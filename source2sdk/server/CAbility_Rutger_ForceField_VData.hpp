#pragma once
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
#include "source2sdk/server/CBaseModifier.hpp"
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
    // Size: 0x16a0
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CAbility_Rutger_ForceField_VData : public server::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyStartGroup "Modifiers"
        // m_AuraModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_AuraModifier;
        char m_AuraModifier[0x10]; // 0x1560        
        // m_VictimPushModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_VictimPushModifier;
        char m_VictimPushModifier[0x10]; // 0x1570        
        // m_SlowModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CBaseModifier> m_SlowModifier;
        char m_SlowModifier[0x10]; // 0x1580        
        // metadata: MPropertyGroupName "Sounds"
        CSoundEventName m_strDomeCreated; // 0x1590        
        CSoundEventName m_strChargeUpSound; // 0x15a0        
        CSoundEventName m_strPushAndDamage; // 0x15b0        
        // metadata: MPropertyStartGroup "Visuals"
        // m_ChronoSphereChargeParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_ChronoSphereChargeParticle;
        char m_ChronoSphereChargeParticle[0xe0]; // 0x15c0        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CAbility_Rutger_ForceField_VData because it is not a standard-layout class
    static_assert(sizeof(CAbility_Rutger_ForceField_VData) == 0x16a0);
};
