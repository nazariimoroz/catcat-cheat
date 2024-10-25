#define UNICODE
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <vector>
#include <string>
#include <Psapi.h>
#include <sstream>
#include <iomanip>

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

struct Signature
{
    std::string pattern;
    uint32_t offset;
    uint32_t extra;

    Signature(const std::string& pat, uint32_t off, uint32_t ext)
        : pattern(pat), offset(off), extra(ext)
    {
    }

    std::vector<uint8_t> parse_pattern() const
    {
        std::vector<uint8_t> bytes;
        std::istringstream patternStream(pattern);
        std::string byteStr;

        while (patternStream >> byteStr)
        {
            if (byteStr == "?" || byteStr == "??")
            {
                bytes.push_back(0);
            }
            else
            {
                bytes.push_back(static_cast<uint8_t>(strtol(byteStr.c_str(), nullptr, 16)));
            }
        }
        return bytes;
    }

    uintptr_t find(const std::vector<uint8_t>& memory, HANDLE processHandle, uintptr_t moduleBase) const
    {
        std::vector<uint8_t> pattern = parse_pattern();
        std::vector<uintptr_t> offsets;
        for (size_t i = 1000000; i < memory.size(); ++i)
        {
            bool patternMatch = true;
            for (size_t j = 0; j < pattern.size(); ++j)
            {
                if (pattern[j] != 0 && memory[i + j] != pattern[j])
                {
                    patternMatch = false;
                    break;
                }
            }
            if (patternMatch)
            {
                uintptr_t patternAddress = moduleBase + i;
                int32_t of;
                ReadProcessMemory(processHandle, reinterpret_cast<LPCVOID>(patternAddress + offset), &of, sizeof(of),
                                  nullptr);
                uintptr_t result = patternAddress + of + extra;
                std::cout << "+ 0x" << std::hex << (result - moduleBase) << std::endl;

                offsets.push_back(result - moduleBase);
            }
        }

        return offsets.at(0);
    }
};

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

std::vector<uint8_t> readMemoryBytes(HANDLE processHandle, uintptr_t address, size_t size)
{
    std::vector<uint8_t> buffer(size);
    ReadProcessMemory(processHandle, reinterpret_cast<LPCVOID>(address), buffer.data(), size, nullptr);
    return buffer;
}

struct EntSys
{
    char a[16];
    uintptr_t ptr;
};

struct Smth
{
    char a[16];
    uintptr_t ptr;
};


int main()
{
#pragma region CHEAT
    std::cerr << "By 5komar (Catrine)\n" << std::endl;

    Signature localPlayerSig("48 8B 0D ? ? ? ? 48 85 C9 74 65 83 FF FF", 3, 7);
    Signature viewMatrixSig("48 8D ? ? ? ? ? 48 C1 E0 06 48 03 C1 C3", 3, 7);
    Signature entityListSig("48 8B 0D ? ? ? ? 8B C5 48 C1 E8", 3, 7);
    Signature CCameraManagerSig("48 8D 3D ? ? ? ? 8B D9", 3, 7);
    Signature gameEntitySystemSig("48 8B 1D ? ? ? ? 48 89 1D", 3, 7);
    Signature viewRenderSig("48 89 05 ? ? ? ? 48 8B C8 48 85 C0", 3, 7);

    std::string processName = "project8.exe";
    HANDLE processHandle = getProcessHandle(processName);
    if (!processHandle)
    {
        std::cerr << "Game process not found!" << std::endl;
        return 1;
    }

    MODULEINFO moduleInfo = getModuleInfo(processHandle, "client.dll");

    if (!moduleInfo.lpBaseOfDll)
    {
        std::cerr << "client.dll not found!" << std::endl;
        return 1;
    }

    std::vector<uint8_t> memory = readMemoryBytes(processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll),
                                                  moduleInfo.SizeOfImage);

#if 1
    std::cout << "dwLocalPlayerController:" << std::endl;
    uintptr_t localPlayerOffset = localPlayerSig.find(memory, processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll));
    std::cout << "dwViewMatrix:" << std::endl;
    uintptr_t viewMatrixOffset = viewMatrixSig.find(memory, processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll));
    std::cout << "dwViewRender:" << std::endl;
    uintptr_t viewRenderOffset = viewRenderSig.find(memory, processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll));

    std::cout << "dwEntityList:" << std::endl;
    entityListSig.find(memory, processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll));
    std::cout << "dwGameEntitySystem:" << std::endl;
    gameEntitySystemSig.find(memory, processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll));
    std::cout << "CCameraManager:" << std::endl;
    CCameraManagerSig.find(memory, processHandle, reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll));
