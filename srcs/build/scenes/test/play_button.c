/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:15:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:24:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "resources/button.h"
#include "events/mouse.h"
#include "graphic/texture.h"
#include "events/action.h"
#include "utils/error.h"
#include "ft/str.h"

/*
	actions functions
*/
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
	play_button
*/

t_result	add_play_button_textures(t_animation *anim,
				t_list_head *render_list)
{
	t_vec2i		size;

	size = ft_vec2i(350, 170);
	add_new_texture(anim->textures, "skull_play_dark", size, FILTER_NONE);
	add_new_texture(anim->textures, "skull_play_light", size, FILTER_NONE);
	if (list_lenght(anim->textures) == 0)
		return (throw_error("add_play_button", "Texture list is empty"));
	anim->curr = (t_texture*)anim->textures->next;
	anim->box.anchor = ft_vec2i(720, 520);
	update_animation_render_box(anim);
	anim->list = render_list;
	anim->subscribe(anim);
	return (OK);
}

t_result	add_play_button_mouse_observer(t_animation *anim,
				t_mouse_followers *followers)
{
	t_list_head	*action_list;

	update_mouse_observers_lists(&anim->mouse_obs, followers);

	// clic
	anim->mouse_obs.left_up.subscribe(&anim->mouse_obs.left_up);
	action_list = &anim->mouse_obs.left_up.actions;
	add_new_action(action_list, debug_test, (t_arg)(void*)anim->curr);

	// hover
	anim->mouse_obs.hover_start.subscribe(&anim->mouse_obs.hover_start);
	action_list = &anim->mouse_obs.hover_start.actions;
	add_new_action(action_list, animation_hover_start, (t_arg)(void*)anim);
	add_new_action(action_list, animation_wheel_start, (t_arg)(void*)anim);
	add_new_action(action_list, texture_next, (t_arg)(void*)anim);
	action_list = &anim->mouse_obs.hover_end.actions;
	add_new_action(action_list, animation_hover_end, (t_arg)(void*)anim);
	add_new_action(action_list, animation_wheel_end, (t_arg)(void*)anim);
	add_new_action(action_list, reset_animation, (t_arg)(void*)anim);

	// drag & drop
	anim->mouse_obs.drag.subscribe(&anim->mouse_obs.drag);
	action_list = &anim->mouse_obs.drag.actions;
	add_new_action(action_list, animation_drag_start, (t_arg)(void*)anim);
	add_new_action(action_list, set_mouse_as_anchor, (t_arg)(void*)anim);
	action_list = &anim->mouse_obs.motion.actions;
	add_new_action(action_list, transform_anim_on_mouse, (t_arg)(void*)anim);
	action_list = &anim->mouse_obs.drop.actions;
	add_new_action(action_list, animation_drag_end, (t_arg)(void*)anim);

	// mouse wheel
	action_list = &anim->mouse_obs.wheel_normal.actions;
	add_new_action(action_list, increase_scale_animation, (t_arg)(void*)anim);
	action_list = &anim->mouse_obs.wheel_flip.actions;
	add_new_action(action_list, decrease_scale_animation, (t_arg)(void*)anim);
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
	if (!add_play_button_mouse_observer(&button->animation, followers))
		return (throw_error("add_play_button", "add_mouse_obss failed"));
	list_add_entry(&button->node, buttons);
	return (OK);
}
