#pragma once
#include "source2sdk/client/CBaseAnimGraphAnimGraphController.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: client
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::client
{
    // Registered alignment: unknown
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x118
    // Has VTable
    #pragma pack(push, 1)
    class C_PortraitWorldUnit_GraphController : public client::CBaseAnimGraphAnimGraphController
    {
    public:
        // m_pszHeroUI has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CAnimGraphParamOptionalRef<char*> m_pszHeroUI;
        char m_pszHeroUI[0x28]; // 0xc8        
        // m_pszShopUI has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CAnimGraphParamOptionalRef<char*> m_pszShopUI;
        char m_pszShopUI[0x28]; // 0xf0        
        
        // Static fields:
        static uint32_t &Get_s_nControllerTypeID() {return *reinterpret_cast<uint32_t*>(interfaces::g_schema->FindTypeScopeForModule("!GlobalTypes")->FindDeclaredClass("C_PortraitWorldUnit_GraphController")->GetStaticFields()[0]->m_pInstance);};
        static bool &Get_s_bSchemaTest() {return *reinterpret_cast<bool*>(interfaces::g_schema->FindTypeScopeForModule("!GlobalTypes")->FindDeclaredClass("C_PortraitWorldUnit_GraphController")->GetStaticFields()[1]->m_pInstance);};
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in C_PortraitWorldUnit_GraphController because it is not a standard-layout class
    static_assert(sizeof(C_PortraitWorldUnit_GraphController) == 0x118);
};
