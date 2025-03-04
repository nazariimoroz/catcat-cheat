#pragma once
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
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
    // Size: 0x1788
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_ArmorUpgrade_PersonalRejuvenatorVData : public server::CitadelItemVData
    {
    public:
        // metadata: MPropertyStartGroup "Visuals"
        // m_DeployParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_DeployParticle;
        char m_DeployParticle[0xe0]; // 0x15a8        
        // m_RespawnParticle has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CResourceNameTyped<CWeakHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition>> m_RespawnParticle;
        char m_RespawnParticle[0xe0]; // 0x1688        
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_sDeploySound; // 0x1768        
        CSoundEventName m_sRespawnSound; // 0x1778        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_ArmorUpgrade_PersonalRejuvenatorVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_ArmorUpgrade_PersonalRejuvenatorVData) == 0x1788);
};
