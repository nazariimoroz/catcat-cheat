

#ifndef TYPE_H
#define TYPE_H
#include <string>
#include <Windows.h>
#include <vector>
#include <map>
#include <algorithm>

#include "source2sdk/client/CCitadelPlayerController.hpp"
#include "source2sdk/client/C_CitadelPlayerPawn.hpp"

struct str_t
{
    char _str[256];
    char* str() { return _str; }
};

std::vector<uint8_t> readMemoryBytes(HANDLE processHandle, uintptr_t address, size_t size);

template<class T, std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
  readMemoryBytes2(std::tuple<Tp...>& t, std::vector<uint8_t>& buffer, HANDLE processHandle, uintptr_t address)
{

}

template<class T, std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
  readMemoryBytes2(std::tuple<Tp...>& t, std::vector<uint8_t>& buffer, HANDLE processHandle, uintptr_t address)
{
    T* nullptr_var = nullptr;
    const auto offset = (char*)&(nullptr_var->*std::get<I>(t)) - (char*)(nullptr_var);
    const auto size = sizeof(nullptr_var->*std::get<I>(t));

    ReadProcessMemory(processHandle, reinterpret_cast<LPCVOID>(address + offset), buffer.data() + offset, size, nullptr);

    readMemoryBytes2<T, I + 1, Tp...>(t, buffer, processHandle, address);
}

template<class T>
class Type
{
public:
    std::vector<std::uint8_t> data;

    uintptr_t _address = 0;
    HANDLE _ph = nullptr;

    // DEBUG ONLY
    volatile T* ptr = nullptr;

public:
    Type() = default;

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

    template<class... Args>
    Type(HANDLE ph, std::uintptr_t address, std::tuple<Args...> to_read)
    {
        _address = address;
        _ph = ph;

        reread(to_read);
    }

    template<class... Args>
    Type(HANDLE ph, T* address, std::tuple<Args...> to_read)
    {
        _address = reinterpret_cast<uintptr_t>(address);
        _ph = ph;

        reread(to_read);
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

    template<class TupleType>
    void reread(TupleType to_read)
    {
        data.resize(sizeof(T));
        readMemoryBytes2<T>(to_read, data, _ph, _address);
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

#define BYTES_TO_PTR(DATA) *(uintptr_t*)DATA

struct player_t
{
    Type<source2sdk::client::CCitadelPlayerController> ex_controller;
    Type<source2sdk::client::C_CitadelPlayerPawn> ex_pawn;
};

inline std::string c_heroname_to_realname(const char* hero_name)
{
    std::string hn{ hero_name };
    hn.erase(0, 5);
    std::ranges::transform(hn, hn.begin(), toupper);
    return hn;
}

#endif //TYPE_H
