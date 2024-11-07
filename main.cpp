#define UNICODE
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <vector>
#include <string>
#include <Psapi.h>
#include <sstream>
#include <iomanip>
#include <functional>

#include <thread>
#include <chrono>
#include <imgui.h>
#include <glm/detail/func_geometric.inl>

#include <gui/gui.h>

#include "global_t.h"
#include "matrix3x4.h"
#include "settings.h"
#include "source2sdk/client/CCitadelPlayerController.hpp"
#include "source2sdk/client/CBodyComponent.hpp"
#include "source2sdk/client/CGameSceneNode.hpp"
#include "source2sdk/client/CSkeletonInstance.hpp"
#include "source2sdk/entity2/CEntityIdentity.hpp"

#include "source2sdk/worldrenderer/WorldNode_t.hpp"
#include "source2sdk/worldrenderer/World_t.hpp"

// Helper function to convert TCHAR to std::string or std::wstring
#ifdef UNICODE
std::wstring toString(const TCHAR* tcharArray)
{
    return std::wstring(tcharArray);
}
#else
std::string toString(const TCHAR* tcharArray)
{
    return std::string(tcharArray);
}
#endif

std::string wstringToString(const std::wstring& wstr)
{
    std::string str(wstr.begin(), wstr.end());
    return str;
}

HANDLE getProcessHandle(const std::string& processName)
{
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (Process32First(snapshot, &processEntry))
    {
        do
        {
            std::string exeFileName = wstringToString(processEntry.szExeFile);
            if (processName == exeFileName)
            {
                CloseHandle(snapshot);
                return OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, processEntry.th32ProcessID);
            }
        }
        while (Process32Next(snapshot, &processEntry));
    }
    CloseHandle(snapshot);
    return nullptr;
}


MODULEINFO getModuleInfo(HANDLE processHandle, const std::string& moduleName)
{
    HMODULE hMods[1024];
    DWORD cbNeeded;
    MODULEINFO modInfo = {0};

    if (EnumProcessModules(processHandle, hMods, sizeof(hMods), &cbNeeded))
    {
        for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
        {
            char szModName[MAX_PATH];
            if (GetModuleBaseNameA(processHandle, hMods[i], szModName, sizeof(szModName) / sizeof(char)))
            {
                if (moduleName == szModName)
                {
                    GetModuleInformation(processHandle, hMods[i], &modInfo, sizeof(modInfo));
                    break;
                }
            }
        }
    }
    return modInfo;
}

/**
 * player_list, index of local_player
 */
