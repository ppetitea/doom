/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:20:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 17:20:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/texture.h"
#include "interface/screen.h"
#include "utils/color.h"

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
