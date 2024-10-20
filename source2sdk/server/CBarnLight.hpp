#pragma once
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/entity2/GameTime_t.hpp"
#include "source2sdk/resourcesystem/InfoForResourceTypeCTextureBase.hpp"
#include "source2sdk/server/CBaseModelEntity.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    class CBaseModelEntity;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xae8
    // Has VTable
    // 
    // static metadata: MEntityAllowsPortraitWorldSpawn
    // static metadata: MNetworkVarNames "bool m_bEnabled"
    // static metadata: MNetworkVarNames "int m_nColorMode"
    // static metadata: MNetworkVarNames "Color m_Color"
    // static metadata: MNetworkVarNames "float m_flColorTemperature"
    // static metadata: MNetworkVarNames "float m_flBrightness"
    // static metadata: MNetworkVarNames "float m_flBrightnessScale"
    // static metadata: MNetworkVarNames "int m_nDirectLight"
    // static metadata: MNetworkVarNames "int m_nBakedShadowIndex"
    // static metadata: MNetworkVarNames "int m_nLuminaireShape"
    // static metadata: MNetworkVarNames "float m_flLuminaireSize"
    // static metadata: MNetworkVarNames "float m_flLuminaireAnisotropy"
    // static metadata: MNetworkVarNames "CUtlString m_LightStyleString"
    // static metadata: MNetworkVarNames "GameTime_t m_flLightStyleStartTime"
    // static metadata: MNetworkVarNames "CUtlString m_QueuedLightStyleStrings"
    // static metadata: MNetworkVarNames "CUtlString m_LightStyleEvents"
    // static metadata: MNetworkVarNames "CHandle< CBaseModelEntity > m_LightStyleTargets"
    // static metadata: MNetworkVarNames "HRenderTextureStrong m_hLightCookie"
    // static metadata: MNetworkVarNames "float m_flShape"
    // static metadata: MNetworkVarNames "float m_flSoftX"
    // static metadata: MNetworkVarNames "float m_flSoftY"
    // static metadata: MNetworkVarNames "float m_flSkirt"
    // static metadata: MNetworkVarNames "float m_flSkirtNear"
    // static metadata: MNetworkVarNames "Vector m_vSizeParams"
    // static metadata: MNetworkVarNames "float m_flRange"
    // static metadata: MNetworkVarNames "Vector m_vShear"
    // static metadata: MNetworkVarNames "int m_nBakeSpecularToCubemaps"
    // static metadata: MNetworkVarNames "Vector m_vBakeSpecularToCubemapsSize"
    // static metadata: MNetworkVarNames "int m_nCastShadows"
    // static metadata: MNetworkVarNames "int m_nShadowMapSize"
    // static metadata: MNetworkVarNames "int m_nShadowPriority"
    // static metadata: MNetworkVarNames "bool m_bContactShadow"
    // static metadata: MNetworkVarNames "int m_nBounceLight"
    // static metadata: MNetworkVarNames "float m_flBounceScale"
    // static metadata: MNetworkVarNames "float m_flMinRoughness"
    // static metadata: MNetworkVarNames "Vector m_vAlternateColor"
    // static metadata: MNetworkVarNames "float m_fAlternateColorBrightness"
    // static metadata: MNetworkVarNames "int m_nFog"
    // static metadata: MNetworkVarNames "float m_flFogStrength"
    // static metadata: MNetworkVarNames "int m_nFogShadows"
    // static metadata: MNetworkVarNames "float m_flFogScale"
    // static metadata: MNetworkVarNames "bool m_bFogMixedShadows"
    // static metadata: MNetworkVarNames "float m_flFadeSizeStart"
    // static metadata: MNetworkVarNames "float m_flFadeSizeEnd"
    // static metadata: MNetworkVarNames "float m_flShadowFadeSizeStart"
    // static metadata: MNetworkVarNames "float m_flShadowFadeSizeEnd"
    // static metadata: MNetworkVarNames "bool m_bPrecomputedFieldsValid"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedBoundsMins"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedBoundsMaxs"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent"
    // static metadata: MNetworkVarNames "int m_nPrecomputedSubFrusta"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin0"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles0"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent0"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin1"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles1"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent1"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin2"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles2"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent2"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin3"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles3"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent3"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin4"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles4"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent4"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBOrigin5"
    // static metadata: MNetworkVarNames "QAngle m_vPrecomputedOBBAngles5"
    // static metadata: MNetworkVarNames "Vector m_vPrecomputedOBBExtent5"
    // static metadata: MNetworkVarNames "uint16 m_VisClusters"
    #pragma pack(push, 1)
    class CBarnLight : public server::CBaseModelEntity
    {
    public:
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        bool m_bEnabled; // 0x7c8        
        [[maybe_unused]] std::uint8_t pad_0x7c9[0x3]; // 0x7c9
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nColorMode; // 0x7cc        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Color m_Color; // 0x7d0        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flColorTemperature; // 0x7d4        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flBrightness; // 0x7d8        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flBrightnessScale; // 0x7dc        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nDirectLight; // 0x7e0        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nBakedShadowIndex; // 0x7e4        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nLuminaireShape; // 0x7e8        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flLuminaireSize; // 0x7ec        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flLuminaireAnisotropy; // 0x7f0        
        [[maybe_unused]] std::uint8_t pad_0x7f4[0x4]; // 0x7f4
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "StyleChanged"
        CUtlString m_LightStyleString; // 0x7f8        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        entity2::GameTime_t m_flLightStyleStartTime; // 0x800        
        [[maybe_unused]] std::uint8_t pad_0x804[0x4]; // 0x804
        // metadata: MNetworkEnable
        // m_QueuedLightStyleStrings has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CNetworkUtlVectorBase<CUtlString> m_QueuedLightStyleStrings;
        char m_QueuedLightStyleStrings[0x18]; // 0x808        
        // metadata: MNetworkEnable
        // m_LightStyleEvents has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CNetworkUtlVectorBase<CUtlString> m_LightStyleEvents;
        char m_LightStyleEvents[0x18]; // 0x820        
        // metadata: MNetworkEnable
        // m_LightStyleTargets has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CNetworkUtlVectorBase<CHandle<server::CBaseModelEntity>> m_LightStyleTargets;
        char m_LightStyleTargets[0x18]; // 0x838        
        entity2::CEntityIOOutput m_StyleEvent[4]; // 0x850        
        [[maybe_unused]] std::uint8_t pad_0x8f0[0x20]; // 0x8f0
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        // m_hLightCookie has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CStrongHandle<resourcesystem::InfoForResourceTypeCTextureBase> m_hLightCookie;
        char m_hLightCookie[0x8]; // 0x910        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flShape; // 0x918        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flSoftX; // 0x91c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flSoftY; // 0x920        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flSkirt; // 0x924        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flSkirtNear; // 0x928        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        // metadata: MNetworkBitCount "32"
        Vector m_vSizeParams; // 0x92c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        // metadata: MNetworkBitCount "32"
        float m_flRange; // 0x938        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        // metadata: MNetworkBitCount "32"
        Vector m_vShear; // 0x93c        
        // metadata: MNetworkEnable
        int32_t m_nBakeSpecularToCubemaps; // 0x948        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        // metadata: MNetworkBitCount "32"
        Vector m_vBakeSpecularToCubemapsSize; // 0x94c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nCastShadows; // 0x958        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nShadowMapSize; // 0x95c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nShadowPriority; // 0x960        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        bool m_bContactShadow; // 0x964        
        [[maybe_unused]] std::uint8_t pad_0x965[0x3]; // 0x965
        // metadata: MNetworkEnable
        int32_t m_nBounceLight; // 0x968        
        // metadata: MNetworkEnable
        float m_flBounceScale; // 0x96c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flMinRoughness; // 0x970        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vAlternateColor; // 0x974        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_fAlternateColorBrightness; // 0x980        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nFog; // 0x984        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flFogStrength; // 0x988        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nFogShadows; // 0x98c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flFogScale; // 0x990        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        bool m_bFogMixedShadows; // 0x994        
        [[maybe_unused]] std::uint8_t pad_0x995[0x3]; // 0x995
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flFadeSizeStart; // 0x998        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flFadeSizeEnd; // 0x99c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flShadowFadeSizeStart; // 0x9a0        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        float m_flShadowFadeSizeEnd; // 0x9a4        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        bool m_bPrecomputedFieldsValid; // 0x9a8        
        [[maybe_unused]] std::uint8_t pad_0x9a9[0x3]; // 0x9a9
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedBoundsMins; // 0x9ac        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedBoundsMaxs; // 0x9b8        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin; // 0x9c4        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles; // 0x9d0        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent; // 0x9dc        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        int32_t m_nPrecomputedSubFrusta; // 0x9e8        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin0; // 0x9ec        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles0; // 0x9f8        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent0; // 0xa04        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin1; // 0xa10        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles1; // 0xa1c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent1; // 0xa28        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin2; // 0xa34        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles2; // 0xa40        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent2; // 0xa4c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin3; // 0xa58        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles3; // 0xa64        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent3; // 0xa70        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin4; // 0xa7c        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles4; // 0xa88        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent4; // 0xa94        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBOrigin5; // 0xaa0        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        QAngle m_vPrecomputedOBBAngles5; // 0xaac        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        Vector m_vPrecomputedOBBExtent5; // 0xab8        
        bool m_bPvsModifyEntity; // 0xac4        
        [[maybe_unused]] std::uint8_t pad_0xac5[0x3]; // 0xac5
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "RenderingChanged"
        // m_VisClusters has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CNetworkUtlVectorBase<uint16_t> m_VisClusters;
        char m_VisClusters[0x18]; // 0xac8        
        [[maybe_unused]] std::uint8_t pad_0xae0[0x8];
        
        // Datamap fields:
        // void m_StyleEvent[0]; // 0x850
        // void m_StyleEvent[1]; // 0x878
        // void m_StyleEvent[2]; // 0x8a0
        // void m_StyleEvent[3]; // 0x8c8
        // void CBarnLightThink_SetNextQueuedLightStyle; // 0x0
        // void CBarnLightThink_ApplyLightStylesToTargets; // 0x0
        // void CBarnLightThink_LightStyleEvent; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CBarnLight because it is not a standard-layout class
    static_assert(sizeof(CBarnLight) == 0xae8);
};
