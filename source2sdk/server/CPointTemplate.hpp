#pragma once
#include "source2sdk/client/PointTemplateClientOnlyEntityBehavior_t.hpp"
#include "source2sdk/client/PointTemplateOwnerSpawnGroupType_t.hpp"
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/server/CLogicalEntity.hpp"
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
    // Size: 0x578
    // Has VTable
    #pragma pack(push, 1)
    class CPointTemplate : public server::CLogicalEntity
    {
    public:
        CUtlSymbolLarge m_iszWorldName; // 0x4e8        
        CUtlSymbolLarge m_iszSource2EntityLumpName; // 0x4f0        
        CUtlSymbolLarge m_iszEntityFilterName; // 0x4f8        
        float m_flTimeoutInterval; // 0x500        
        bool m_bAsynchronouslySpawnEntities; // 0x504        
        [[maybe_unused]] std::uint8_t pad_0x505[0x3]; // 0x505
        entity2::CEntityIOOutput m_pOutputOnSpawned; // 0x508        
        client::PointTemplateClientOnlyEntityBehavior_t m_clientOnlyEntityBehavior; // 0x530        
        client::PointTemplateOwnerSpawnGroupType_t m_ownerSpawnGroupType; // 0x534        
        // m_createdSpawnGroupHandles has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVector<uint32_t> m_createdSpawnGroupHandles;
        char m_createdSpawnGroupHandles[0x18]; // 0x538        
        // m_SpawnedEntityHandles has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVector<CEntityHandle> m_SpawnedEntityHandles;
        char m_SpawnedEntityHandles[0x18]; // 0x550        
        HSCRIPT m_ScriptSpawnCallback; // 0x568        
        HSCRIPT m_ScriptCallbackScope; // 0x570        
        
        // Datamap fields:
        // void InputForceSpawn; // 0x0
        // void InputDeleteCreatedSpawnGroups; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CPointTemplate because it is not a standard-layout class
    static_assert(sizeof(CPointTemplate) == 0x578);
};
