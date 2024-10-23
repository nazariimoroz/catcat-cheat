

#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <Windows.h>
#include <vector>

#include "source2sdk/client/C_CitadelPlayerPawn.hpp"

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

    T* operator->()
    {
        return get();
    }

    void reread()
    {
        data = readMemoryBytes(_ph, _address, sizeof(T));
    }
};

struct Pawn
{
    std::string name;
    Type<source2sdk::client::C_CitadelPlayerPawn> pawn;
    Type<source2sdk::client::CBodyComponent> body_comp;
    Type<source2sdk::client::CGameSceneNode> scene_node;
};

#endif //TYPE_H