#endif

#if 0
    {
        Type<uintptr_t> pc_ptr {processHandle
            ,reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + 0x2180378};

        Type<source2sdk::client::CCitadelPlayerController> pc {processHandle
            , *pc_ptr.get() };

        auto entity_ptr = pc->m_pEntity;
        do
        {
            Type entity {processHandle , entity_ptr};
            using str_t = char[256];
            Type<str_t> str = {processHandle, *(uintptr_t*)entity->m_designerName};
            Type<str_t> str_2 = {processHandle, *(uintptr_t*)entity->m_name};
            std::cout << entity_ptr << ": " << (char*)str.get()
                << "   " << (char*)str_2.get() << std::endl;

            entity_ptr = entity->m_pNext;
        } while (entity_ptr);

        std::cout << "============\n";

        entity_ptr = pc->m_pEntity;
        do
        {
            Type entity {processHandle , entity_ptr};
            using str_t = char[256];
            Type<str_t> str = {processHandle, *(uintptr_t*)entity->m_designerName};
            std::cout << entity_ptr << ": " << (char*)str.get() << std::endl;

            entity_ptr = entity->m_pPrev;
        } while (entity_ptr);
    }

    {
        Type<Urho3D::Matrix3x4> matrix {processHandle
                , reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + 0x2192230};
        while(false)
        {
            const auto a = matrix.get();
            auto x = a->m03_;
            auto y = a->m13_;
            auto z = a->m23_;

            std::cout << std::setw(6) <<  x << " "
                << std::setw(6) << y << " "
                << std::setw(6) << z << " "
                << std::setw(6) << a->yaw() << " "
                << std::setw(6) << a->pitch() << std::endl;

            matrix.reread();
        }
    }
#endif
#pragma endregion CHEAT

    gui::CreateHWindow("Deadlock", "Cheat Menu");
    if(!gui::CreateDevice())
    {
        return 1;
    }
    gui::CreateImGui();

    while (gui::isRunning)
    {
        std::vector<Pawn> pawns;
        {
            Type<uintptr_t> pc_ptr {processHandle
                ,reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + localPlayerOffset};

            Type<source2sdk::client::CCitadelPlayerController> pc {processHandle
                , *pc_ptr.get() };

            auto entity_ptr = pc->m_pEntity;
            do
            {
                Type entity {processHandle , entity_ptr};
                using str_t = char[256];
                Type<str_t> str = {processHandle, *(uintptr_t*)entity->m_designerName};
                Type<str_t> str_2 = {processHandle, *(uintptr_t*)entity->m_name};
                if( strcmp((char*)str.get(), "player") == 0)
                {
                    Pawn pwn;
                    pwn.name = (char*)str_2.get();
                    pwn.pawn = {processHandle , *(uintptr_t*)entity->pad_0x00};
                    pwn.body_comp = {processHandle , pwn.pawn->m_CBodyComponent};
                    pwn.scene_node = {processHandle , pwn.body_comp->m_pSceneNode};
                    pawns.push_back(pwn);
                }

                entity_ptr = entity->m_pNext;
            } while (entity_ptr);

            std::cout << "============\n";

            entity_ptr = pc->m_pEntity;
            do
            {
                Type entity {processHandle , entity_ptr};
                using str_t = char[256];
                Type<str_t> str = {processHandle, *(uintptr_t*)entity->m_designerName};
                Type<str_t> str_2 = {processHandle, *(uintptr_t*)entity->m_name};
                if( strcmp((char*)str.get(), "player") == 0)
                {
                    Pawn pwn;
                    pwn.name = (char*)str_2.get();
                    pwn.pawn = {processHandle , *(uintptr_t*)entity->pad_0x00};
                    pwn.body_comp = {processHandle , pwn.pawn->m_CBodyComponent};
                    pwn.scene_node = {processHandle , pwn.body_comp->m_pSceneNode};
                    pawns.push_back(pwn);
                }

                entity_ptr = entity->m_pPrev;
            } while (entity_ptr);
        }

        Type<Urho3D::Matrix3x4> matrix {processHandle
                , reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + viewMatrixOffset};

        Type<ViewRender> $view_render;
        {
            Type<uintptr_t> $vr_ptr {processHandle
                ,reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll) + viewRenderOffset};

            $view_render = decltype($view_render){processHandle, *$vr_ptr.get()};
        }

        gui::BeginRender();
        gui::Render({std::move(matrix), std::move(pawns), std::move($view_render)});
        gui::EndRender();

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    // destroy gui
    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    //CloseHandle(processHandle);
    return 0;
}


