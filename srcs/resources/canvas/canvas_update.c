/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:01:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 12:59:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/map.h"
#include "resources/canvas.h"
#include "utils/error.h"

t_result	set_animation_as_current_color_map(t_animation *anim)
{
	t_map	*map;

	if (!(map = get_current_map()))
		return (throw_error("render_canvas", "Current map not found"));
	if (anim->textures != map->context.color.textures &&
		list_lenght(map->context.color.textures) > 0)
	{
		anim->textures = map->context.color.textures;
		anim->curr = (t_texture*)anim->textures->next;
	}
	return (OK);
}

t_result	set_animation_as_current_height_map(t_animation *anim)
{
	t_map	*map;

	if (!(map = get_current_map()))
		return (throw_error("render_canvas", "Current map not found"));
	if (anim->textures != map->context.height.textures &&
		list_lenght(map->context.height.textures) > 0)
	{
		anim->textures = map->context.height.textures;
		anim->curr = (t_texture*)anim->textures->next;
	}
	return (OK);
}

t_result	render_map3d_on_canvas(t_animation *anim)
{
	t_map	*map;

	if (!(map = get_current_map()))
		return (throw_error("render_canvas", "Current map not found"));
	(void)anim;
	return (OK);
}
