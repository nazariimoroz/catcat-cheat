#include "signature.h"

#include "externallib.h"

std::vector<uint8_t> ex::signature_t::parse_pattern() const
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

uintptr_t ex::signature_t::find(const std::vector<uint8_t>& memory, HANDLE processHandle, uintptr_t moduleBase) const
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

            EX_LOG("+ 0x {:x}", (result - moduleBase));

            offsets.push_back(result - moduleBase);
        }
    }

    return offsets.at(0);
}


