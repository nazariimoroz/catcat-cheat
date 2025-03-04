#pragma once
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
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
    // Size: 0x1a38
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Ability_Viscous_TelepunchVData : public server::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyStartGroup "Visuals"
        // m_PortalParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_PortalParticle;
        char m_PortalParticle[0xe0]; // 0x1560        
        // m_CastParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_CastParticle;
        char m_CastParticle[0xe0]; // 0x1640        
        // m_PunchParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_PunchParticle;
        char m_PunchParticle[0xe0]; // 0x1720        
        // m_WallPunchParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_WallPunchParticle;
        char m_WallPunchParticle[0xe0]; // 0x1800        
        // m_CeilingPunchParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_CeilingPunchParticle;
        char m_CeilingPunchParticle[0xe0]; // 0x18e0        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_EnemyPortalSound; // 0x19c0        
        CSoundEventName m_SelfPortalSound; // 0x19d0        
        CSoundEventName m_WindupSound; // 0x19e0        
        CSoundEventName m_PunchSound; // 0x19f0        
        // metadata: MPropertyStartGroup "Modifiers"
        // m_PunchRollSlowModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_PunchRollSlowModifier;
        char m_PunchRollSlowModifier[0x10]; // 0x1a00        
        // m_ImpactModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_ImpactModifier;
        char m_ImpactModifier[0x10]; // 0x1a10        
        // metadata: MPropertyStartGroup "+Telepunch Parameters"
        float m_flEnemyPortalTelegraphTime; // 0x1a20        
        float m_flSelfPortalTelegraphTime; // 0x1a24        
        float m_flWindupTime; // 0x1a28        
        float m_flAttackTime; // 0x1a2c        
        float m_flGroundTraceOnPlayerHitDistance; // 0x1a30        
        float m_flPlayerCheckSphereRadius; // 0x1a34        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Viscous_TelepunchVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Viscous_TelepunchVData) == 0x1a38);
};
