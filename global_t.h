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

    inline static std::unique_ptr<ex::var<SenseSetting>> ex_sense_settings = nullptr;
    inline static std::vector<player_t> players_list;
    inline static player_t* local_player = nullptr;
    inline static std::vector<orb_t> orbs_list;

    inline static void restart_temp()
    {
        ex_sense_settings.reset();
        players_list.clear();
        local_player = nullptr;
        orbs_list.clear();
    }
};

#endif //GLOBAL_T_H
