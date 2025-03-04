#pragma once
#include "source2sdk/client/CitadelCameraOperationsSequence_t.hpp"
#include "source2sdk/resourcesystem/InfoForResourceTypeCModel.hpp"
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
    // Size: 0x1a68
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CAbilityGuidedArrowVData : public server::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyStartGroup "Camera"
        client::CitadelCameraOperationsSequence_t m_cameraCancelledTransitionBacktoArcher; // 0x1560        
        client::CitadelCameraOperationsSequence_t m_cameraExplodedTransitionBackToArcher; // 0x15e8        
        float m_flCameraHoldAtExplosion; // 0x1670        
        float m_flFadeToBlackTime; // 0x1674        
        // metadata: MPropertyStartGroup "Visuals"
        // m_SpectatingProjectileParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_SpectatingProjectileParticle;
        char m_SpectatingProjectileParticle[0xe0]; // 0x1678        
        // m_ExplosionParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_ExplosionParticle;
        char m_ExplosionParticle[0xe0]; // 0x1758        
        // m_GuidedArrowChannelParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_GuidedArrowChannelParticle;
        char m_GuidedArrowChannelParticle[0xe0]; // 0x1838        
        // m_ProjectileModel has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeCModel>> m_ProjectileModel;
        char m_ProjectileModel[0xe0]; // 0x1918        
        float m_ArrowOffsetX; // 0x19f8        
        float m_ArrowCameraDistance; // 0x19fc        
        float m_ArrowCameraHeightOffset; // 0x1a00        
        float m_ArrowInitialPitch; // 0x1a04        
        // metadata: MPropertyStartGroup "Modifiers"
        // m_GuidingModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_GuidingModifier;
        char m_GuidingModifier[0x10]; // 0x1a08        
        // m_DebuffModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_DebuffModifier;
        char m_DebuffModifier[0x10]; // 0x1a18        
        // m_KillCheckModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_KillCheckModifier;
        char m_KillCheckModifier[0x10]; // 0x1a28        
        // metadata: MPropertyGroupName "Sounds"
        CSoundEventName m_strExplodeSound; // 0x1a38        
        // metadata: MPropertyStartGroup "Gameplay"
        float m_flTrackAmount; // 0x1a48        
        float m_flSpeedAccel; // 0x1a4c        
        float m_flSpeedDeccel; // 0x1a50        
        float m_flBaseProjectileSpeed; // 0x1a54        
        float m_flMaxProjectileSpeed; // 0x1a58        
        float m_flArrowModelTurnSpringStrength; // 0x1a5c        
        float m_flKillCheckWindow; // 0x1a60        
        float m_flWorldCollideGraceWindow; // 0x1a64        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CAbilityGuidedArrowVData because it is not a standard-layout class
    static_assert(sizeof(CAbilityGuidedArrowVData) == 0x1a68);
};
