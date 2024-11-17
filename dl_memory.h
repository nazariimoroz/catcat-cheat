#pragma once
#include <externallib/externallib.h>

#include "type.h"


class dl_memory_t
{
public:
    /**
    * [player_list(skips most teammates), index_of_local_player, orbs]
    */
    static std::tuple<std::vector<player_t>, size_t, std::vector<orb_t>> get_all_entities(uintptr_t entity_list_sys_ptr);

    static std::string get_entity_design_name(uintptr_t entity_address);
};
