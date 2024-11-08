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
    class CBaseEntity;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xc20
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "EHANDLE m_hActiveProjectile"
    #pragma pack(push, 1)
    class CCitadel_Ability_Perched_Predator : public server::CCitadelBaseAbility
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0xb00[0x118]; // 0xb00
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        // m_hActiveProjectile has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseEntity> m_hActiveProjectile;
        char m_hActiveProjectile[0x4]; // 0xc18        
        [[maybe_unused]] std::uint8_t pad_0xc1c[0x4];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Perched_Predator because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Perched_Predator) == 0xc20);
};
