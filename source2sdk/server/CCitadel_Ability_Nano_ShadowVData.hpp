#pragma once
#include "source2sdk/server/CCitadelModifier.hpp"
#include "source2sdk/server/CitadelAbilityVData.hpp"
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
    // Size: 0x1598
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Ability_Nano_ShadowVData : public server::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyGroupName "Modifiers"
        // m_ShadowModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_ShadowModifier;
        char m_ShadowModifier[0x10]; // 0x1560        
        // m_PurgeModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_PurgeModifier;
        char m_PurgeModifier[0x10]; // 0x1570        
        // m_EnemyAura has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_EnemyAura;
        char m_EnemyAura[0x10]; // 0x1580        
        // metadata: MPropertyGroupName "GamePlay"
        float m_flAuraRadius; // 0x1590        
        [[maybe_unused]] std::uint8_t pad_0x1594[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Nano_ShadowVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Nano_ShadowVData) == 0x1598);
};
