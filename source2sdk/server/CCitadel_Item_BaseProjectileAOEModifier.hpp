#pragma once
#include "source2sdk/server/CCitadel_Item.hpp"
#include "source2sdk/server/CitadelAbilityProjectileCreateInfo_t.hpp"
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
    // Size: 0xbc0
    // Has VTable
    #pragma pack(push, 1)
    class CCitadel_Item_BaseProjectileAOEModifier : public server::CCitadel_Item
    {
    public:
        Vector m_vLaunchPosition; // 0xb20        
        QAngle m_qLaunchAngle; // 0xb2c        
        [[maybe_unused]] std::uint8_t pad_0xb38[0x38]; // 0xb38
        server::CitadelAbilityProjectileCreateInfo_t m_projInfo; // 0xb70        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Item_BaseProjectileAOEModifier because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Item_BaseProjectileAOEModifier) == 0xbc0);
};
