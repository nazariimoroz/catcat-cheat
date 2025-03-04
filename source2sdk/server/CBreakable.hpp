#pragma once
#include "source2sdk/client/PerformanceMode_t.hpp"
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/entity2/GameTime_t.hpp"
#include "source2sdk/server/CBaseModelEntity.hpp"
#include "source2sdk/server/CPropDataComponent.hpp"
#include "source2sdk/server/EOverrideBlockLOS_t.hpp"
#include "source2sdk/server/Explosions.hpp"
#include "source2sdk/server/Materials.hpp"
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
    class CBasePlayerPawn;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x898
    // Has VTable
    // 
    // static metadata: MNetworkVarNames "CPropDataComponent::Storage_t m_CPropDataComponent"
    #pragma pack(push, 1)
    class CBreakable : public server::CBaseModelEntity
    {
    public:
        [[maybe_unused]] std::uint8_t pad_0x7c0[0x8]; // 0x7c0
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "CPropDataComponent"
        // metadata: MNetworkAlias "CPropDataComponent"
        // metadata: MNetworkTypeAlias "CPropDataComponent"
        server::CPropDataComponent m_CPropDataComponent; // 0x7c8        
        server::Materials m_Material; // 0x808        
        // m_hBreaker has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseEntity> m_hBreaker;
        char m_hBreaker[0x4]; // 0x80c        
        server::Explosions m_Explosion; // 0x810        
        [[maybe_unused]] std::uint8_t pad_0x814[0x4]; // 0x814
        CUtlSymbolLarge m_iszSpawnObject; // 0x818        
        float m_flPressureDelay; // 0x820        
        int32_t m_iMinHealthDmg; // 0x824        
        CUtlSymbolLarge m_iszPropData; // 0x828        
        float m_impactEnergyScale; // 0x830        
        server::EOverrideBlockLOS_t m_nOverrideBlockLOS; // 0x834        
        entity2::CEntityIOOutput m_OnBreak; // 0x838        
        // m_OnHealthChanged has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CEntityOutputTemplate<float> m_OnHealthChanged;
        char m_OnHealthChanged[0x28]; // 0x860        
        client::PerformanceMode_t m_PerformanceMode; // 0x888        
        // m_hPhysicsAttacker has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBasePlayerPawn> m_hPhysicsAttacker;
        char m_hPhysicsAttacker[0x4]; // 0x88c        
        entity2::GameTime_t m_flLastPhysicsInfluenceTime; // 0x890        
        [[maybe_unused]] std::uint8_t pad_0x894[0x4];
        
        // Datamap fields:
        // void InputBreak; // 0x0
        // int32_t InputSetHealth; // 0x0
        // int32_t InputAddHealth; // 0x0
        // int32_t InputRemoveHealth; // 0x0
        // float InputSetMass; // 0x0
        // void CBreakableDie; // 0x0
        // int32_t material; // 0x7fffffff
        // int32_t spawnobject; // 0x7fffffff
        // int32_t propdata; // 0x7fffffff
        // int64_t gamemass; // 0x7fffffff
        // float massScale; // 0x7fffffff
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CBreakable because it is not a standard-layout class
    static_assert(sizeof(CBreakable) == 0x898);
};
