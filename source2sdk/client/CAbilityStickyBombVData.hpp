#pragma once
#include "source2sdk/client/CCitadelModifier.hpp"
#include "source2sdk/client/CitadelAbilityVData.hpp"
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
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
    // Size: 0x1668
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CAbilityStickyBombVData : public client::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyGroupName "Modifiers"
        // m_BombAttachedModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CCitadelModifier> m_BombAttachedModifier;
        char m_BombAttachedModifier[0x10]; // 0x1560        
        // m_KillCheckModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CCitadelModifier> m_KillCheckModifier;
        char m_KillCheckModifier[0x10]; // 0x1570        
        // metadata: MPropertyStartGroup "Visuals"
        // m_CastBombParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_CastBombParticle;
        char m_CastBombParticle[0xe0]; // 0x1580        
        // metadata: MPropertyStartGroup "Gameplay"
        float m_flAllyTargetRangeMult; // 0x1660        
        [[maybe_unused]] std::uint8_t pad_0x1664[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CAbilityStickyBombVData because it is not a standard-layout class
    static_assert(sizeof(CAbilityStickyBombVData) == 0x1668);
};
