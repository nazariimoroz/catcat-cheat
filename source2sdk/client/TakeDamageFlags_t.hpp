#pragma once
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: client
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::client
{
    // Enumerator count: 45
    // Alignment: 8
    // Size: 0x8
    enum class TakeDamageFlags_t : std::uint64_t
    {
        DFLAG_NONE = 0x0,
        DFLAG_SUPPRESS_HEALTH_CHANGES = 0x1,
        DFLAG_SUPPRESS_PHYSICS_FORCE = 0x2,
        DFLAG_SUPPRESS_EFFECTS = 0x4,
        DFLAG_PREVENT_DEATH = 0x8,
        DFLAG_FORCE_DEATH = 0x10,
        DFLAG_ALWAYS_GIB = 0x20,
        DFLAG_NEVER_GIB = 0x40,
        DFLAG_REMOVE_NO_RAGDOLL = 0x80,
        DFLAG_SUPPRESS_DAMAGE_MODIFICATION = 0x100,
        DFLAG_ALWAYS_FIRE_DAMAGE_EVENTS = 0x200,
        DFLAG_RADIUS_DMG = 0x400,
        DFLAG_FORCEREDUCEARMOR_DMG = 0x800,
        DFLAG_SUPPRESS_INTERRUPT_FLINCH = 0x1000,
        // MPropertySuppressEnumerator
        // MEnumeratorIsNotAFlag
        DMG_LASTDFLAG = 0x1000,
        DFLAG_ALLOW_SUICIDE = 0x2000,
        DFLAG_BOUNTY_ALL_DIRECT = 0x4000,
        DFLAG_SUPPRESS_DIRECT_GOLD_BOUNTY = 0x8000,
        DFLAG_SUPPRESS_COINS_GOLD_BOUNTY = 0x10000,
        DFLAG_SUPPRESS_KILL_CREDIT = 0x20000,
        DFLAG_SUPPRESS_DEATH_CREDIT = 0x40000,
        DFLAG_SUPPRESS_AP_BOUNTY = 0x80000,
        DFLAG_SUPPRESS_DAMAGE_RECORD = 0x100000,
        DFLAG_SUPPRESS_DEATH_EVENT = 0x200000,
        DFLAG_MITIGATION_DUE_TO_NO_NEARBY_TROOPERS = 0x400000,
        DFLAG_TRIGGER_FLINCH = 0x800000,
        DFLAG_DO_NOT_BATCH_DAMAGE_NUMBER = 0x1000000,
        DFLAG_SUPPRESS_HIT_INDICATOR_SOUND = 0x2000000,
        DFLAG_DO_NOT_PROC = 0x4000000,
        DFLAG_RICOCHET = 0x8000000,
        DFLAG_PURE_DMG = 0x10000000,
        DFLAG_HEAVY_MELEE = 0x20000000,
        DFLAG_LIGHT_MELEE = 0x40000000,
        DFLAG_BONUS_DAMAGE = 0x80000000,
        DFLAG_KILL_CREATES_RAGDOLL = 0x100000000,
        DFLAG_IS_HEALTH_TRANSFER = 0x200000000,
        DFLAG_DO_NOT_RICOCHET = 0x400000000,
        DFLAG_NOT_IN_MIDBOSS_PIT = 0x800000000,
        DFLAG_NOT_IN_TIER3_PIT = 0x1000000000,
        DFLAG_DO_NOT_TRIGGER_DAMAGE_FLASH = 0x2000000000,
        DFLAG_TOO_FAR = 0x4000000000,
        DFLAG_DO_NOT_DISRUPT_HEALING_RITE = 0x8000000000,
        DFLAG_DO_NOT_HEADSHOT = 0x10000000000,
        DFLAG_TOO_LOW = 0x20000000000,
        DFLAG_DO_NOT_CRIT = 0x40000000000,
    };
};
