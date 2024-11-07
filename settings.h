#ifndef SETTINGS_H
#define SETTINGS_H

enum class scope_t
{
    scope_and_noscope,
    scope_only,
    noscope_only
};

class settings_t
{
public:
    settings_t() = delete;

    #pragma region Aim
    inline static bool aim = true;
    inline static scope_t aim_scope = scope_t::scope_only;

    inline static float aim_max_distance = 2000.f;

    // if distance to enemy1 >= aim_lost_distance, and there are other enemy in range
    // cheat will pick closest enemy
    inline static float aim_lost_distance = 2000.f;
    #pragma endregion Aim



};

#endif //SETTINGS_H
