#pragma once
#include "source2sdk/client/C_CitadelBaseAbility.hpp"
#include "source2sdk/client/ParticleIndex_t.hpp"
#include "source2sdk/entity2/GameTime_t.hpp"
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
    // Size: 0xee0
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "bool m_bLeaping"
    // static metadata: MNetworkVarNames "GameTime_t m_flLeapStartTime"
    #pragma pack(push, 1)
    class CCitadel_Ability_HornetLeap : public client::C_CitadelBaseAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xca0[0x2]; // 0xca0
        // metadata: MNetworkEnable
        bool m_bLeaping; // 0xca2        
        [[maybe_unused]] std::uint8_t pad_0xca3[0x1]; // 0xca3
        // metadata: MNetworkEnable
        entity2::GameTime_t m_flLeapStartTime; // 0xca4        
        client::ParticleIndex_t m_nFXIndex; // 0xca8        
        [[maybe_unused]] std::uint8_t pad_0xcac[0x234];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_HornetLeap because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_HornetLeap) == 0xee0);
};
