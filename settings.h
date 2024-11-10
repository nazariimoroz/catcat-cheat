#ifndef SETTINGS_H
#define SETTINGS_H
#include <string>
#include <string_view>

#include "dl_memory.h"

enum class scope_t : int32_t
{
    scope_and_noscope,
    scope_only,
    noscope_only
};

inline const char* scope_t_str[]{
    "scope_and_noscope",
    "scope_only",
    "noscope_only"
};

class settings_t
{
public:
    settings_t() = delete;

    inline static std::wstring config_name = L"config.ini";

    static void load_settings();
    static void save_settings();

    static float get_value(std::wstring_view settings_name, std::wstring_view key_name, float value);
    static void save_value(std::wstring_view settings_name, std::wstring_view key_name, float value);

#pragma region Aim
    inline static bool aim = true;
    inline static scope_t aim_scope = scope_t::scope_only;
    inline static float aim_max_distance = 2000.f;
    // if distance to enemy1 >= aim_lost_distance, and there are other enemy in range
    // cheat will pick closest enemy
    inline static float aim_lost_distance = 2000.f;
    inline static int aim_key = VK_LBUTTON;

    inline static bool orb_aim = true;
    inline static scope_t orb_aim_scope = scope_t::noscope_only;
    inline static float orb_aim_max_distance = 2000.f;
    inline static int orb_aim_key = VK_LBUTTON;

    inline static bool aim_circle = true;
    inline static float aim_circle_radius_in_px = 100.f;
#pragma endregion Aim

#pragma region Esp
    inline static bool esp = true;
    inline static float esp_max_distance = 10000.f;

    inline static bool esp_with_health = true;
#pragma endregion Esp

#pragma region Other
    inline static int exit_key = VK_NUMPAD0;
#pragma endregion Other
};

#endif //SETTINGS_H
