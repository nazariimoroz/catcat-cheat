#pragma once
#include "source2sdk/client/C_CitadelBaseAbility.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: client
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::client
{
    class C_BaseEntity;
};

namespace source2sdk::client
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xe08
    // Has VTable
    #pragma pack(push, 1)
    class CCitadel_Ability_Ghost_BloodShards : public client::C_CitadelBaseAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xca0[0x150]; // 0xca0
        // m_vecDamagedTargets has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVector<CHandle<client::C_BaseEntity>> m_vecDamagedTargets;
        char m_vecDamagedTargets[0x18]; // 0xdf0        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Ghost_BloodShards because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Ghost_BloodShards) == 0xe08);
};
