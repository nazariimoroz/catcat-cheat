#pragma once
#include "source2sdk/server/CCitadelModifier.hpp"
#include "source2sdk/server/CitadelAbilityVData.hpp"
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
    // Size: 0x1580
    // Has VTable
    // 
    // static metadata: MGetKV3ClassDefaults
    #pragma pack(push, 1)
    class CAbilityKobunVData : public server::CitadelAbilityVData
    {
    public:
        Vector m_vSummonFollowOffset; // 0x1560        
        [[maybe_unused]] std::uint8_t pad_0x156c[0x4]; // 0x156c
        // metadata: MPropertyStartGroup "Modifiers"
        // m_CloneModifier has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEmbeddedSubclass<server::CCitadelModifier> m_CloneModifier;
        char m_CloneModifier[0x10]; // 0x1570        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CAbilityKobunVData because it is not a standard-layout class
    static_assert(sizeof(CAbilityKobunVData) == 0x1580);
};
