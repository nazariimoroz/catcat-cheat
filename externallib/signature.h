#ifndef SIGNATURE_H
#define SIGNATURE_H

#include "memory.h"

#include <sstream>
#include <string>
#include <vector>

namespace ex
{
    struct signature_t
    {
        std::string pattern;
        uint32_t offset;
        uint32_t extra;

        signature_t(const std::string& pat, uint32_t off, uint32_t ext)
            : pattern(pat), offset(off), extra(ext)
        {}

        std::vector<uint8_t> parse_pattern() const;

        uintptr_t find(const std::vector<uint8_t>& memory, HANDLE processHandle, uintptr_t moduleBase) const;
    };

}

#endif //SIGNATURE_H
