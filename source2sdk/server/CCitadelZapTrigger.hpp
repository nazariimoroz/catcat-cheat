#pragma once
#include "source2sdk/server/CFuncBrush.hpp"
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
    // Size: 0x830
    // Has VTable
    #pragma pack(push, 1)
    class CCitadelZapTrigger : public server::CFuncBrush
    {
    public:
        float m_flShootAfterEnteringTime; // 0x7e0        
        float m_flWaitForNextShootTime; // 0x7e4        
        float m_flPercentMaxHealthDamage; // 0x7e8        
        [[maybe_unused]] std::uint8_t pad_0x7ec[0x4]; // 0x7ec
        CUtlSymbolLarge m_strShootOrigin; // 0x7f0        
        [[maybe_unused]] std::uint8_t pad_0x7f8[0x38];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadelZapTrigger because it is not a standard-layout class
    static_assert(sizeof(CCitadelZapTrigger) == 0x830);
};
