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

#include ".env.h"
#include "dl_memory.h"
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

float get_coef(float fov, float global_sense, float aim_sense_mul, bool in_aim)
{
    //float fov = 87.61151886f / 45.f; // 43.02112579f // 87.61151886f
    fov /= 45.f; // 43.02112579f // 87.61151886f

    // 1: 0.0225849f * 0.94887767f = 0.0214303
    // 2: 0.0225849f * 1.4555f     = 0.03287232
    // 3: 0.0225849f * 1.964f      = 0.04435674

    float final_coef = 0.0226762f
        * global_sense
        * fov;

    if (in_aim)
    {
        final_coef *= ((0.5085f * aim_sense_mul) + 0.44037767f);
    }

    return final_coef;
}

bool in_game(uintptr_t local_player_ptr_address)
{
    ex::var<uintptr_t> local_player_address = local_player_ptr_address;
    return *local_player_address.get();
}

void aim(std::vector<player_t>& players_list,
    ex::var<SenseSetting>& sense_settings,
    player_t& local_player,
    std::vector<orb_t>& orbs_list)
{
    bool aim_worked = false;

    if ( settings_t::aim &&
        ((settings_t::aim_scope == scope_t::scope_only && local_player.view_render->fov < 80.f) ||
        (settings_t::aim_scope == scope_t::noscope_only && local_player.view_render->fov > 80.f) ||
        settings_t::aim_scope == scope_t::scope_and_noscope))
    {
        if (!(GetAsyncKeyState(settings_t::aim_key) & 0x8000))
        {
            goto SKIP_AIM;
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

            xyz_t cursor_pos = {(float)gui::WIDTH / 2.f, (float)gui::HEIGHT / 2.f};
            auto len = glm::length(static_cast<glm::vec3>(xyw.xy0() - cursor_pos));

            if(settings_t::aim_circle && len > settings_t::aim_circle_radius_in_px)
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

            float coef = get_coef(local_player.view_render->fov,
                                  sense_settings->global_sense,
                                  sense_settings->aim_sense_coef,
                                  local_player.view_render->fov < 80.f);

            float fov_per_pixel = local_player.view_render->fov / (float)gui::WIDTH / 2;
            result.x = (result.x * fov_per_pixel) / coef;
            result.y = (result.y * fov_per_pixel) / coef;

            move_mouse(result.x, result.y);

            aim_worked = true;
        }
    }

    SKIP_AIM:

    if(aim_worked)
        goto AIM_EXIT;

    if ( settings_t::orb_aim &&
        ((settings_t::orb_aim_scope == scope_t::scope_only && local_player.view_render->fov < 80.f) ||
        (settings_t::orb_aim_scope == scope_t::noscope_only && local_player.view_render->fov > 80.f) ||
        settings_t::orb_aim_scope == scope_t::scope_and_noscope))
    {
        if (!(GetAsyncKeyState(settings_t::orb_aim_key) & 0x8000))
        {
            goto AIM_EXIT;
        }

        orb_t* closest_orb = nullptr;
        xyz_t closest_orb_screen = {0, 0, INFINITY};
        float min_len = INFINITY;
        for (auto& i : orbs_list)
        {
            if(i.visible)
                continue;

            auto [xyw, is_ok] = gui::world_to_screen(i.position, local_player.matrix.get());
            if (!is_ok)
                continue;

            if (xyw.z >= settings_t::orb_aim_max_distance)
                continue;

            xyz_t cursor_pos = {(float)gui::WIDTH / 2.f, (float)gui::HEIGHT / 2.f};
            auto new_len = glm::length(static_cast<glm::vec3>(xyw.xy0() - cursor_pos));

            if(settings_t::aim_circle && new_len > settings_t::aim_circle_radius_in_px)
                continue;

            if (min_len > new_len)
            {
                min_len = new_len;
                closest_orb_screen = xyw;
                closest_orb = &i;
            }
        }

        if (closest_orb)
        {
            xyz_t cursor_pos = {(float)gui::WIDTH / 2.f, (float)gui::HEIGHT / 2.f};

            auto result = closest_orb_screen - cursor_pos;
            result.z = 0;

            float coef = get_coef(local_player.view_render->fov,
                                  sense_settings->global_sense,
                                  sense_settings->aim_sense_coef,
                                  local_player.view_render->fov < 80.f);

            float fov_per_pixel = local_player.view_render->fov / (float)gui::WIDTH / 2;
            result.x = (result.x * fov_per_pixel) / coef;
            result.y = (result.y * fov_per_pixel) / coef;

            move_mouse(result.x, result.y);

            aim_worked = true;
        }
    }

    AIM_EXIT: {}
    if (!aim_worked)
    {
        global_t::aim_locked_on_hero.clear();
    }
}