std::tuple<std::vector<player_t>, size_t> get_all_players(uintptr_t entity_list_sys_ptr)
{
    std::vector<player_t> players;
    ex::var<uintptr_t> ex_entity_list_ptr = entity_list_sys_ptr + 0x10;

    size_t index_of_local_player = 0;

    for (int i = 0; i < 20; ++i)
    {
        player_t player{};
        ex::var<uintptr_t> ex_controller_ptr
            = (*ex_entity_list_ptr) + 0x78 * (i & 0x1FF);

        if (*ex_controller_ptr == 0)
            continue;

        ex::var<source2sdk::client::CCitadelPlayerController> ex_controller{
            *ex_controller_ptr,
            std::make_tuple(
                &source2sdk::client::CCitadelPlayerController::m_iTeamNum,
                &source2sdk::client::CCitadelPlayerController::m_pEntity,
                &source2sdk::client::CCitadelPlayerController::m_hPawn,
                &source2sdk::client::CCitadelPlayerController::m_bIsLocalPlayerController
            )
        };

        if (!ex_controller->m_pEntity)
            continue;

        ex::var ex_entity = ex_controller->m_pEntity;
        const auto designer_name_ptr = *(uintptr_t*)ex_entity->m_designerName;
        if (!designer_name_ptr)
            continue;

        ex::var<ex::str_t> designer_name = designer_name_ptr;
        if (strcmp(designer_name->str(), "citadel_player_controller") != 0)
            continue;

        player.ex_controller = std::move(ex_controller);

        int32_t pawn_index = *(int32_t*)player.ex_controller->m_hPawn;
        uintptr_t pawns_entity_list_sys_ptr
            = entity_list_sys_ptr + (0x8 * ((pawn_index & 0x7FFF) >> 0x9) + 0x10);
        ex::var<uintptr_t> ex_pawns_entity_list_ptr = pawns_entity_list_sys_ptr;

        if (*ex_pawns_entity_list_ptr == 0)
            continue;

        uintptr_t pawn_ptr_ptr = (*ex_pawns_entity_list_ptr) + 0x78 * (pawn_index & 0x1FF);
        if (pawn_ptr_ptr == 0)
            continue;

        ex::var<uintptr_t> ex_pawn_ptr = pawn_ptr_ptr;
        if (*ex_pawn_ptr == 0)
            continue;

        player.ex_pawn = ex::var<source2sdk::client::C_CitadelPlayerPawn>{
            *ex_pawn_ptr,
            std::make_tuple(
                &source2sdk::client::C_CitadelPlayerPawn::m_CBodyComponent,
                &source2sdk::client::C_CitadelPlayerPawn::m_pEntity,
                &source2sdk::client::C_CitadelPlayerPawn::m_iHealth,
                &source2sdk::client::C_CitadelPlayerPawn::m_iMaxHealth,
                &source2sdk::client::C_CitadelPlayerPawn::m_flMouseSensitivity,
                &source2sdk::client::C_CitadelPlayerPawn::m_pGameSceneNode,
                &source2sdk::client::C_CitadelPlayerPawn::m_lifeState
            )
        };

        // getting hero name
        {
            if (player.ex_pawn->m_pEntity == nullptr)
                continue;
            ex::var pawn_entity{
                player.ex_pawn->m_pEntity, std::make_tuple(
                    &source2sdk::entity2::CEntityIdentity::m_name)
            };

            ex::var<ex::str_t> pawn_name = EX_BYTES_TO_PTR(pawn_entity->m_name);
            player.hero_name = c_heroname_to_realname(pawn_name->str()).c_str();
        }

        // getting current position
        {
            if (player.ex_pawn->m_CBodyComponent == nullptr)
                continue;
            ex::var bc{
                player.ex_pawn->m_CBodyComponent, std::make_tuple(
                    &source2sdk::client::CBodyComponent::m_pSceneNode
                )
            };

            if (bc->m_pSceneNode == nullptr)
                continue;
            ex::var scene_node{
                bc->m_pSceneNode, std::make_tuple(
                    &source2sdk::client::CGameSceneNode::m_nodeToWorld
                )
            };

            player.world_pos.x = *((float*)scene_node->m_nodeToWorld);
            player.world_pos.y = *((float*)scene_node->m_nodeToWorld + 1);
            player.world_pos.z = *((float*)scene_node->m_nodeToWorld + 2);
        }

        // getting head bone
        do
        {
            const auto bi_iter = realname_to_head_bone_map.find(player.hero_name);
            if (bi_iter == realname_to_head_bone_map.end())
            {
                player.head_pos = player.world_pos;
                player.head_pos.z += 92.f;
                break;
            }
            const auto bi_ex_index = bi_iter->second;

            ex::var<source2sdk::client::CSkeletonInstance> ex_gsn{
                (uintptr_t)player.ex_pawn->m_pGameSceneNode,
                std::make_tuple(
                    &source2sdk::client::CSkeletonInstance::m_modelState
                )
            };

            uintptr_t bone_array_address = ex_gsn->m_modelState.m_bone_array;

            uintptr_t bone_address = bone_array_address
                + sizeof(bone_t) * bi_ex_index;

            ex::var<bone_t> ex_bone{bone_address};
            player.head_pos = ex_bone.get()->position;
        }
        while (false);

        if (player.ex_controller->m_bIsLocalPlayerController)
        {
            index_of_local_player = players.size();
        }

        players.push_back(std::move(player));
    }

    return {players, index_of_local_player};
}

void move_mouse(int d_x, int d_y)
{
    /*
    if (g_settings->invert_vertical)
        d_y *= -1;
        */

    INPUT input = {0};
    input.mi.dwFlags = MOUSEEVENTF_MOVE;

    input.mi.dx = d_x;
    input.mi.dy = d_y;

    input.type = INPUT_MOUSE;
    SendInput(
        1,
        &input,
        sizeof(INPUT)
    );
}

