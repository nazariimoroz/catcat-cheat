#pragma once
#include "source2sdk/server/CBaseTrigger.hpp"
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
    // Size: 0x9d0
    // Has VTable
    #pragma pack(push, 1)
    class CTriggerProximity : public server::CBaseTrigger
    {
    public:
        // m_hMeasureTarget has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseEntity> m_hMeasureTarget;
        char m_hMeasureTarget[0x4]; // 0x990        
        [[maybe_unused]] std::uint8_t pad_0x994[0x4]; // 0x994
        CUtlSymbolLarge m_iszMeasureTarget; // 0x998        
        float m_fRadius; // 0x9a0        
        int32_t m_nTouchers; // 0x9a4        
        // m_NearestEntityDistance has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEntityOutputTemplate<float> m_NearestEntityDistance;
        char m_NearestEntityDistance[0x28]; // 0x9a8        
        
        // Datamap fields:
        // void CTriggerProximityMeasureThink; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CTriggerProximity because it is not a standard-layout class
    static_assert(sizeof(CTriggerProximity) == 0x9d0);
};
