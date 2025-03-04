#pragma once
#include "source2sdk/client/CCitadelBaseYamatoAbility.hpp"
#include "source2sdk/client/ParticleIndex_t.hpp"
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
    // Size: 0xf60
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "int m_nPowerLevel"
    #pragma pack(push, 1)
    class CCitadel_Ability_PowerSlash : public client::CCitadelBaseYamatoAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xca8[0xc]; // 0xca8
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        int32_t m_nPowerLevel; // 0xcb4        
        client::ParticleIndex_t m_nCastParticle; // 0xcb8        
        [[maybe_unused]] std::uint8_t pad_0xcbc[0x2a4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_PowerSlash because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_PowerSlash) == 0xf60);
};
