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
    // Size: 0x19b8
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Ability_Bull_LeapVData : public server::CitadelAbilityVData
    {
    public:
        CPiecewiseCurve m_CrashSpeedScaleCurve; // 0x1560        
        // metadata: MPropertyStartGroup "Modifiers"
        // m_BoostModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_BoostModifier;
        char m_BoostModifier[0x10]; // 0x15a0        
        // m_CrashModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_CrashModifier;
        char m_CrashModifier[0x10]; // 0x15b0        
        // m_ImmunityModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_ImmunityModifier;
        char m_ImmunityModifier[0x10]; // 0x15c0        
        // m_LandingBonusesModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_LandingBonusesModifier;
        char m_LandingBonusesModifier[0x10]; // 0x15d0        
        // metadata: MPropertyStartGroup "Visuals"
        // m_TakeOffParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_TakeOffParticle;
        char m_TakeOffParticle[0xe0]; // 0x15e0        
        // m_ImpactParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_ImpactParticle;
        char m_ImpactParticle[0xe0]; // 0x16c0        
        // m_AoEPreviewParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_AoEPreviewParticle;
        char m_AoEPreviewParticle[0xe0]; // 0x17a0        
        // m_nHoverParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_nHoverParticle;
        char m_nHoverParticle[0xe0]; // 0x1880        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_strCrashingSound; // 0x1960        
        CSoundEventName m_strImpactSound; // 0x1970        
        // metadata: MPropertyStartGroup "GamePlay"
        float m_flStartupTime; // 0x1980        
        float m_flForwardBoostSpeed; // 0x1984        
        float m_flUpBoostSpeed; // 0x1988        
        float m_flBoostTurnRate; // 0x198c        
        float m_flHoverTime; // 0x1990        
        float m_flMinAimAngle; // 0x1994        
        float m_flBoostGain; // 0x1998        
        float m_flBoostTime; // 0x199c        
        float m_flLandingTime; // 0x19a0        
        float m_flCrashSpeed; // 0x19a4        
        float m_flHoverInputSpeedMax; // 0x19a8        
        float m_flHoverInputAcceleration; // 0x19ac        
        float m_flHoverSpeedDecay; // 0x19b0        
        [[maybe_unused]] std::uint8_t pad_0x19b4[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Bull_LeapVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Bull_LeapVData) == 0x19b8);
};
