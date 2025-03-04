#pragma once
#include "source2sdk/client/CBaseModifier.hpp"
#include "source2sdk/client/CCitadel_Modifier_BaseEventProcVData.hpp"
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
    // Size: 0x660
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_Modifier_ApplyDebuff_ProcVData : public client::CCitadel_Modifier_BaseEventProcVData
    {
    public:
        bool m_bUseNonEmbedded; // 0x638        
        [[maybe_unused]] std::uint8_t pad_0x639[0x7]; // 0x639
        // metadata: MPropertyGroupName "Modifiers"
        // m_DebuffModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CBaseModifier> m_DebuffModifier;
        char m_DebuffModifier[0x10]; // 0x640        
        // m_NonEmbeddedModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CSubclassName<2> m_NonEmbeddedModifier;
        char m_NonEmbeddedModifier[0x10]; // 0x650        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Modifier_ApplyDebuff_ProcVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Modifier_ApplyDebuff_ProcVData) == 0x660);
};
