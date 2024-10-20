#pragma once
#include <cstdint>

// /////////////////////////////////////////////////////////////
// Module: modellib
// Created using source2gen - github.com/neverlosecc/source2gen
// /////////////////////////////////////////////////////////////

namespace source2sdk::modellib
{
    // Enumerator count: 8
    // Alignment: 4
    // Size: 0x4
    enum class MeshDrawPrimitiveFlags_t : std::uint32_t
    {
        MESH_DRAW_FLAGS_NONE = 0x0,
        MESH_DRAW_FLAGS_USE_SHADOW_FAST_PATH = 0x1,
        MESH_DRAW_FLAGS_USE_COMPRESSED_NORMAL_TANGENT = 0x2,
        MESH_DRAW_INPUT_LAYOUT_IS_NOT_MATCHED_TO_MATERIAL = 0x8,
        MESH_DRAW_FLAGS_USE_COMPRESSED_PER_VERTEX_LIGHTING = 0x10,
        MESH_DRAW_FLAGS_USE_UNCOMPRESSED_PER_VERTEX_LIGHTING = 0x20,
        MESH_DRAW_FLAGS_CAN_BATCH_WITH_DYNAMIC_SHADER_CONSTANTS = 0x40,
        MESH_DRAW_FLAGS_DRAW_LAST = 0x80,
    };
};
