#pragma once
#include "source2sdk/server/CLogicNPCCounter.hpp"
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
    // Size: 0x858
    // Has VTable
    #pragma pack(push, 1)
    class CLogicNPCCounterAABB : public server::CLogicNPCCounter
    {
    public:
        Vector m_vDistanceOuterMins; // 0x828        
        Vector m_vDistanceOuterMaxs; // 0x834        
        Vector m_vOuterMins; // 0x840        
        Vector m_vOuterMaxs; // 0x84c        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CLogicNPCCounterAABB because it is not a standard-layout class
    static_assert(sizeof(CLogicNPCCounterAABB) == 0x858);
};
