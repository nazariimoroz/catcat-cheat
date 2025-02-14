#pragma once
#include "source2sdk/client/ParticleIndex_t.hpp"
#include "source2sdk/server/CCitadelBaseYamatoAbility.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xdc0
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "int m_nPowerLevel"
    #pragma pack(push, 1)
    class CCitadel_Ability_PowerSlash : public server::CCitadelBaseYamatoAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xb08[0xc]; // 0xb08
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        int32_t m_nPowerLevel; // 0xb14        
        client::ParticleIndex_t m_nCastParticle; // 0xb18        
        [[maybe_unused]] std::uint8_t pad_0xb1c[0x2a4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_PowerSlash because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_PowerSlash) == 0xdc0);
};
