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
    // Size: 0x1748
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Ability_Fathom_Breach_VData : public client::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyStartGroup "Visuals"
        // m_ExplosionParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_ExplosionParticle;
        char m_ExplosionParticle[0xe0]; // 0x1560        
        // m_LeapParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_LeapParticle;
        char m_LeapParticle[0xe0]; // 0x1640        
        // metadata: MPropertyLeafSuggestionProviderFn
        CGlobalSymbol m_strInFlightAnimGraphParam; // 0x1720        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_strExplodeSound; // 0x1728        
        // metadata: MPropertyStartGroup "Modifiers"
        // m_InFlightModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CCitadelModifier> m_InFlightModifier;
        char m_InFlightModifier[0x10]; // 0x1738        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Fathom_Breach_VData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Fathom_Breach_VData) == 0x1748);
};
