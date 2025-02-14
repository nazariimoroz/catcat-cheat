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
    // Size: 0xc60
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "float m_flDissipationRate"
    // static metadata: MNetworkVarNames "GameTime_t m_flDissipationTime"
    // static metadata: MNetworkVarNames "GameTime_t m_flHeatTime"
    // static metadata: MNetworkVarNames "GameTime_t m_flOverheatSoundTime"
    // static metadata: MNetworkVarNames "bool m_bOverheating"
    #pragma pack(push, 1)
    class CCitadel_Ability_Tokamak_HeatSinks_Inherent : public server::CCitadelBaseAbility
    {
    public:
        int32_t m_nIntervalsElapsed; // 0xb00        
        entity2::GameTime_t m_NextShotTime; // 0xb04        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        float m_flDissipationRate; // 0xb08        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        entity2::GameTime_t m_flDissipationTime; // 0xb0c        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        entity2::GameTime_t m_flHeatTime; // 0xb10        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        entity2::GameTime_t m_flOverheatSoundTime; // 0xb14        
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "LocalPlayerOwnerAndObserversExclusive"
        bool m_bOverheating; // 0xb18        
        [[maybe_unused]] std::uint8_t pad_0xb19[0x147];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Tokamak_HeatSinks_Inherent because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Tokamak_HeatSinks_Inherent) == 0xc60);
};
