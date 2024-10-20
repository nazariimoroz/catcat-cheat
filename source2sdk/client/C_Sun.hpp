#pragma once
#include "source2sdk/client/C_BaseModelEntity.hpp"
#include "source2sdk/client/ParticleIndex_t.hpp"
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
    // Size: 0x8a0
    // Has VTable
    // 
    // static metadata: MNetworkIncludeByName "m_clrRender"
    // static metadata: MNetworkExcludeByName "CGameSceneNode::m_vecOrigin"
    // static metadata: MNetworkIncludeByUserGroup "Origin"
    // static metadata: MNetworkIncludeByName "CGameSceneNode::m_angRotation"
    // static metadata: MNetworkIncludeByName "CGameSceneNode::m_hParent"
    // static metadata: MNetworkIncludeByName "m_spawnflags"
    // static metadata: MNetworkVarNames "Vector m_vDirection"
    // static metadata: MNetworkVarNames "string_t m_iszEffectName"
    // static metadata: MNetworkVarNames "string_t m_iszSSEffectName"
    // static metadata: MNetworkVarNames "Color m_clrOverlay"
    // static metadata: MNetworkVarNames "bool m_bOn"
    // static metadata: MNetworkVarNames "bool m_bmaxColor"
    // static metadata: MNetworkVarNames "float32 m_flSize"
    // static metadata: MNetworkVarNames "float32 m_flHazeScale"
    // static metadata: MNetworkVarNames "float32 m_flRotation"
    // static metadata: MNetworkVarNames "float32 m_flHDRColorScale"
    // static metadata: MNetworkVarNames "float32 m_flAlphaHaze"
    // static metadata: MNetworkVarNames "float32 m_flAlphaScale"
    // static metadata: MNetworkVarNames "float32 m_flAlphaHdr"
    // static metadata: MNetworkVarNames "float32 m_flFarZScale"
    #pragma pack(push, 1)
    class C_Sun : public client::C_BaseModelEntity
    {
    public:
        client::ParticleIndex_t m_fxSSSunFlareEffectIndex; // 0x840        
        client::ParticleIndex_t m_fxSunFlareEffectIndex; // 0x844        
        float m_fdistNormalize; // 0x848        
        Vector m_vSunPos; // 0x84c        
        // metadata: MNetworkEnable
        Vector m_vDirection; // 0x858        
        [[maybe_unused]] std::uint8_t pad_0x864[0x4]; // 0x864
        // metadata: MNetworkEnable
        CUtlSymbolLarge m_iszEffectName; // 0x868        
        // metadata: MNetworkEnable
        CUtlSymbolLarge m_iszSSEffectName; // 0x870        
        // metadata: MNetworkEnable
        Color m_clrOverlay; // 0x878        
        // metadata: MNetworkEnable
        bool m_bOn; // 0x87c        
        // metadata: MNetworkEnable
        bool m_bmaxColor; // 0x87d        
        [[maybe_unused]] std::uint8_t pad_0x87e[0x2]; // 0x87e
        // metadata: MNetworkEnable
        // metadata: MNetworkBitCount "10"
        float m_flSize; // 0x880        
        // metadata: MNetworkEnable
        // metadata: MNetworkBitCount "10"
        float m_flHazeScale; // 0x884        
        // metadata: MNetworkEnable
        // metadata: MNetworkMinValue "-360.000000"
        // metadata: MNetworkMaxValue "360.000000"
        float m_flRotation; // 0x888        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "OnHDRScaleChanged"
        float m_flHDRColorScale; // 0x88c        
        // metadata: MNetworkEnable
        // metadata: MNetworkMinValue "0.000000"
        // metadata: MNetworkMaxValue "2.000000"
        float m_flAlphaHaze; // 0x890        
        // metadata: MNetworkEnable
        // metadata: MNetworkMinValue "0.000000"
        // metadata: MNetworkMaxValue "2.000000"
        float m_flAlphaScale; // 0x894        
        // metadata: MNetworkEnable
        // metadata: MNetworkMinValue "0.000000"
        // metadata: MNetworkMaxValue "2.000000"
        float m_flAlphaHdr; // 0x898        
        // metadata: MNetworkEnable
        // metadata: MNetworkMinValue "0.000000"
        // metadata: MNetworkMaxValue "1.000000"
        float m_flFarZScale; // 0x89c        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in C_Sun because it is not a standard-layout class
    static_assert(sizeof(C_Sun) == 0x8a0);
};
