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
    // Size: 0x1930
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CAbilityTokamakHotShotVData : public client::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyGroupName "Modifiers"
        // m_LaserModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CCitadelModifier> m_LaserModifier;
        char m_LaserModifier[0x10]; // 0x1560        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_strLaserStartSound; // 0x1570        
        CSoundEventName m_strLaserEndSound; // 0x1580        
        CSoundEventName m_strLaserLoopSound; // 0x1590        
        CSoundEventName m_strLaserHitSound; // 0x15a0        
        // metadata: MPropertyStartGroup "Visuals"
        // m_ChargeParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_ChargeParticle;
        char m_ChargeParticle[0xe0]; // 0x15b0        
        // m_BeamParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_BeamParticle;
        char m_BeamParticle[0xe0]; // 0x1690        
        // m_HitParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_HitParticle;
        char m_HitParticle[0xe0]; // 0x1770        
        // m_GroundParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_GroundParticle;
        char m_GroundParticle[0xe0]; // 0x1850        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CAbilityTokamakHotShotVData because it is not a standard-layout class
    static_assert(sizeof(CAbilityTokamakHotShotVData) == 0x1930);
};
