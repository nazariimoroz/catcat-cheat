#ifndef TYPE_H
#define TYPE_H

#include "externallib/externallib.h"

#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <glm/vec3.hpp>

#include "matrix3x4.h"
#include "source2sdk/client/CCitadelPlayerController.hpp"
#include "source2sdk/client/C_CitadelPlayerPawn.hpp"
#include "source2sdk/client/CGameSceneNode.hpp"
#include "source2sdk/client/CItemXP.hpp"

inline std::string get_key_name(int key) {
    static std::map<int, std::string> keyNames = {
        { VK_LBUTTON, "MOUSE1" },
        { VK_RBUTTON, "MOUSE2" },
        { VK_MBUTTON, "MOUSE3" },
        { VK_XBUTTON1, "MOUSE4" },
        { VK_XBUTTON2, "MOUSE5" },
        { VK_BACK, "Backspace" },
        { VK_TAB, "Tab" },
        { VK_RETURN, "Enter" },
        { VK_SHIFT, "Shift" },
        { VK_CONTROL, "Ctrl" },
        { VK_MENU, "Alt" },
        { VK_PAUSE, "Pause" },
        { VK_CAPITAL, "Caps Lock" },
        { VK_ESCAPE, "Escape" },
        { VK_SPACE, "Space" },
        { VK_PRIOR, "Page Up" },
        { VK_NEXT, "Page Down" },
        { VK_END, "End" },
        { VK_HOME, "Home" },
        { VK_LEFT, "Left Arrow" },
        { VK_UP, "Up Arrow" },
        { VK_RIGHT, "Right Arrow" },
        { VK_DOWN, "Down Arrow" },
        { VK_INSERT, "Insert" },
        { VK_DELETE, "Delete" },
        { 'A', "A" },
        { 'B', "B" },
        { 'C', "C" },
        { 'D', "D" },
        { 'E', "E" },
        { 'F', "F" },
        { 'G', "G" },
        { 'H', "H" },
        { 'I', "I" },
        { 'J', "J" },
        { 'K', "K" },
        { 'L', "L" },
        { 'M', "M" },
        { 'N', "N" },
        { 'O', "O" },
        { 'P', "P" },
        { 'Q', "Q" },
        { 'R', "R" },
        { 'S', "S" },
        { 'T', "T" },
        { 'U', "U" },
        { 'V', "V" },
        { 'W', "W" },
        { 'X', "X" },
        { 'Y', "Y" },
        { 'Z', "Z" },
        { VK_F1, "F1" },
        { VK_F2, "F2" },
        { VK_F3, "F3" },
        { VK_F4, "F4" },
        { VK_F5, "F5" },
        { VK_F6, "F6" },
        { VK_F7, "F7" },
        { VK_F8, "F8" },
        { VK_F9, "F9" },
        { VK_F10, "F10" },
        { VK_F11, "F11" },
        { VK_F12, "F12" },
        { VK_NUMPAD0, "Numpad 0" },
        { VK_NUMPAD1, "Numpad 1" },
        { VK_NUMPAD2, "Numpad 2" },
        { VK_NUMPAD3, "Numpad 3" },
        { VK_NUMPAD4, "Numpad 4" },
        { VK_NUMPAD5, "Numpad 5" },
        { VK_NUMPAD6, "Numpad 6" },
        { VK_NUMPAD7, "Numpad 7" },
        { VK_NUMPAD8, "Numpad 8" },
        { VK_NUMPAD9, "Numpad 9" },
        { VK_MULTIPLY, "Numpad *" },
        { VK_ADD, "Numpad +" },
        { VK_SUBTRACT, "Numpad -" },
        { VK_DECIMAL, "Numpad ." },
        { VK_DIVIDE, "Numpad /" },
        { VK_OEM_1, ";" },
        { VK_OEM_PLUS, "=" },
        { VK_OEM_COMMA, "," },
        { VK_OEM_MINUS, "-" },
        { VK_OEM_PERIOD, "." },
        { VK_OEM_2, "/" },
        { VK_OEM_3, "`" },
        { VK_OEM_4, "[" },
        { VK_OEM_5, "\\" },
        { VK_OEM_6, "]" },
        { VK_OEM_7, "'" }
    };
    if (keyNames.contains(key)) {
        return keyNames[key];
    }
    return "Unknown";
}

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

struct SenseSetting
{
    char _ggg[0x220];
    float global_sense;
    char _gggg[0x25C];
    float aim_sense_coef;
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

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

    // local only
    ex::var<ViewRender> view_render;

    // local only
    ex::var<Urho3D::Matrix3x4> matrix;

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

struct orb_t
{
    ex::var<source2sdk::client::CItemXP> ex_orb;

    xyz_t position;
    bool visible;
};

#endif //TYPE_H
