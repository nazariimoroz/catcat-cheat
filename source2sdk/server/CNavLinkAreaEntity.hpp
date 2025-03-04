#pragma once
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/server/CPointEntity.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    class CAI_BaseNPC;
};

namespace source2sdk::server
{
    class CBaseFilter;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x650
    // Has VTable
    #pragma pack(push, 1)
    class CNavLinkAreaEntity : public server::CPointEntity
    {
    public:
        float m_flWidth; // 0x4e8        
        Vector m_vLocatorOffset; // 0x4ec        
        QAngle m_qLocatorAnglesOffset; // 0x4f8        
        [[maybe_unused]] std::uint8_t pad_0x504[0x4]; // 0x504
        CUtlSymbolLarge m_strMovementForward; // 0x508        
        CUtlSymbolLarge m_strMovementReverse; // 0x510        
        int32_t m_nNavLinkIdForward; // 0x518        
        int32_t m_nNavLinkIdReverse; // 0x51c        
        bool m_bEnabled; // 0x520        
        [[maybe_unused]] std::uint8_t pad_0x521[0x7]; // 0x521
        CUtlSymbolLarge m_strFilterName; // 0x528        
        // m_hFilter has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseFilter> m_hFilter;
        char m_hFilter[0x4]; // 0x530        
        [[maybe_unused]] std::uint8_t pad_0x534[0x4]; // 0x534
        // m_vecNpcUsers has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CUtlVectorFixedGrowable<CHandle<server::CAI_BaseNPC>,6> m_vecNpcUsers;
        char m_vecNpcUsers[0x30]; // 0x538        
        CUtlSymbolLarge m_szListenForAnimTag; // 0x568        
        bool m_bIsListeningForAnimTag; // 0x570        
        [[maybe_unused]] std::uint8_t pad_0x571[0xf]; // 0x571
        entity2::CEntityIOOutput m_OnAnimTagFired; // 0x580        
        entity2::CEntityIOOutput m_OnAnimTagStart; // 0x5a8        
        entity2::CEntityIOOutput m_OnAnimTagEnd; // 0x5d0        
        entity2::CEntityIOOutput m_OnNavLinkStart; // 0x5f8        
        entity2::CEntityIOOutput m_OnNavLinkFinish; // 0x620        
        bool m_bIsTerminus; // 0x648        
        [[maybe_unused]] std::uint8_t pad_0x649[0x7];
        
        // Datamap fields:
        // void InputEnable; // 0x0
        // void InputDisable; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CNavLinkAreaEntity because it is not a standard-layout class
    static_assert(sizeof(CNavLinkAreaEntity) == 0x650);
};
