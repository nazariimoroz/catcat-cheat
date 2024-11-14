#ifndef GLOBAL_T_H
#define GLOBAL_T_H
#include <string>

class global_t
{
public:
    inline static bool gui_is_inited = false;

    inline static bool in_game = false;

    inline static std::string aim_locked_on_hero = "";

    inline static uint32_t list_size = 0;
};

#endif //GLOBAL_T_H
