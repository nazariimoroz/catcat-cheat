#pragma once
#include "source2sdk/client/CSkillInt.hpp"
#include "source2sdk/client/ConditionId_t.hpp"
#include "source2sdk/client/EDestructiblePartDamagePassThroughType.hpp"
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
    // Standard-layout class: true
    // Size: 0x50
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CDestructiblePartsSystemData_PartRuntimeData
    {
    public:
        // metadata: MPropertyStartGroup "+Damage"
        // metadata: MPropertyDescription "Total health of this part. When it reaches 0, the part is 'broken' using the breakable prop system."
        client::CSkillInt m_nHealth; // 0x0        
        // metadata: MPropertyDescription "How damage to this part is handled."
        client::EDestructiblePartDamagePassThroughType m_nDamagePassthroughType; // 0x10        
        // metadata: MPropertyStartGroup "+Death"
        // metadata: MPropertyDescription "Should the entity die when this part is destroyed?"
        bool m_bKillEntityOnDestruction; // 0x14        
        [[maybe_unused]] std::uint8_t pad_0x15[0x3]; // 0x15
        // metadata: MPropertyDescription "Custom death handshake to set when this part is destroyed."
        // metadata: MPropertySuppressExpr "m_bKillEntityOnDestruction == false"
        CGlobalSymbol m_sCustomDeathHandshake; // 0x18        
        // metadata: MPropertyStartGroup "+Conditions"
        // metadata: MPropertyDescription "Conditions to remove when this part is destroyed."
        // m_nConditionsToRemove has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVector<client::ConditionId_t> m_nConditionsToRemove;
        char m_nConditionsToRemove[0x18]; // 0x20        
        // metadata: MPropertyDescription "Conditions to add when this part is destroyed."
        // m_nConditionsToAdd has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVector<client::ConditionId_t> m_nConditionsToAdd;
        char m_nConditionsToAdd[0x18]; // 0x38        
    };
    #pragma pack(pop)
    
    static_assert(offsetof(CDestructiblePartsSystemData_PartRuntimeData, m_nHealth) == 0x0);
    static_assert(offsetof(CDestructiblePartsSystemData_PartRuntimeData, m_nDamagePassthroughType) == 0x10);
    static_assert(offsetof(CDestructiblePartsSystemData_PartRuntimeData, m_bKillEntityOnDestruction) == 0x14);
    static_assert(offsetof(CDestructiblePartsSystemData_PartRuntimeData, m_sCustomDeathHandshake) == 0x18);
    static_assert(offsetof(CDestructiblePartsSystemData_PartRuntimeData, m_nConditionsToRemove) == 0x20);
    static_assert(offsetof(CDestructiblePartsSystemData_PartRuntimeData, m_nConditionsToAdd) == 0x38);
    
    static_assert(sizeof(CDestructiblePartsSystemData_PartRuntimeData) == 0x50);
};