int ex_main()
{
    // aim coef testing
#if 0
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

#pragma region SigsInition GettingDdHandle GettingsOffsetsFromSigs
    ex::signature_t localPlayerSig("48 8B 0D ? ? ? ? 48 85 C9 74 65 83 FF FF", 3, 7);
    ex::signature_t viewMatrixSig("48 8D ? ? ? ? ? 48 C1 E0 06 48 03 C1 C3", 3, 7);
    ex::signature_t entityListSig("48 8B 0D ? ? ? ? 8B C5 48 C1 E8", 3, 7);
    ex::signature_t viewRenderSig("48 89 05 ? ? ? ? 48 8B C8 48 85 C0", 3, 7);
    ex::signature_t senseSettingsSig(
        "48 8B 05 ? ? ? ? 48 8B 40 08 80 38 00 74 ? F3 ? ? 06 F3 ? ? 05 ? ? ? ? F3 ? ? 06 F3 ? ? 05 ? ? ? ? 48 8B B4 24 ? ? ? ?",
        3, 7);

    while(true)
    {
        std::string process_name = "project8.exe";
        ex::set_global_handle(getProcessHandle(process_name));
        if (!ex::get_global_handle())
        {
            if(MessageBoxA(nullptr, "Open Deadlock first", nullptr,
                MB_RETRYCANCEL | MB_SYSTEMMODAL) == 4)
                continue;
            break;
        }

        MODULEINFO module_info = getModuleInfo(ex::get_global_handle(), "client.dll");

        if (!module_info.lpBaseOfDll)
        {
            if(MessageBoxA(nullptr, "Open Deadlock first", nullptr,
                MB_RETRYCANCEL | MB_SYSTEMMODAL) == 4)
                continue;
            break;
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

        std::cout << "Sense settings: " << std::endl;
        uintptr_t senseSettingsOffsetPtrStat = senseSettingsSig.find(memory, ex::get_global_handle(),
                                                                     reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

        ex::var<uintptr_t> senseSettingsPtr =
            reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + senseSettingsOffsetPtrStat;

#pragma endregion SigsInition GettingDdHandle GettingsOffsetsFromSIgs

        if(!gui::FindDowWindow("Deadlock"))
        {
            if(MessageBoxA(nullptr, "Open Deadlock first", nullptr,
                MB_RETRYCANCEL | MB_SYSTEMMODAL) == 4)
                continue;
            break;
        }
        if(!global_t::gui_is_inited)
        {
            gui::CreateHWindow(WINDOW_NAME_A);
            if (!gui::CreateDevice())
            {
                return 1;
            }
            gui::CreateImGui();
        }

#pragma region Settings Globals
        bool is_dd_window_closed = false;
        global_t::gui_is_inited = true;
        settings_t::load_settings();
#pragma endregion Settings Globals

        while (gui::isRunning)
        {
            if(!IsWindow(gui::dow_hwnd))
            {
                is_dd_window_closed = true;
                break;
            }
            if(UNIX_TIME_EXPIRY < std::chrono::duration_cast<std::chrono::seconds>(
                       std::chrono::system_clock::now().time_since_epoch()).count())
            {
                MessageBoxA(nullptr, "The license have expired", nullptr, MB_OK | MB_SYSTEMMODAL);
                return 0;
            }

            if (GetAsyncKeyState(settings_t::exit_key) & 0x8000)
                break;

            global_t::in_game = in_game(localPlayerOffset + reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));
            if (!global_t::in_game)
            {
                global_t::list_size = 0;
                break;
            }

            ex::var<SenseSetting> sense_settings{
                *senseSettingsPtr.get(), std::make_tuple(
                    &SenseSetting::global_sense,
                    &SenseSetting::aim_sense_coef
                )
            };

            ex::var<uintptr_t> ex_entity_list_ptr
                = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + entityListOffset;

            auto [players_list, local_player_i,
                orbs_list] = dl_memory_t::get_all_entities(*ex_entity_list_ptr);
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

            if(!gui::show_menu && gui::is_dd_activated() && global_t::in_game)
            {
                aim(players_list, sense_settings, local_player, orbs_list);
            }
        }

        if(is_dd_window_closed)
        {
            // TODO REMAKE
            break;
            CloseHandle(ex::get_global_handle());
            ex::set_global_handle(nullptr);

            // Just reusing old UI
            //gui::DestroyImGui();
            //gui::DestroyDevice();
            //gui::DestroyHWindow();
            gui::BeginRender();
            gui::EndRender();

            continue;
        }

        break;
    }

    // destroy gui
    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    CloseHandle(ex::get_global_handle());
    return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    return ex_main();
}
