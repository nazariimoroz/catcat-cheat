#pragma once
#include "source2sdk/server/CCitadel_Item_TrackingProjectileApplyModifier.hpp"
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
    // Size: 0xb58
    // Has VTable
    #pragma pack(push, 1)
    class CItem_WitheringWhip : public server::CCitadel_Item_TrackingProjectileApplyModifier
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xb20[0x38];
        // No schema binary for binding
    };
    #pragma pack(pop)
    
    static_assert(sizeof(CItem_WitheringWhip) == 0xb58);
};
