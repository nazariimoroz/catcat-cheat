#pragma once
#include "source2sdk/client/C_PointClientUIWorldPanel.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: client
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::client
{
    // Registered alignment: unknown
    // Alignment: 0x10
    // Standard-layout class: false
    // Size: 0xaa0
    // Has VTable
    #pragma pack(push, 1)
    class CUnitStatusOverlay : public client::C_PointClientUIWorldPanel
    {
    public:
        // No schema binary for binding
    };
    #pragma pack(pop)
    
    static_assert(sizeof(CUnitStatusOverlay) == 0xaa0);
};
