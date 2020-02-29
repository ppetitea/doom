/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:23:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 16:09:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "interface/screen.h"
#include "utils/error.h"
#include "utils/color.h"

// #include <stdio.h>

void		render_texture(t_screen *screen, t_texture *text,
				t_render_box box)
{
	t_rgba		curr;
	t_u32		*px;
	t_vec2i		i;
	
	i.y = box.start.y;
	while (box.offset.y + i.y < box.end.y)
	{
		i.x = box.start.x;
		while (box.offset.x + i.x < box.end.x)
		{
			curr.px = text->pixels[(int)(i.x * box.scale.x + (i.y * box.scale.y)
				* text->size.x)];
			px = &screen->pixels[box.offset.x + i.x + (i.y + box.offset.y)
				* screen->size.x];
			*px = blend_add(curr, (t_rgba)*px);
			++i.x;
		}
		++i.y;
	}
}

t_result	render_animation(t_screen *screen, t_animation *anim)
{
	t_render_box	box;

	box.offset = anim->box.render_box.offset;
	box.size = anim->box.render_box.size;
	box.start.x = (box.offset.x < 0) ? -box.offset.x : 0;
	box.start.y = (box.offset.y < 0) ? -box.offset.y : 0;
	box.end = vec2i_add(box.offset, box.size);
	if (box.end.x >= (int)screen->size.x)
		box.end.x = (int)screen->size.x;
	if (box.end.y >= (int)screen->size.y)
		box.end.y = (int)screen->size.y;
	box.scale.x = (float)anim->curr->size.x / (float)box.size.x;
	box.scale.y = (float)anim->curr->size.y / (float)box.size.y;
	render_texture(screen, anim->curr, box);
	return (OK);
}

t_result	render_scene(t_scene *scene)
{
	t_list_head	*pos;
	t_animation	*anim;
	t_screen	*screen;

	if (scene == NULL)
		return (throw_error("render_scene", "NULL pointer provided"));
	if (!(screen = get_screen()))
		return (throw_error("render_scene", "Screen not found"));
	pos = &scene->gui.render_list;
	while ((pos = pos->next) != &scene->gui.render_list)
	{
		anim = (t_animation*)pos;
		if (anim->curr)
			render_animation(screen, anim);
	}
	return (OK);
}