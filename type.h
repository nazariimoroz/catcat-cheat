#ifndef TYPE_H
#define TYPE_H

#include "externallib/externallib.h"

#include <string>
#include <algorithm>
#include <unordered_map>

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

struct xyz_t
{
    float x;
    float y;
    float z;
};

inline const std::unordered_map<std::string, int> realname_to_head_bone_map = {
    {"TARGETDUMMY", 12},
    {"HAZE", 7},
    {"INFERNO", 30},
    {"ATLAS", 7},       // ABRAMS
    {"LASH", 12},
    {"BEBOP", 6},
    {"HORNET", 7},      // VINDICTA
    {"VISCOUS", 7},
    {"DYNAMO", 13},
    {"KELVIN", 12},

    {"SYNTH", 13},      // POCKET
    {"GHOST", 11},      // LADY GEIST
    {"SHIV", 13},       // LEZO

    {"FORGE", 7},       // MCGINNIS
    {"WRAITH", 7},
    {"KRILL", 10},      // MO & KRILL TODO FIND NEW

    {"MIRAGE", 8},
    {"CHRONO", 8},      // PARADOX
    {"TENGU", 13},      // IVY PLUSH

    {"WARDEN", 11},
    {"ORION", 17},      // GREY TALON
    {"GIGAWATT", 14},   // SEVEN
    {"YAMATO", 35},
};

struct bone_t
{
    xyz_t position;
    char pad[0x20 - sizeof(position)];
};
static_assert(sizeof(bone_t) == 0x20);


struct player_t
{
    ex::var<source2sdk::client::CCitadelPlayerController> ex_controller;
    ex::var<source2sdk::client::C_CitadelPlayerPawn> ex_pawn;

    std::string hero_name;

    xyz_t world_pos;

    // should be world pos + ~90.f
    xyz_t head_pos;
    int head_bone_index;
};

inline std::string c_heroname_to_realname(const char* hero_name)
{
    std::string hn{ hero_name };
    hn.erase(0, 5);
    std::ranges::transform(hn, hn.begin(), toupper);
    return hn;
}

#endif //TYPE_H
