

#ifndef TYPE_H
#define TYPE_H

#include "externallib/externallib.h"

#include <string>
#include <algorithm>

#include "source2sdk/client/CCitadelPlayerController.hpp"
#include "source2sdk/client/C_CitadelPlayerPawn.hpp"

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
    ex::var<source2sdk::client::CCitadelPlayerController> ex_controller;
    ex::var<source2sdk::client::C_CitadelPlayerPawn> ex_pawn;
};

inline std::string c_heroname_to_realname(const char* hero_name)
{
    std::string hn{ hero_name };
    hn.erase(0, 5);
    std::ranges::transform(hn, hn.begin(), toupper);
    return hn;
}

#endif //TYPE_H
