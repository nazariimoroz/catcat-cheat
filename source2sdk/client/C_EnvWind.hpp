#pragma once
#include "source2sdk/client/C_BaseEntity.hpp"
#include "source2sdk/client/C_EnvWindShared.hpp"
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
    // Size: 0x770
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "CEnvWindShared m_EnvWindShared"
    #pragma pack(push, 1)
    class C_EnvWind : public client::C_BaseEntity
    {
    public:
        // metadata: MNetworkEnable
        client::C_EnvWindShared m_EnvWindShared; // 0x568        
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in C_EnvWind because it is not a standard-layout class
    static_assert(sizeof(C_EnvWind) == 0x770);
};
