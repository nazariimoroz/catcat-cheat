#pragma once
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
    // Size: 0xc10
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "Vector m_vecCastPosition"
    // static metadata: MNetworkVarNames "Vector m_vecCastPositionNormal"
    // static metadata: MNetworkVarNames "Vector m_vecEndPosition"
    // static metadata: MNetworkVarNames "Vector m_vecEndPositionNormal"
    #pragma pack(push, 1)
    class CCitadel_Ability_Trapper_WebWall : public server::CCitadelBaseAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xb00[0xe0]; // 0xb00
        // metadata: MNetworkEnable
        Vector m_vecCastPosition; // 0xbe0        
        // metadata: MNetworkEnable
        Vector m_vecCastPositionNormal; // 0xbec        
        // metadata: MNetworkEnable
        Vector m_vecEndPosition; // 0xbf8        
        // metadata: MNetworkEnable
        Vector m_vecEndPositionNormal; // 0xc04        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Trapper_WebWall because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Trapper_WebWall) == 0xc10);
};
