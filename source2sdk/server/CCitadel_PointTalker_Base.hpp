#pragma once
#include "source2sdk/server/CBaseCombatCharacter.hpp"
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
    // Size: 0xb60
    // Has VTable
    #pragma pack(push, 1)
    class CCitadel_PointTalker_Base : public server::CBaseCombatCharacter
    {
    public:
        // No schema binary for binding
    };
    #pragma pack(pop)
    
    static_assert(sizeof(CCitadel_PointTalker_Base) == 0xb60);
};
