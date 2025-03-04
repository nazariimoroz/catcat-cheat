#pragma once
#include "source2sdk/client/CBaseModifier.hpp"
#include "source2sdk/client/CitadelAbilityVData.hpp"
#include "source2sdk/resourcesystem/InfoForResourceTypeCModel.hpp"
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
    // Size: 0x1828
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Ability_MobileResupplyVData : public client::CitadelAbilityVData
    {
    public:
        float m_flResupplyForceScale; // 0x1560        
        float m_flResupplyUp; // 0x1564        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_strKilledSound; // 0x1568        
        // metadata: MPropertyStartGroup "Modifiers"
        // m_AuraModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CBaseModifier> m_AuraModifier;
        char m_AuraModifier[0x10]; // 0x1578        
        // metadata: MPropertyStartGroup "Visuals"
        // m_DispenserModel has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeCModel>> m_DispenserModel;
        char m_DispenserModel[0xe0]; // 0x1588        
        // m_SprayParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_SprayParticle;
        char m_SprayParticle[0xe0]; // 0x1668        
        // m_DestroyedParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_DestroyedParticle;
        char m_DestroyedParticle[0xe0]; // 0x1748        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_MobileResupplyVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_MobileResupplyVData) == 0x1828);
};
