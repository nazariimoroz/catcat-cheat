#ifndef SETTINGS_H
#define SETTINGS_H

class settings_t
{
public:
    settings_t() = delete;

    inline static bool aim_without_scope = false;
    inline static bool aim_in_scope = true;
    inline static float aim_sense = 50.f;
    inline static float aim_max_distance = 2000.f;

    // if distance to enemy1 >= aim_lost_distance, and there are other enemy in range
    // cheat will pick closest enemy
    inline static float aim_lost_distance = 2000.f;
};

#endif //SETTINGS_H
