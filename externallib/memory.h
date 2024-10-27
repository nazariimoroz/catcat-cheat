#ifndef MEMORY_H
#define MEMORY_H

/* TODO
#ifdef _WINDOWS_
#error "Windows.h should be firtly included in externallib/memory.h"
#endif
*/

#define UNICODE
#include <Windows.h>
#include <tuple>

namespace ex
{
    bool read_memory_into_array(char* buffer, HANDLE processHandle, uintptr_t address, size_t size);

    template<class T, std::size_t I = 0, typename... Tp>
    inline typename std::enable_if<I == sizeof...(Tp), void>::type
      read_memory_into_array_tl(std::tuple<Tp...>& t, char* buffer, HANDLE processHandle, uintptr_t address)
    {}

    template<class T, std::size_t I = 0, typename... Tp>
    inline typename std::enable_if<I < sizeof...(Tp), void>::type
      read_memory_into_array_tl(std::tuple<Tp...>& t, char* buffer, HANDLE processHandle, uintptr_t address)
    {
        T* nullptr_var = nullptr;
        const auto offset = (char*)&(nullptr_var->*std::get<I>(t)) - (char*)(nullptr_var);
        const auto size = sizeof(nullptr_var->*std::get<I>(t));

        read_memory_into_array(buffer + offset, processHandle, address + offset, size);

        read_memory_into_array_tl<T, I + 1, Tp...>(t, buffer, processHandle, address);
    }

    inline HANDLE _global_handle;
    inline void set_global_handle(HANDLE gh)
    {
        _global_handle = gh;
    }
    inline HANDLE get_global_handle()
    {
        return _global_handle;
    }

    template<class T>
    class var
    {
    public:
        var() = default;

        var(HANDLE ph, std::uintptr_t address)
        {
            _address = address;
            _handle = ph;

            reread();
        }

        var(HANDLE ph, T* address)
        {
            _address = reinterpret_cast<uintptr_t>(address);
            _handle = ph;

            reread();
        }

        template<class... Args>
        var(HANDLE ph, std::uintptr_t address, std::tuple<Args...> to_read)
        {
            _address = address;
            _handle = ph;

            reread(to_read);
        }

        template<class... Args>
        var(HANDLE ph, T* address, std::tuple<Args...> to_read)
        {
            _address = reinterpret_cast<uintptr_t>(address);
            _handle = ph;

            reread(to_read);
        }

        var(std::uintptr_t address)
        {
            _address = address;
            _handle = get_global_handle();

            reread();
        }

        var(T* address)
        {
            _address = reinterpret_cast<uintptr_t>(address);
            _handle = get_global_handle();

            reread();
        }

        template<class... Args>
        var(std::uintptr_t address, std::tuple<Args...> to_read)
        {
            _address = address;
            _handle = get_global_handle();

            reread(to_read);
        }

        template<class... Args>
        var(T* address, std::tuple<Args...> to_read)
        {
            _address = reinterpret_cast<uintptr_t>(address);
            _handle = get_global_handle();

            reread(to_read);
        }

        T* get()
        {
            _ptr = reinterpret_cast<T*>(_buffer);
            return reinterpret_cast<T*>(_buffer);
        }

        std::reference_wrapper<T> operator*()
        {
            _ptr = reinterpret_cast<T*>(_buffer);
            return std::ref(*reinterpret_cast<T*>(_buffer));
        }

        T* operator->()
        {
            return get();
        }

        void reread()
        {
            read_memory_into_array(_buffer, _handle, _address, sizeof(T));
        }

        template<class TupleType>
        void reread(TupleType to_read)
        {
            read_memory_into_array_tl<T>(to_read, _buffer, _handle, _address);
        }

        uintptr_t get_address() const { return _address; }
        HANDLE get_handle() const { return _handle; }
        char* get_buffer() const { return (char*)_buffer; }

    private:
        char _buffer[sizeof(T)] = { 0 };

        uintptr_t _address = 0;
        HANDLE _handle = nullptr;

        // DEBUG ONLY
        volatile T* _ptr = nullptr;
    };
}

#endif //MEMORY_H
