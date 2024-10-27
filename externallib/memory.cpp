#include "memory.h"
#include "externallib.h"

bool ex::read_memory_into_array(char* buffer, HANDLE processHandle, uintptr_t address, size_t size)
{
    if(!ReadProcessMemory(processHandle, reinterpret_cast<LPCVOID>(address), buffer, size, nullptr))
    {
        auto errorMessageID = ::GetLastError();

        LPSTR messageBuffer = nullptr;

        size_t size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

        EX_LOG("read_memory_into_array(ERROR): {}", messageBuffer);

        LocalFree(messageBuffer);

        return false;
    }

    return true;
}
