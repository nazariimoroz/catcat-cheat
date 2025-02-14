#pragma once
#include "source2sdk/resourcesystem/InfoForResourceTypeIParticleSystemDefinition.hpp"
#include "source2sdk/server/CParticleSystem.hpp"
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
    // Size: 0xd58
    // Has VTable
    // 
    // static metadata: MNetworkExcludeByName "m_iEffectIndex"
    // static metadata: MNetworkIncludeByName "m_iTeamNum"
    // static metadata: MNetworkVarNames "HParticleSystemDefinitionStrong m_iFriendlyEffectIndex"
    // static metadata: MNetworkVarNames "HParticleSystemDefinitionStrong m_iEnemyEffectIndex"
    #pragma pack(push, 1)
    class CTeamRelativeParticleSystem : public server::CParticleSystem
    {
    public:
        CUtlSymbolLarge m_iszFriendlyEffectName; // 0xd38        
        CUtlSymbolLarge m_iszEnemyEffectName; // 0xd40        
        // metadata: MNetworkEnable
        // m_iFriendlyEffectIndex has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CStrongHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition> m_iFriendlyEffectIndex;
        char m_iFriendlyEffectIndex[0x8]; // 0xd48        
        // metadata: MNetworkEnable
        // m_iEnemyEffectIndex has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CStrongHandle<resourcesystem::InfoForResourceTypeIParticleSystemDefinition> m_iEnemyEffectIndex;
        char m_iEnemyEffectIndex[0x8]; // 0xd50        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CTeamRelativeParticleSystem because it is not a standard-layout class
    static_assert(sizeof(CTeamRelativeParticleSystem) == 0xd58);
};
