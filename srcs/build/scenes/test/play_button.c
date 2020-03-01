/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:15:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 02:03:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "resources/button.h"
#include "graphic/texture.h"
#include "events/action.h"
#include "utils/error.h"
#include "ft/str.h"

#include <stdio.h>
t_result	debug_test(t_texture *texture)
{
	// printf("number %d\n", n);
	if (texture == NULL)
		return (throw_error("debug_test", "texture is NULL"));
	printf("texture width %d\n", ((t_texture*)texture)->size.x);
	printf("texture height %d\n", ((t_texture*)texture)->size.y);
	return (OK);
}

/*
	Create a button
		init_new_button
		add_textures
		add_actions
*/

t_result	add_play_button_textures(t_animation *anim,
				t_list_head *render_list)
{
	t_vec2i		size;

	size = ft_vec2i(350, 170);
	add_new_texture(&anim->textures, "skull_play_dark", size, FILTER_NONE);
	add_new_texture(&anim->textures, "skull_play_light", size, FILTER_NONE);
	if (list_lenght(&anim->textures) == 0)
		return (throw_error("add_play_button", "Texture list is empty"));
	anim->curr = (t_texture*)anim->textures.next;
	anim->box.anchor = ft_vec2i(720, 520);
	update_animation_render_box(anim);
	anim->list = render_list;
	anim->subscribe(anim);
	return (OK);
}

t_result	add_play_button_collide(t_animation *anim,
				t_mouse_followers *followers)
{
	t_list_head	*action_list;

	update_animation_collide_lists(anim, followers);
	anim->collide.select.suscribe(&anim->collide.select);
	action_list = &anim->collide.select.start_actions;
	add_new_action(action_list, debug_test, (t_arg)(void*)anim->curr);
	return (OK);
}

t_result	add_play_button(t_list_head *buttons, t_list_head *render_list,
				t_mouse_followers *followers)
{
	t_button	*button;

	if (!(button = init_new_button()))
		return (throw_error("add_play_button", "init_new_button failed"));
	if (!(button->name = ft_strdup("test_play")))
		return (throw_error("add_play_button", "ft_strdup failed"));
	if (!add_play_button_textures(&button->animation, render_list))
		return (throw_error("add_play_button", "add_textures failed"));
	if (!add_play_button_collide(&button->animation, followers))
		return (throw_error("add_play_button", "add_collides failed"));
	list_add_entry(&button->node, buttons);
	return (OK);
}
