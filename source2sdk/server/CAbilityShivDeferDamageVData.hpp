#pragma once
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
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
    // Size: 0x1648
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CAbilityShivDeferDamageVData : public server::CitadelAbilityVData
    {
    public:
        // metadata: MPropertyStartGroup "Visuals"
        // m_ActiveCastParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_ActiveCastParticle;
        char m_ActiveCastParticle[0xe0]; // 0x1560        
        // metadata: MPropertyStartGroup "+Defer Properties"
        float m_flDeferredDamageApplicationInterval; // 0x1640        
        [[maybe_unused]] std::uint8_t pad_0x1644[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CAbilityShivDeferDamageVData because it is not a standard-layout class
    static_assert(sizeof(CAbilityShivDeferDamageVData) == 0x1648);
};
