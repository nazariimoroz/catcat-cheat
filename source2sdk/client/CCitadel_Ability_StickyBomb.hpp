#pragma once
#include "source2sdk/client/C_CitadelBaseAbility.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: client
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::client
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xdc8
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "float m_flBombBonus"
    #pragma pack(push, 1)
    class CCitadel_Ability_StickyBomb : public client::C_CitadelBaseAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xca0[0x8]; // 0xca0
        // metadata: MNetworkEnable
        float m_flBombBonus; // 0xca8        
        [[maybe_unused]] std::uint8_t pad_0xcac[0x11c];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_StickyBomb because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_StickyBomb) == 0xdc8);
};
