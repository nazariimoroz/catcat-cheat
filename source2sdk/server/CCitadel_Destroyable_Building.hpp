#pragma once
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/entity2/GameTime_t.hpp"
#include "source2sdk/server/CCitadelAbilityComponent.hpp"
#include "source2sdk/server/CCitadelAnimatingModelEntity.hpp"
#include "source2sdk/server/CCitadelMinimapComponent.hpp"
#include "source2sdk/server/WeakPoint_t.hpp"
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
    // Size: 0x1008
    // Has VTable
    // 
    // static metadata: MNetworkIncludeByName "m_bTakesDamage"
    // static metadata: MNetworkIncludeByName "m_nTakeDamageFlags"
    // static metadata: MNetworkVarNames "CCitadelMinimapComponent::Storage_t m_CCitadelMinimapComponent"
    // static metadata: MNetworkVarNames "CCitadelAbilityComponent::Storage_t m_CCitadelAbilityComponent"
    // static metadata: MNetworkVarNames "WeakPoint_t m_vecWeakPoints"
    // static metadata: MNetworkVarNames "bool m_bDestroyed"
    // static metadata: MNetworkVarNames "bool m_bActive"
    // static metadata: MNetworkVarNames "bool m_bFinal"
    #pragma pack(push, 1)
    class CCitadel_Destroyable_Building : public server::CCitadelAnimatingModelEntity
    {
    public:
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "CCitadelMinimapComponent"
        // metadata: MNetworkAlias "CCitadelMinimapComponent"
        // metadata: MNetworkTypeAlias "CCitadelMinimapComponent"
        server::CCitadelMinimapComponent m_CCitadelMinimapComponent; // 0xbc8        
        entity2::CEntityIOOutput m_OnDestroyed; // 0xbe0        
        entity2::CEntityIOOutput m_OnRevitilized; // 0xc08        
        entity2::CEntityIOOutput m_OnDamageTaken; // 0xc30        
        entity2::CEntityIOOutput m_OnLifeChanged; // 0xc58        
        entity2::CEntityIOOutput m_OnBecomeActive; // 0xc80        
        entity2::CEntityIOOutput m_OnBecomeInvulnerable; // 0xca8        
        entity2::CEntityIOOutput m_OnBecomeVulnerable; // 0xcd0        
        entity2::CEntityIOOutput m_OnUnderAttack; // 0xcf8        
        entity2::CEntityIOOutput m_OnAttackSubsided; // 0xd20        
        int32_t m_nBuildingHealth; // 0xd48        
        [[maybe_unused]] std::uint8_t pad_0xd4c[0x4]; // 0xd4c
        int32_t m_iLane; // 0xd50        
        entity2::GameTime_t m_flDestroyedTime; // 0xd54        
        entity2::GameTime_t m_flLastDamagedTime; // 0xd58        
        QAngle m_angOriginal; // 0xd5c        
        [[maybe_unused]] std::uint8_t pad_0xd68[0x18]; // 0xd68
        CUtlSymbolLarge m_backdoorProtectionTrigger; // 0xd80        
        [[maybe_unused]] std::uint8_t pad_0xd88[0x8]; // 0xd88
        // metadata: MNetworkEnable
        // metadata: MNetworkUserGroup "CCitadelAbilityComponent"
        // metadata: MNetworkAlias "CCitadelAbilityComponent"
        // metadata: MNetworkTypeAlias "CCitadelAbilityComponent"
        server::CCitadelAbilityComponent m_CCitadelAbilityComponent; // 0xd90        
        // metadata: MNetworkEnable
        // m_vecWeakPoints has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVectorEmbeddedNetworkVar<server::WeakPoint_t> m_vecWeakPoints;
        char m_vecWeakPoints[0x68]; // 0xf98        
        // metadata: MNetworkEnable
        // metadata: MNetworkChangeCallback "DestroyedChanged"
        bool m_bDestroyed; // 0x1000        
        // metadata: MNetworkEnable
        bool m_bActive; // 0x1001        
        // metadata: MNetworkEnable
        bool m_bFinal; // 0x1002        
        [[maybe_unused]] std::uint8_t pad_0x1003[0x5];
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CCitadel_Destroyable_Building because it is not a standard-layout class
    static_assert(sizeof(CCitadel_Destroyable_Building) == 0x1008);
};
