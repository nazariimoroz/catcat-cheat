#ifndef EXTERNALLIB_H
#define EXTERNALLIB_H

#include <format>
#include <syncstream>
#include <iostream>

#include "memory.h"
#include "signature.h"

#define EX_GLUE2(x, y) x##y
#define EX_GLUE(x, y) EX_GLUE2(x, y)
#define EX_UNIQUE_NAME EX_GLUE(_ex_unique_name_temporary, __COUNTER__)

#define EX_DEFER2(UNIQUE, FUNC) \
    std::shared_ptr<void> UNIQUE(nullptr, FUNC )
#define EX_DEFER(FUNC) EX_DEFER2(EX_UNIQUE_NAME, FUNC)

#ifndef _NDEBUG
#define EX_LOG(FMT, ...) std::osyncstream(std::cerr) << std::format(FMT ,##__VA_ARGS__) << std::endl
#define EX_ERROR(FMT, ...) std::osyncstream(std::cerr) << std::format(FMT ,##__VA_ARGS__) << std::endl
#else
#define EX_DLOG(FMT, ...) do {} while (0)
#define EX_ERROR(FMT, ...) do {} while (0)
#endif

#define EX_BYTES_TO_PTR(DATA) *(uintptr_t*)DATA

namespace ex
{
    struct str_t
    {
        char _str[256];
        char* str() { return _str; }
    };
}


#endif //EXTERNALLIB_H
