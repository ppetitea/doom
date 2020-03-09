/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_basic_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:44:21 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/09 16:06:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/map.h"
#include "resources/player.h"
#include "utils/error.h"

t_result	add_basic_player_hurt(t_destructible *state,
				t_list_head *render_list3d)
{
	t_animation *anim;
	t_vec2i		size;
	t_screen	*screen;

	size = ft_vec2i(350, 170);
	anim = &state->hurt;
	add_new_texture(anim->textures, "skull_play_dark", size, FILTER_NONE);
	if (list_lenght(anim->textures) == 0)
		return (throw_error("add_basic_player_hurt", "Texture list is empty"));
	anim->curr = (t_texture*)anim->textures->next;
	anim->box.anchor = ft_vec2i(540, 720);
	update_animation_render_box(anim);
	anim->list = render_list3d;
	state->actions_hurt
	add_new_action(state->actions_hurt, hurt_player, (t_arg)(void*)anim->curr);
	return (OK);
}

t_result	add_basic_player(t_map *map)
{
	t_player	*player;

	
	player = &map->sprites.player;
	
	return (OK);
}
