#pragma once
#include "source2sdk/client/CCitadelModifier.hpp"
#include "source2sdk/client/CitadelItemVData.hpp"
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
    // Size: 0x15b8
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CCitadel_ArmorUpgrade_VexBarrierVData : public client::CitadelItemVData
    {
    public:
        // metadata: MPropertyGroupName "Modifiers"
        // m_ShieldModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<client::CCitadelModifier> m_ShieldModifier;
        char m_ShieldModifier[0x10]; // 0x15a8        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_ArmorUpgrade_VexBarrierVData because it is not a standard-layout class
    static_assert(sizeof(CCitadel_ArmorUpgrade_VexBarrierVData) == 0x15b8);
};
