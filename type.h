

#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <Windows.h>
#include <vector>

#include "source2sdk/client/CCitadelPlayerController.hpp"
#include "source2sdk/client/C_CitadelPlayerPawn.hpp"

struct str_t
{
    char _str[256];
    char* str() { return _str; }
};

std::vector<uint8_t> readMemoryBytes(HANDLE processHandle, uintptr_t address, size_t size);

template <class T>
class Type
{
public:
    std::vector<std::uint8_t> data;

    uintptr_t _address;
    HANDLE _ph;

    // DEBUG ONLY
    volatile T* ptr;

public:
    Type() {}

    Type(HANDLE ph, std::uintptr_t address)
    {
        _address = address;
        _ph = ph;

        reread();
    }

    Type(HANDLE ph, T* address)
    {
        _address = reinterpret_cast<uintptr_t>(address);
        _ph = ph;

        reread();
    }

    T* get()
    {
        ptr = reinterpret_cast<T*>(data.data());
        return reinterpret_cast<T*>(data.data());
    }

    std::reference_wrapper<T> operator*()
    {
        ptr = reinterpret_cast<T*>(data.data());
        return std::ref(*reinterpret_cast<T*>(data.data()));
    }

    T* operator->()
    {
        return get();
    }

    void reread()
    {
        data = readMemoryBytes(_ph, _address, sizeof(T));
    }
};

struct ViewRender
{
    char _ggg[0x28];
    float fov; // 0x28
};

struct EntitySystem
{
    char _ggg[0x10];
    uintptr_t first_entry_ptr;
};

struct player_t
{
    Type<source2sdk::client::CCitadelPlayerController> ex_controller;
    Type<source2sdk::client::C_CitadelPlayerPawn> ex_pawn;
};

#endif //TYPE_H
