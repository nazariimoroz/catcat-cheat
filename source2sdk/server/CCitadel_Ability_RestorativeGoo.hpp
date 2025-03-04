#pragma once
#include "source2sdk/entity2/GameTime_t.hpp"
#include "source2sdk/server/CCitadelBaseAbility.hpp"
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
    // Size: 0xb08
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "GameTime_t m_flSelfCastEndTime"
    #pragma pack(push, 1)
    class CCitadel_Ability_RestorativeGoo : public server::CCitadelBaseAbility
    {
    public:
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        entity2::GameTime_t m_flSelfCastEndTime; // 0xb00        
        [[maybe_unused]] std::uint8_t pad_0xb04[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_RestorativeGoo because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_RestorativeGoo) == 0xb08);
};
