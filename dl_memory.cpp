#include "dl_memory.h"

#include "global_t.h"
#include "source2sdk/client/CBodyComponent.hpp"
#include "source2sdk/client/CGameSceneNode.hpp"
#include "source2sdk/client/CItemXP.hpp"
#include "source2sdk/client/CSkeletonInstance.hpp"
#include "source2sdk/entity2/CEntityIdentity.hpp"

std::tuple<std::vector<player_t>, size_t, std::vector<orb_t>> dl_memory_t::get_all_entities(
    uintptr_t entity_list_sys_ptr)
{
    std::vector<player_t> players;
    size_t index_of_local_player = 0;
    std::vector<orb_t> orbs;

    ex::var<uint32_t> ex_list_size = entity_list_sys_ptr + 0x1534;
    global_t::list_size = *ex_list_size;

    int list_itter = 0;
    for (int i = 0; list_itter < global_t::list_size; ++i)
    {
        ex::var<uintptr_t> ex_entity_list_ptr = entity_list_sys_ptr + 8LL * ((i & 0x7FFF) >> 9) + 16;

        player_t player{};
        ex::var<uintptr_t> ex_entity_inst_address
            = (*ex_entity_list_ptr) + 0x78 * (i & 0x1FF);

        if (*ex_entity_inst_address == 0)
            continue;

        list_itter += 1;

        std::string design_name = get_entity_design_name(*ex_entity_inst_address);
        //if(design_name.empty())
        //    std::cout << design_name << std::endl;
        if (design_name == "citadel_player_controller")
        {
            ex::var<source2sdk::client::CCitadelPlayerController> ex_controller{
                *ex_entity_inst_address,
                std::make_tuple(
                    &source2sdk::client::CCitadelPlayerController::m_iTeamNum,
                    &source2sdk::client::CCitadelPlayerController::m_hPawn,
                    &source2sdk::client::CCitadelPlayerController::m_bIsLocalPlayerController
                )
            };

            player.ex_controller = std::move(ex_controller);

            int32_t pawn_index = *(int32_t*)player.ex_controller->m_hPawn;
            uintptr_t pawns_entity_list_sys_ptr
                = entity_list_sys_ptr + (0x8 * ((pawn_index & 0x7FFF) >> 0x9) + 0x10);
            ex::var<uintptr_t> ex_pawns_entity_list_ptr = pawns_entity_list_sys_ptr;

            if (*ex_pawns_entity_list_ptr == 0)
                continue;

            uintptr_t pawn_ptr_ptr = (*ex_pawns_entity_list_ptr) + 0x78 * (pawn_index & 0x1FF);
            if (pawn_ptr_ptr == 0)
                continue;

            ex::var<uintptr_t> ex_pawn_ptr = pawn_ptr_ptr;
            if (*ex_pawn_ptr == 0)
                continue;

            player.ex_pawn = ex::var<source2sdk::client::C_CitadelPlayerPawn>{
                *ex_pawn_ptr,
                std::make_tuple(
                    &source2sdk::client::C_CitadelPlayerPawn::m_CBodyComponent,
                    &source2sdk::client::C_CitadelPlayerPawn::m_pEntity,
                    &source2sdk::client::C_CitadelPlayerPawn::m_iHealth,
                    &source2sdk::client::C_CitadelPlayerPawn::m_iMaxHealth,
                    &source2sdk::client::C_CitadelPlayerPawn::m_flMouseSensitivity,
                    &source2sdk::client::C_CitadelPlayerPawn::m_pGameSceneNode,
                    &source2sdk::client::C_CitadelPlayerPawn::m_lifeState
                )
            };

            // getting hero name
            {
                if (player.ex_pawn->m_pEntity == nullptr)
                    continue;
                ex::var pawn_entity{
                    player.ex_pawn->m_pEntity, std::make_tuple(
                        &source2sdk::entity2::CEntityIdentity::m_name)
                };

                ex::var<ex::str_t> pawn_name = EX_BYTES_TO_PTR(pawn_entity->m_name);
                player.hero_name = c_heroname_to_realname(pawn_name->str()).c_str();
            }

            // getting current position
            {
                if (player.ex_pawn->m_CBodyComponent == nullptr)
                    continue;
                ex::var bc{
                    player.ex_pawn->m_CBodyComponent, std::make_tuple(
                        &source2sdk::client::CBodyComponent::m_pSceneNode
                    )
                };

                if (bc->m_pSceneNode == nullptr)
                    continue;
                ex::var scene_node{
                    bc->m_pSceneNode, std::make_tuple(
                        &source2sdk::client::CGameSceneNode::m_nodeToWorld
                    )
                };

                player.world_pos.x = *((float*)scene_node->m_nodeToWorld);
                player.world_pos.y = *((float*)scene_node->m_nodeToWorld + 1);
                player.world_pos.z = *((float*)scene_node->m_nodeToWorld + 2);
            }

            // getting head bone
            do
            {
                const auto bi_iter = realname_to_head_bone_map.find(player.hero_name);
                if (bi_iter == realname_to_head_bone_map.end())
                {
                    player.head_pos = player.world_pos;
                    player.head_pos.z += 92.f;
                    break;
                }
                const auto bi_ex_index = bi_iter->second;

                ex::var<source2sdk::client::CSkeletonInstance> ex_gsn{
                    (uintptr_t)player.ex_pawn->m_pGameSceneNode,
                    std::make_tuple(
                        &source2sdk::client::CSkeletonInstance::m_modelState
                    )
                };

                uintptr_t bone_array_address = ex_gsn->m_modelState.m_bone_array;

                uintptr_t bone_address = bone_array_address
                    + sizeof(bone_t) * bi_ex_index;

                ex::var<bone_t> ex_bone{bone_address};
                player.head_pos = ex_bone.get()->position;
            }
            while (false);

            if (player.ex_controller->m_bIsLocalPlayerController)
            {
                index_of_local_player = players.size();
            }

            players.push_back(std::move(player));
        }

        if (design_name == "item_xp")
        {
            ex::var<source2sdk::client::CItemXP> ex_orb_entity{
                *ex_entity_inst_address,
                std::make_tuple(
                    &source2sdk::client::CItemXP::m_pGameSceneNode
                )
            };

            if(!ex_orb_entity->m_pGameSceneNode)
                continue;

            ex::var ex_gs_node {
                ex_orb_entity->m_pGameSceneNode,
                std::make_tuple(
                    &source2sdk::client::CGameSceneNode::m_vecOrigin,
                    &source2sdk::client::CGameSceneNode::m_bDormant
                )
            };

            xyz_t* pos = (xyz_t*)ex_gs_node->m_vecOrigin.pad_0x00;
            bool visible = ex_gs_node->m_bDormant;

            orb_t orb {
                .ex_orb = std::move(ex_orb_entity),
                .position = *pos,
                .visible = visible };

            orbs.push_back(std::move(orb));
        }
    }
    std::cout << std::endl;

    return {players, index_of_local_player, orbs};
}

std::string dl_memory_t::get_entity_design_name(uintptr_t entity_address)
{
    ex::var<source2sdk::entity2::CEntityInstance> ex_entity_inst{
        entity_address, std::make_tuple(
            &source2sdk::entity2::CEntityInstance::m_pEntity
        )
    };

    ex::var ex_entity = ex_entity_inst->m_pEntity;
    const auto designer_name_ptr = *(uintptr_t*)ex_entity->m_designerName;
    if (!designer_name_ptr)
        return "";

    ex::var<ex::str_t> designer_name = designer_name_ptr;
    return designer_name->str();
}
