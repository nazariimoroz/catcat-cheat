#pragma once
#include "source2sdk/client/ParticleIndex_t.hpp"
#include "source2sdk/server/CCitadel_Modifier_Invis.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    // Registered alignment: unknown
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x380
    // Has VTable
    #pragma pack(push, 1)
    class CCitadel_Modifier_Shadow_Step : public server::CCitadel_Modifier_Invis
    {
    public:
        client::ParticleIndex_t m_nRevealedEffect; // 0x260        
        [[maybe_unused]] std::uint8_t pad_0x264[0x11c];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Modifier_Shadow_Step because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Modifier_Shadow_Step) == 0x380);
};
