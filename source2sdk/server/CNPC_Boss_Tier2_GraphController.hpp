#pragma once
#include "source2sdk/server/CAI_CitadelNPC_GraphController.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    // Registered alignment: unknown
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0xb38
    // Has VTable
    #pragma pack(push, 1)
    class CNPC_Boss_Tier2_GraphController : public server::CAI_CitadelNPC_GraphController
    {
    public:
        // m_pszActivity has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CAnimGraphParamRef<char*> m_pszActivity;
        char m_pszActivity[0x28]; // 0xa48        
        // m_pszStompAttack has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CAnimGraphParamRef<char*> m_pszStompAttack;
        char m_pszStompAttack[0x28]; // 0xa70        
        // m_pszStaggerDirection has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CAnimGraphParamRef<char*> m_pszStaggerDirection;
        char m_pszStaggerDirection[0x28]; // 0xa98        
        // m_pszElectricBeamPosition has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CAnimGraphParamRef<char*> m_pszElectricBeamPosition;
        char m_pszElectricBeamPosition[0x28]; // 0xac0        
        CAnimGraphTagRef m_sStaggered; // 0xae8        
        CAnimGraphTagRef m_sStomp; // 0xb00        
        [[maybe_unused]] std::uint8_t pad_0xb18[0x8]; // 0xb18
        CAnimGraphTagRef m_sApplyStompDamage; // 0xb20        
        
        // Static fields:
        static uint32_t &Get_s_nControllerTypeID() {return *reinterpret_cast<uint32_t*>(interfaces::g_schema->FindTypeScopeForModule("!GlobalTypes")->FindDeclaredClass("CNPC_Boss_Tier2_GraphController")->GetStaticFields()[0]->m_pInstance);};
        static bool &Get_s_bSchemaTest() {return *reinterpret_cast<bool*>(interfaces::g_schema->FindTypeScopeForModule("!GlobalTypes")->FindDeclaredClass("CNPC_Boss_Tier2_GraphController")->GetStaticFields()[1]->m_pInstance);};
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CNPC_Boss_Tier2_GraphController because it is not a standard-layout class
    static_assert(sizeof(CNPC_Boss_Tier2_GraphController) == 0xb38);
};
