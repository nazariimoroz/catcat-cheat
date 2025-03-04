#pragma once
#include "source2sdk/client/C_CitadelBaseAbility.hpp"
#include "source2sdk/client/EViscousChargedGunState.hpp"
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
    // Size: 0xef0
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "EViscousChargedGunState m_ChargeState"
    // static metadata: MNetworkVarNames "float m_nClipConsumed"
    // static metadata: MNetworkVarNames "bool m_bIsCharging"
    // static metadata: MNetworkVarNames "bool m_bIsToggled"
    #pragma pack(push, 1)
    class CCitadel_Ability_ViscousWeapon_Alt : public client::C_CitadelBaseAbility
    {
    public:
        // metadata: MNetworkEnable
        client::EViscousChargedGunState m_ChargeState; // 0xca0        
        // metadata: MNetworkEnable
        float m_nClipConsumed; // 0xca4        
        // metadata: MNetworkEnable
        bool m_bIsCharging; // 0xca8        
        // metadata: MNetworkEnable
        bool m_bIsToggled; // 0xca9        
        [[maybe_unused]] std::uint8_t pad_0xcaa[0x2]; // 0xcaa
        client::ParticleIndex_t m_fxChargingParticle; // 0xcac        
        [[maybe_unused]] std::uint8_t pad_0xcb0[0x8]; // 0xcb0
        entity2::GameTime_t m_flLastBulletConsumedTime; // 0xcb8        
        [[maybe_unused]] std::uint8_t pad_0xcbc[0x234];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_ViscousWeapon_Alt because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_ViscousWeapon_Alt) == 0xef0);
};
