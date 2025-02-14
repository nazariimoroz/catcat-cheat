#pragma once
#include "source2sdk/server/CLogicalEntity.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    class CLightEntity;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x528
    // Has VTable
    #pragma pack(push, 1)
    class CMultiLightProxy : public server::CLogicalEntity
    {
    public:
        CUtlSymbolLarge m_iszLightNameFilter; // 0x4e8        
        CUtlSymbolLarge m_iszLightClassFilter; // 0x4f0        
        float m_flLightRadiusFilter; // 0x4f8        
        float m_flBrightnessDelta; // 0x4fc        
        bool m_bPerformScreenFade; // 0x500        
        [[maybe_unused]] std::uint8_t pad_0x501[0x3]; // 0x501
        float m_flTargetBrightnessMultiplier; // 0x504        
        float m_flCurrentBrightnessMultiplier; // 0x508        
        [[maybe_unused]] std::uint8_t pad_0x50c[0x4]; // 0x50c
        // m_vecLights has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVector<CHandle<server::CLightEntity>> m_vecLights;
        char m_vecLights[0x18]; // 0x510        
        
        // Datamap fields:
        // float InputFlickerLights; // 0x0
        // float InputDisableLights; // 0x0
        // float InputSetLightsBrightnessMultiplier; // 0x0
        // float InputSetBrightnessDelta; // 0x0
        // void CMultiLightProxyRestoreFlashlightThink; // 0x0
        // void CMultiLightProxyApproachBrightnessThink; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CMultiLightProxy because it is not a standard-layout class
    static_assert(sizeof(CMultiLightProxy) == 0x528);
};
