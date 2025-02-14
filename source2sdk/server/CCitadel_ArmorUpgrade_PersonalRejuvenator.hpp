#pragma once
#include "source2sdk/client/ParticleIndex_t.hpp"
#include "source2sdk/server/CCitadel_Item.hpp"
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
    // Size: 0xbd0
    // Has VTable
    #pragma pack(push, 1)
    class CCitadel_ArmorUpgrade_PersonalRejuvenator : public server::CCitadel_Item
    {
    public:
        bool m_bActivated; // 0xb20        
        [[maybe_unused]] std::uint8_t pad_0xb21[0x3]; // 0xb21
        client::ParticleIndex_t m_nFxIndex; // 0xb24        
        [[maybe_unused]] std::uint8_t pad_0xb28[0xa8];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_ArmorUpgrade_PersonalRejuvenator because it is not a standard-layout class
    static_assert(sizeof(CCitadel_ArmorUpgrade_PersonalRejuvenator) == 0xbd0);
};
