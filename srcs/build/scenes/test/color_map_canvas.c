/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map_canvas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:15:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 13:12:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "resources/canvas.h"
#include "graphic/texture.h"
#include "events/action.h"
#include "utils/error.h"
#include "ft/str.h"

/*
	actions functions
*/
#include <stdio.h>

t_result	test_canvas(t_texture *texture)
{
	// printf("number %d\n", n);
	if (texture == NULL)
		return (throw_error("test_canvas", "texture is NULL"));
	printf("texture width %d\n", ((t_texture*)texture)->size.x);
	printf("texture height %d\n", ((t_texture*)texture)->size.y);
	return (OK);
}

/*
	play_canvas
*/
t_result	add_color_map_canvas_textures(t_animation *anim,
				t_list_head *render_list)
{
	t_vec2i		size;

	size = ft_vec2i(350, 170);
	anim->update = set_animation_as_current_color_map;
	if (!anim->update(anim))
		return (throw_error("add_color_map_canvas_textures", "Update failed"));
	anim->box.anchor = ft_vec2i(100, 100);
	anim->box.render_box.size = size;
	update_animation_render_box(anim);
	anim->list = render_list;
	anim->subscribe(anim);
	return (OK);
}

t_result	add_color_map_canvas_mouse_observer(t_animation *anim,
				t_mouse_followers *followers)
{
	t_list_head	*action_list;

	update_mouse_observers_lists(&anim->mouse_obs, followers);

	// clic
	anim->mouse_obs.left_up.subscribe(&anim->mouse_obs.left_up);
	action_list = &anim->mouse_obs.left_up.actions;
	add_new_action(action_list, test_canvas, (t_arg)(void*)anim->curr);

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

t_result	add_color_map_canvas(t_list_head *canvas_list,
				t_list_head *render_list, t_mouse_followers *followers)
{
	t_canvas	*canvas;

	if (!(canvas = init_new_canvas()))
		return (throw_error("add_color_map_canvas", "init_new_canvas failed"));
	if (!(canvas->name = ft_strdup("color_map_canvas")))
		return (throw_error("add_color_map_canvas", "ft_strdup failed"));
	if (!add_color_map_canvas_textures(&canvas->anim, render_list))
		return (throw_error("add_color_map_canvas", "add_textures failed"));
	if (!add_color_map_canvas_mouse_observer(&canvas->anim, followers))
		return (throw_error("add_color_map_canvas", "add_mouse_obss failed"));
	list_add_entry(&canvas->node, canvas_list);
	return (OK);
}
