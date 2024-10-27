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

#include <gui/gui.h>

#include "matrix3x4.h"
#include "source2sdk/client/CCitadelPlayerController.hpp"
#include "source2sdk/client/CBodyComponent.hpp"
#include "source2sdk/client/CGameSceneNode.hpp"
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

std::vector<player_t> get_all_players(uintptr_t entity_list_sys_ptr)
{
    std::vector<player_t> players;
    ex::var<uintptr_t> ex_entity_list_ptr = entity_list_sys_ptr + 0x10 ;

    for(int i = 0; i < 20; ++i)
    {
        player_t player {};
        ex::var<uintptr_t> ex_controller_ptr
            = (*ex_entity_list_ptr) + 0x78 * (i & 0x1FF);

        if(*ex_controller_ptr == 0)
            continue;

        ex::var<source2sdk::client::CCitadelPlayerController> ex_controller { *ex_controller_ptr,
            std::make_tuple(
                &source2sdk::client::CCitadelPlayerController::m_iTeamNum,
                &source2sdk::client::CCitadelPlayerController::m_pEntity,
                &source2sdk::client::CCitadelPlayerController::m_hPawn,
                &source2sdk::client::CCitadelPlayerController::m_bIsLocalPlayerController
                )};

        if(!ex_controller->m_pEntity)
            continue;

        ex::var ex_entity = ex_controller->m_pEntity;
        const auto designer_name_ptr = *(uintptr_t*)ex_entity->m_designerName;
        if(!designer_name_ptr)
            continue;

        ex::var<ex::str_t> designer_name = designer_name_ptr;
        if( strcmp(designer_name->str(), "citadel_player_controller") != 0)
            continue;

        player.ex_controller = std::move(ex_controller);

        int32_t pawn_index = *(int32_t*)player.ex_controller->m_hPawn;
        uintptr_t pawns_entity_list_sys_ptr
            = entity_list_sys_ptr + (0x8 * ((pawn_index & 0x7FFF) >> 0x9) + 0x10);
        ex::var<uintptr_t> ex_pawns_entity_list_ptr = pawns_entity_list_sys_ptr;

        if(*ex_pawns_entity_list_ptr == 0)
            continue;

        uintptr_t pawn_ptr_ptr = (*ex_pawns_entity_list_ptr) + 0x78 * (pawn_index & 0x1FF);
        if(pawn_ptr_ptr == 0)
            continue;

        ex::var<uintptr_t> ex_pawn_ptr = pawn_ptr_ptr;
        if(*ex_pawn_ptr == 0)
            continue;

        player.ex_pawn = ex::var<source2sdk::client::C_CitadelPlayerPawn>{ *ex_pawn_ptr,
            std::make_tuple(
                &source2sdk::client::C_CitadelPlayerPawn::m_CBodyComponent,
                &source2sdk::client::C_CitadelPlayerPawn::m_pEntity,
                &source2sdk::client::C_CitadelPlayerPawn::m_iHealth,
                &source2sdk::client::C_CitadelPlayerPawn::m_iMaxHealth
                )};

        players.push_back(player);
    }

    return players;
}

int main()
{
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
    uintptr_t localPlayerOffset = localPlayerSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwViewMatrix:" << std::endl;
    uintptr_t viewMatrixOffset = viewMatrixSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwViewRender:" << std::endl;
    uintptr_t viewRenderOffset = viewRenderSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwEntityList:" << std::endl;
    uintptr_t entityListOffset = entityListSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

    std::cout << "dwGameEntitySystem:" << std::endl;
    gameEntitySystemSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));
    std::cout << "CCameraManager:" << std::endl;
    CCameraManagerSig.find(memory, ex::get_global_handle(), reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll));

#pragma endregion CHEAT

    gui::CreateHWindow("Deadlock", "Cheat Menu");
    if(!gui::CreateDevice())
    {
        return 1;
    }
    gui::CreateImGui();

    while (gui::isRunning)
    {
        ex::var<Urho3D::Matrix3x4> matrix
            = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + viewMatrixOffset;

        ex::var<ViewRender> view_render;
        {
            ex::var<uintptr_t> vr_ptr
                = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + viewRenderOffset;

            view_render = decltype(view_render){ *vr_ptr.get() };
        }

        ex::var<uintptr_t> ex_entity_list_ptr
            = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll) + entityListOffset;
        auto result = get_all_players(*ex_entity_list_ptr);

        gui::BeginRender();
        gui::Render({std::move(matrix), std::move(result), std::move(view_render)});
        gui::EndRender();
    }

    // destroy gui
    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    //CloseHandle(processHandle);
    return 0;
}


