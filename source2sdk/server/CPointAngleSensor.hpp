#pragma once
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/entity2/GameTime_t.hpp"
#include "source2sdk/server/CPointEntity.hpp"
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
    // Size: 0x5b0
    // Has VTable
    #pragma pack(push, 1)
    class CPointAngleSensor : public server::CPointEntity
    {
    public:
        bool m_bDisabled; // 0x4e8        
        [[maybe_unused]] std::uint8_t pad_0x4e9[0x7]; // 0x4e9
        CUtlSymbolLarge m_nLookAtName; // 0x4f0        
        // m_hTargetEntity has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseEntity> m_hTargetEntity;
        char m_hTargetEntity[0x4]; // 0x4f8        
        // m_hLookAtEntity has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseEntity> m_hLookAtEntity;
        char m_hLookAtEntity[0x4]; // 0x4fc        
        float m_flDuration; // 0x500        
        float m_flDotTolerance; // 0x504        
        entity2::GameTime_t m_flFacingTime; // 0x508        
        bool m_bFired; // 0x50c        
        [[maybe_unused]] std::uint8_t pad_0x50d[0x3]; // 0x50d
        entity2::CEntityIOOutput m_OnFacingLookat; // 0x510        
        entity2::CEntityIOOutput m_OnNotFacingLookat; // 0x538        
        // m_TargetDir has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEntityOutputTemplate<Vector> m_TargetDir;
        char m_TargetDir[0x28]; // 0x560        
        // m_FacingPercentage has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEntityOutputTemplate<float> m_FacingPercentage;
        char m_FacingPercentage[0x28]; // 0x588        
        
        // Datamap fields:
        // void InputEnable; // 0x0
        // void InputDisable; // 0x0
        // void InputToggle; // 0x0
        // void InputTest; // 0x0
        // CUtlSymbolLarge InputSetTargetEntity; // 0x0
        // float tolerance; // 0x7fffffff
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CPointAngleSensor because it is not a standard-layout class
    static_assert(sizeof(CPointAngleSensor) == 0x5b0);
};
