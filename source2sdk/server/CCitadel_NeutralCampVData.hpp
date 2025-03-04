#pragma once
#include "source2sdk/client/CEntitySubclassVDataBase.hpp"
#include "source2sdk/client/ENeutralTrooperType.hpp"
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
    // Size: 0x60
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_NeutralCampVData : public client::CEntitySubclassVDataBase
    {
    public:
        // metadata: MPropertyStartGroup "Gameplay"
        int32_t m_iInitialSpawnDelayInSeconds; // 0x28        
        int32_t m_iSpawnIntervalInSeconds; // 0x2c        
        int32_t m_iSpawnIntervalChange; // 0x30        
        int32_t m_iSpawnIntervalMin; // 0x34        
        client::ENeutralTrooperType m_eNeutralType; // 0x38        
        [[maybe_unused]] std::uint8_t pad_0x3c[0x4]; // 0x3c
        // metadata: MPropertyStartGroup "Sounds"
        CSoundEventName m_sIdleAmbient; // 0x40        
        CSoundEventName m_sAlertAmbient; // 0x50        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_NeutralCampVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_NeutralCampVData) == 0x60);
};
