#pragma once
#include "source2sdk/client/C_CitadelBaseAbility.hpp"
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
    class C_CitadelBaseAbility;
};

namespace source2sdk::client
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xcf0
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "GameTime_t m_flDashCastStartTime"
    // static metadata: MNetworkVarNames "Vector m_vDashCastDir"
    #pragma pack(push, 1)
    class CCitadelBaseDashCastAbility : public client::C_CitadelBaseAbility
    {
    public:
        // m_hAbilityToTrigger has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<client::C_CitadelBaseAbility> m_hAbilityToTrigger;
        char m_hAbilityToTrigger[0x4]; // 0xca0        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        entity2::GameTime_t m_flDashCastStartTime; // 0xca4        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        Vector m_vDashCastDir; // 0xca8        
        [[maybe_unused]] std::uint8_t pad_0xcb4[0x3c];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadelBaseDashCastAbility because it is not a standard-layout class
    static_assert(sizeof(CCitadelBaseDashCastAbility) == 0xcf0);
};
