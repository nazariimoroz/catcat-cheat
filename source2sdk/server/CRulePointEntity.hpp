#pragma once
#include "source2sdk/server/CRuleEntity.hpp"
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
    // Size: 0x7d0
    // Has VTable
    #pragma pack(push, 1)
    class CRulePointEntity : public server::CRuleEntity
    {
    public:
        int32_t m_Score; // 0x7c8        
        [[maybe_unused]] std::uint8_t pad_0x7cc[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CRulePointEntity because it is not a standard-layout class
    static_assert(sizeof(CRulePointEntity) == 0x7d0);
};