float get_coef(float fov)
{
    float sens_coef = 2.01f;
    float aim_sens_coef = 1.f;
    //float fov = 87.61151886f / 45.f; // 43.02112579f // 87.61151886f
    fov /= 45.f; // 43.02112579f // 87.61151886f

    // 1: 0.0225849f * 0.94887767f = 0.0214303
    // 2: 0.0225849f * 1.4555f     = 0.03287232
    // 3: 0.0225849f * 1.964f      = 0.04435674

    float final_coef = 0.0226762f
        * ((0.5085f * aim_sens_coef) + 0.44037767f)
        * sens_coef
        * fov;

    return final_coef;
}

int main()
{
    // GLOBAL FINAL COEF: 0.0442

    /* NO AIM
    float sens_coef = 2.f;
    float fov = 90.f / 45.f;
    float final_coef = 0.02185f
        * sens_coef
        * fov;
    */ // 0.0442

    /*
    float sens_coef = 1.f;
    float final_coef = 0.020455f
        * sens_coef;
    */

    // final_coef1: 0.0225849f

#if 0
    do
    {
        //std::cin >> final_coef;

        // 87.61151886f
        // 43.02112579f
        float final_coef = get_coef(43.02112579f);

        Sleep(3000);

        timeBeginPeriod(1);

        move_mouse(10, 10);
        Sleep(50);
        move_mouse(-10, -10);
        Sleep(50);

        double nedded_angle_x = 0, nedded_angle_y = 0., current_angle_x = 0., current_angle_y = 0.;
        for(int i = 0; i < 360; ++i)
        {
            nedded_angle_x += 1;
            nedded_angle_y += 0;

            auto can_move_x = static_cast<int>((nedded_angle_x - current_angle_x) / final_coef);
            auto can_move_y = static_cast<int>((nedded_angle_y - current_angle_y) / final_coef);

            current_angle_x += static_cast<double>(can_move_x) * final_coef;
            current_angle_y += static_cast<double>(can_move_y) * final_coef;

            move_mouse(can_move_x, can_move_y);
            Sleep(1);
        }

        timeEndPeriod(1);
    } while(false);

    return 1;
#endif

#pragma region CHEAT
    std::cerr << "By 5komar (Catrine)\n" << std::endl;

    ex::signature_t localPlayerSig("48 8B 0D ? ? ? ? 48 85 C9 74 65 83 FF FF", 3, 7);
    ex::signature_t viewMatrixSig("48 8D ? ? ? ? ? 48 C1 E0 06 48 03 C1 C3", 3, 7);
    ex::signature_t entityListSig("48 8B 0D ? ? ? ? 8B C5 48 C1 E8", 3, 7);
    ex::signature_t CCameraManagerSig("48 8D 3D ? ? ? ? 8B D9", 3, 7);
    ex::signature_t gameEntitySystemSig("48 8B 1D ? ? ? ? 48 89 1D", 3, 7);
    ex::signature_t viewRenderSig("48 89 05 ? ? ? ? 48 8B C8 48 85 C0", 3, 7);

    std::string process_name = "project8.exe";
    ex::set_global_handle(getProcessHandle(process_name));
    if (!ex::get_global_handle())
    {
        EX_LOG("Error: {} not found", process_name);
        return 1;
    }

    MODULEINFO module_info = getModuleInfo(ex::get_global_handle(), "client.dll");

    if (!module_info.lpBaseOfDll)
    {
        EX_LOG("Error: client.dll not found!");
        return 1;
    }

    std::vector<uint8_t> memory;
    memory.resize(module_info.SizeOfImage);
    ex::read_memory_into_array((char*)memory.data(),
                               ex::get_global_handle(),
                               reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll),
                               module_info.SizeOfImage);

    std::cout << "dwLocalPlayerController:" << std::endl;
    uintptr_t localPlayerOffset = localPlayerSig.find(memory, ex::get_global_handle(),
                                                      reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwViewMatrix:" << std::endl;
    uintptr_t viewMatrixOffset = viewMatrixSig.find(memory, ex::get_global_handle(),
                                                    reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwViewRender:" << std::endl;
    uintptr_t viewRenderOffset = viewRenderSig.find(memory, ex::get_global_handle(),
                                                    reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwEntityList:" << std::endl;
    uintptr_t entityListOffset = entityListSig.find(memory, ex::get_global_handle(),
                                                    reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwGameEntitySystem:" << std::endl;
    gameEntitySystemSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));
    std::cout << "CCameraManager:" << std::endl;
    CCameraManagerSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

#pragma endregion CHEAT

    gui::CreateHWindow("Deadlock", "Cheat Menu");
    if (!gui::CreateDevice())
    {
        return 1;
    }
    gui::CreateImGui();

    while (gui::isRunning)
    {
        if (GetAsyncKeyState(VK_BACK) & 0x8000)
            break;

        ex::var<uintptr_t> ex_entity_list_ptr
            = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + entityListOffset;
        auto [players_list, local_player_i] = get_all_players(*ex_entity_list_ptr);
        auto& local_player = players_list[local_player_i];

        // initing local_player
        {
            ex::var<Urho3D::Matrix3x4> matrix
                = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + viewMatrixOffset;

            ex::var<ViewRender> view_render;
            {
                ex::var<uintptr_t> vr_ptr
                    = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + viewRenderOffset;

                view_render = decltype(view_render){*vr_ptr.get()};
            }

            local_player.matrix = std::move(matrix);
            local_player.view_render = std::move(view_render);
        }

        gui::BeginRender();
        gui::Render(players_list, local_player);
        gui::EndRender();


        bool aim_worked = false;
        do
        {
            if (
                (settings_t::aim_scope == scope_t::scope_only && local_player.view_render->fov < 80.f) ||
                (settings_t::aim_scope == scope_t::noscope_only && local_player.view_render->fov > 80.f) ||
                settings_t::aim_scope == scope_t::scope_and_noscope)
            {
                if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000))
                {
                    break;
                }
                player_t* closest_player = nullptr;
                xyz_t closest_player_screen = {0, 0, INFINITY};
                for (auto& i : players_list)
                {
                    if (i.ex_controller->m_iTeamNum == local_player.ex_controller->m_iTeamNum)
                        continue;

                    if (i.ex_pawn->m_lifeState != 0)
                        continue;

                    auto [xyw, is_ok] = gui::world_to_screen(i.head_pos, local_player.matrix.get());
                    if (!is_ok)
                        continue;

                    if (xyw.z >= settings_t::aim_max_distance)
                        continue;

                    if (!global_t::aim_locked_on_hero.empty() && xyw.z <= settings_t::aim_lost_distance)
                    {
                        if (i.hero_name == global_t::aim_locked_on_hero)
                        {
                            closest_player = &i;
                            closest_player_screen = xyw;
                            break;
                        }
                    }

                    if (closest_player_screen.z > xyw.z)
                    {
                        closest_player_screen = xyw;
                        closest_player = &i;
                    }
                }

                if (closest_player)
                {
                    if (global_t::aim_locked_on_hero.empty()
                        || global_t::aim_locked_on_hero != closest_player->hero_name)
                    {
                        global_t::aim_locked_on_hero = closest_player->hero_name;
                    }
                    xyz_t cursor_pos = {(float)gui::WIDTH / 2.f, (float)gui::HEIGHT / 2.f};

                    auto result = closest_player_screen - cursor_pos;
                    result.z = 0;

                    float fov_per_pixel = local_player.view_render->fov / (float)gui::WIDTH / 2;
                    result.x = (result.x * fov_per_pixel) / get_coef(local_player.view_render->fov);
                    result.y = (result.y * fov_per_pixel) / get_coef(local_player.view_render->fov);

                    move_mouse(result.x, result.y);

                    aim_worked = true;
                }
            }
        }
        while (false);
        if (!aim_worked)
        {
            global_t::aim_locked_on_hero.clear();
        }
    }

    // destroy gui
    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    //CloseHandle(processHandle);
    return 0;
}
