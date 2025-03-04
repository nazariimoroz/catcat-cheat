#pragma once
#include "source2sdk/client/CCitadelModifier.hpp"
#include "source2sdk/client/CitadelAbilityVData.hpp"
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
    // Size: 0x15d0
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Ability_Climb_RopeVData : public client::CitadelAbilityVData
    {
    public:
        float m_flMinButtonHoldTimeToActivate; // 0x1560        
        float m_flClimbSpeedUp; // 0x1564        
        float m_flClimbSpeedDown; // 0x1568        
        float m_flClimbSpeedDownMax; // 0x156c        
        float m_flClimbDownAccelTime; // 0x1570        
        float m_flLatchSpeed; // 0x1574        
        float m_flAttachOffset; // 0x1578        
        float m_flMinReconnectTime; // 0x157c        
        float m_flSideMoveReduction; // 0x1580        
        float m_flTopOffset; // 0x1584        
        float m_flBottomOffset; // 0x1588        
        float m_flTraceRadiusSize; // 0x158c        
        float m_flStopTimeToShoot; // 0x1590        
        float m_flJumpOffVertical; // 0x1594        
        float m_flJumpOffHorizontal; // 0x1598        
        float m_flDuckOffVertical; // 0x159c        
        float m_flDuckOffHorizontal; // 0x15a0        
        float m_flActivateRange; // 0x15a4        
        float m_flJumpToRoofRayCheckDist; // 0x15a8        
        float m_flMinTimeToRoofCheck; // 0x15ac        
        float m_flTimeToHintRefresh; // 0x15b0        
        float m_iMaxHintCount; // 0x15b4        
        float m_flClimbRopeSlowDurationOnHit; // 0x15b8        
        [[maybe_unused]] std::uint8_t pad_0x15bc[0x4]; // 0x15bc
        // metadata: MPropertyStartGroup "Modifiers"
        // m_ClimbRopeSlowOnHitModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CCitadelModifier> m_ClimbRopeSlowOnHitModifier;
        char m_ClimbRopeSlowOnHitModifier[0x10]; // 0x15c0        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Ability_Climb_RopeVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Ability_Climb_RopeVData) == 0x15d0);
};
