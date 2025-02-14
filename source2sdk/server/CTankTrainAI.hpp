#pragma once
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
    class CBaseEntity;
};

namespace source2sdk::server
{
    class CFuncTrackTrain;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x528
    // Has VTable
    #pragma pack(push, 1)
    class CTankTrainAI : public server::CPointEntity
    {
    public:
        // m_hTrain has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CFuncTrackTrain> m_hTrain;
        char m_hTrain[0x4]; // 0x4e8        
        // m_hTargetEntity has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CBaseEntity> m_hTargetEntity;
        char m_hTargetEntity[0x4]; // 0x4ec        
        int32_t m_soundPlaying; // 0x4f0        
        [[maybe_unused]] std::uint8_t pad_0x4f4[0x14]; // 0x4f4
        CUtlSymbolLarge m_startSoundName; // 0x508        
        CUtlSymbolLarge m_engineSoundName; // 0x510        
        CUtlSymbolLarge m_movementSoundName; // 0x518        
        CUtlSymbolLarge m_targetEntityName; // 0x520        
        
        // Datamap fields:
        // void m_soundTreads; // 0x4f8
        // void m_soundEngine; // 0x500
        // CUtlSymbolLarge InputTargetEntity; // 0x0
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CTankTrainAI because it is not a standard-layout class
    static_assert(sizeof(CTankTrainAI) == 0x528);
};
