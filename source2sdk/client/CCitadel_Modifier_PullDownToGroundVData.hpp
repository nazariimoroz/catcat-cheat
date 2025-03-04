#pragma once
#include "source2sdk/client/CCitadelModifierVData.hpp"
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
    // Standard-layout class: false
    // Size: 0x618
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Modifier_PullDownToGroundVData : public client::CCitadelModifierVData
    {
    public:
        float m_flMaxHeight; // 0x608        
        float m_flPullDownSpeedMin; // 0x60c        
        float m_flPullDownSpeedScale; // 0x610        
        [[maybe_unused]] std::uint8_t pad_0x614[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Modifier_PullDownToGroundVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Modifier_PullDownToGroundVData) == 0x618);
};
