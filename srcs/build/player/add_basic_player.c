/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_basic_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:44:21 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/09 18:26:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/map.h"
#include "resources/player.h"
#include "utils/error.h"
#include "events/action.h"

#include <stdio.h>

// hurt
t_result	play_hurt_song(t_player *player)
{
	printf("Aie j'ai mal: play song\n");
	(void)player;
	return (OK);
}

t_result	active_hurt_texture(t_player *player)
{
	printf("Aie j'ai mal: active texture\n");
	player->curr->unsubscribe(player->curr);
	player->curr = &player->state.hurt;
	player->state.hurt.subscribe(&player->state.hurt);
	return (OK);
}

t_result	add_basic_player_hurt(t_player *player, t_list_head *render_list3d)
{
	t_animation *anim;
	t_vec2i		size;
	t_screen	*screen;
	t_list_head	*action_list;

	size = ft_vec2i(350, 170);
	anim = &player->state.hurt;
	anim->list = render_list3d;
	add_new_texture(anim->textures, "player_die1", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die2", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die3", size, FILTER_NONE);
	if (list_lenght(anim->textures) == 0)
		return (throw_error("add_basic_player_hurt", "Texture list is empty"));
	anim->curr = (t_texture*)anim->textures->next;
	anim->box.anchor = ft_vec2i(540, 720);
	if ((screen= get_screen()))
		anim->box.anchor = ft_vec2i(screen->size.x * 0.5, screen->size.y);
	update_animation_render_box(anim);
	// hurt actions
	action_list = &player->state.actions_hurt;
	add_new_action(action_list, play_hurt_song, (t_arg)(void*)player);
	add_new_action(action_list, active_hurt_texture, (t_arg)(void*)player);
	return (OK);
}

// heal
t_result	play_heal_song(t_player *player)
{
	printf("Ouf je suis soins: play song\n");
	(void)player;
	return (OK);
}

t_result	active_heal_texture(t_player *player)
{
	printf("Ouf je suis soins: active texture\n");
	player->curr->unsubscribe(player->curr);
	player->curr = &player->state.heal;
	player->state.heal.subscribe(&player->state.heal);
	return (OK);
}
t_result	add_basic_player_heal(t_player *player, t_list_head *render_list3d)
{
	t_animation *anim;
	t_vec2i		size;
	t_screen	*screen;
	t_list_head	*action_list;

	size = ft_vec2i(350, 170);
	anim = &player->state.heal;
	anim->list = render_list3d;
	add_new_texture(anim->textures, "player_heal1", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_heal2", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_heal3", size, FILTER_NONE);
	if (list_lenght(anim->textures) == 0)
		return (throw_error("add_basic_player_heal", "Texture list is empty"));
	anim->curr = (t_texture*)anim->textures->next;
	anim->box.anchor = ft_vec2i(540, 720);
	if ((screen= get_screen()))
		anim->box.anchor = ft_vec2i(screen->size.x * 0.5, screen->size.y);
	update_animation_render_box(anim);
	// heal actions
	action_list = &player->state.actions_heal;
	add_new_action(action_list, play_heal_song, (t_arg)(void*)player);
	add_new_action(action_list, active_heal_texture, (t_arg)(void*)player);
	return (OK);
}

//die
t_result	play_die_song(t_player *player)
{
	printf("Argh je me meurs: play song\n");
	(void)player;
	return (OK);
}

t_result	active_die_texture(t_player *player)
{
	printf("Argh je me meurs: active texture\n");
	player->curr->unsubscribe(player->curr);
	player->curr = &player->state.die;
	player->state.die.subscribe(&player->state.die);
	return (OK);
}
t_result	add_basic_player_die(t_player *player, t_list_head *render_list3d)
{
	t_animation *anim;
	t_vec2i		size;
	t_screen	*screen;
	t_list_head	*action_list;

	size = ft_vec2i(350, 170);
	anim = &player->state.die;
	anim->list = render_list3d;
	add_new_texture(anim->textures, "player_die1", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die2", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die3", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die4", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die5", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die6", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die7", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die8", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die9", size, FILTER_NONE);
	add_new_texture(anim->textures, "player_die10", size, FILTER_NONE);
	if (list_lenght(anim->textures) == 0)
		return (throw_error("add_basic_player_die", "Texture list is empty"));
	anim->curr = (t_texture*)anim->textures->next;
	anim->box.anchor = ft_vec2i(540, 720);
	if ((screen= get_screen()))
		anim->box.anchor = ft_vec2i(screen->size.x * 0.5, screen->size.y);
	update_animation_render_box(anim);
	// die actions
	action_list = &player->state.actions_die;
	add_new_action(action_list, play_die_song, (t_arg)(void*)player);
	add_new_action(action_list, active_die_texture, (t_arg)(void*)player);
	return (OK);
}

t_result	add_basic_player(t_map *map)
{
	t_player	*player;

	player = &map->sprites.player;
	add_basic_player_hurt(player, &map->sprites.render_list3d);
	add_basic_player_heal(player, &map->sprites.render_list3d);
	add_basic_player_die(player, &map->sprites.render_list3d);
	return (OK);
}
