#pragma once
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
#include "source2sdk/server/CCitadelModifier.hpp"
#include "source2sdk/server/CitadelItemVData.hpp"
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
    // Size: 0x17a0
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CItem_ActiveReload_VData : public server::CitadelItemVData
    {
    public:
        // metadata: MPropertyStartGroup "Modifiers"
        // m_SuccessModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_SuccessModifier;
        char m_SuccessModifier[0x10]; // 0x15a8        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_strSuccessSound; // 0x15b8        
        CSoundEventName m_strFailureSound; // 0x15c8        
        // metadata: MPropertyStartGroup "Visuals"
        // m_SuccessParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_SuccessParticle;
        char m_SuccessParticle[0xe0]; // 0x15d8        
        // m_FailureParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_FailureParticle;
        char m_FailureParticle[0xe0]; // 0x16b8        
        // metadata: MPropertyStartGroup "Gameplay"
        float m_flGraceTime; // 0x1798        
        [[maybe_unused]] std::uint8_t pad_0x179c[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CItem_ActiveReload_VData because it is not a standard-layout class
    static_assert(sizeof(CItem_ActiveReload_VData) == 0x17a0);
};
