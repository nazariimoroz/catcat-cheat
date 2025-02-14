#pragma once
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/server/CBaseEntity.hpp"
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
    // Size: 0x550
    // Has VTable
    #pragma pack(push, 1)
    class CEnvFireSensor : public server::CBaseEntity
    {
    public:
        bool m_bEnabled; // 0x4e8        
        bool m_bHeatAtLevel; // 0x4e9        
        [[maybe_unused]] std::uint8_t pad_0x4ea[0x2]; // 0x4ea
        float m_radius; // 0x4ec        
        float m_targetLevel; // 0x4f0        
        float m_targetTime; // 0x4f4        
        float m_levelTime; // 0x4f8        
        [[maybe_unused]] std::uint8_t pad_0x4fc[0x4]; // 0x4fc
        entity2::CEntityIOOutput m_OnHeatLevelStart; // 0x500        
        entity2::CEntityIOOutput m_OnHeatLevelEnd; // 0x528        
        
        // Datamap fields:
        // void InputEnable; // 0x0
        // void InputDisable; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CEnvFireSensor because it is not a standard-layout class
    static_assert(sizeof(CEnvFireSensor) == 0x550);
};
