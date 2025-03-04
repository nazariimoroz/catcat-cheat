#pragma once
#include "source2sdk/entity2/CEntityIOOutput.hpp"
#include "source2sdk/entity2/GameTime_t.hpp"
#include "source2sdk/server/CBaseModelEntity.hpp"
#include "source2sdk/server/TrainOrientationType_t.hpp"
#include "source2sdk/server/TrainVelocityType_t.hpp"
#include "source2sdk/source2gen.hpp"
#include <cstddef>
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: server
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::server
{
    class CPathTrack;
};

namespace source2sdk::server
{
    // Registered alignment: 0x8
    // Alignment: 0x8
    // Standard-layout class: false
    // Size: 0x910
    // Has VTable
    #pragma pack(push, 1)
    class CFuncTrackTrain : public server::CBaseModelEntity
    {
    public:
        // m_ppath has a template type with potentially unknown template parameters. You can try uncommenting the field below.
        // CHandle<server::CPathTrack> m_ppath;
        char m_ppath[0x4]; // 0x7c0        
        float m_length; // 0x7c4        
        Vector m_vPosPrev; // 0x7c8        
        QAngle m_angPrev; // 0x7d4        
        Vector m_controlMins; // 0x7e0        
        Vector m_controlMaxs; // 0x7ec        
        Vector m_lastBlockPos; // 0x7f8        
        int32_t m_lastBlockTick; // 0x804        
        float m_flVolume; // 0x808        
        float m_flBank; // 0x80c        
        float m_oldSpeed; // 0x810        
        float m_flBlockDamage; // 0x814        
        float m_height; // 0x818        
        float m_maxSpeed; // 0x81c        
        float m_dir; // 0x820        
        [[maybe_unused]] std::uint8_t pad_0x824[0x4]; // 0x824
        CUtlSymbolLarge m_iszSoundMove; // 0x828        
        CUtlSymbolLarge m_iszSoundMovePing; // 0x830        
        CUtlSymbolLarge m_iszSoundStart; // 0x838        
        CUtlSymbolLarge m_iszSoundStop; // 0x840        
        CUtlSymbolLarge m_strPathTarget; // 0x848        
        float m_flMoveSoundMinDuration; // 0x850        
        float m_flMoveSoundMaxDuration; // 0x854        
        entity2::GameTime_t m_flNextMoveSoundTime; // 0x858        
        float m_flMoveSoundMinPitch; // 0x85c        
        float m_flMoveSoundMaxPitch; // 0x860        
        server::TrainOrientationType_t m_eOrientationType; // 0x864        
        server::TrainVelocityType_t m_eVelocityType; // 0x868        
        [[maybe_unused]] std::uint8_t pad_0x86c[0xc]; // 0x86c
        entity2::CEntityIOOutput m_OnStart; // 0x878        
        entity2::CEntityIOOutput m_OnNext; // 0x8a0        
        entity2::CEntityIOOutput m_OnArrivedAtDestinationNode; // 0x8c8        
        bool m_bManualSpeedChanges; // 0x8f0        
        [[maybe_unused]] std::uint8_t pad_0x8f1[0x3]; // 0x8f1
        float m_flDesiredSpeed; // 0x8f4        
        entity2::GameTime_t m_flSpeedChangeTime; // 0x8f8        
        float m_flAccelSpeed; // 0x8fc        
        float m_flDecelSpeed; // 0x900        
        bool m_bAccelToSpeed; // 0x904        
        [[maybe_unused]] std::uint8_t pad_0x905[0x3]; // 0x905
        entity2::GameTime_t m_flNextMPSoundTime; // 0x908        
        [[maybe_unused]] std::uint8_t pad_0x90c[0x4];
        
        // Datamap fields:
        // int64_t m_soundMoveGuid; // 0x86c
        // void InputStop; // 0x0
        // void InputStartForward; // 0x0
        // void InputStartBackward; // 0x0
        // void InputToggle; // 0x0
        // void InputResume; // 0x0
        // void InputReverse; // 0x0
        // float InputSetSpeed; // 0x0
        // float InputSetSpeedDir; // 0x0
        // float InputSetSpeedReal; // 0x0
        // float InputSetMaxSpeed; // 0x0
        // float InputSetSpeedDirAccel; // 0x0
        // CUtlSymbolLarge InputMoveToPathNode; // 0x0
        // CUtlSymbolLarge InputTeleportToPathNode; // 0x0
        // void InputLockOrientation; // 0x0
        // void InputUnlockOrientation; // 0x0
        // void CFuncTrackTrainNext; // 0x0
        // void CFuncTrackTrainFind; // 0x0
        // void CFuncTrackTrainNearestPath; // 0x0
        // void CFuncTrackTrainDeadEnd; // 0x0
        // int32_t volume; // 0x7fffffff
    };
    #pragma pack(pop)
    
    // Cannot assert offsets of fields in CFuncTrackTrain because it is not a standard-layout class
    static_assert(sizeof(CFuncTrackTrain) == 0x910);
};
