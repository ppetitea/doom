/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:57:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:23:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/texture.h"
#include "utils/color.h"
#include "utils/error.h"

static t_result	filter_color_with_circular_shadow(t_texture *text, t_vec2i i)
{
	t_bgra	color;
	t_vec2i	center;
	float	dist_px;
	float	dist_max;
	float	dist_pourcent;

	center = ft_vec2i(text->size.x * 0.5f, text->size.y * 0.5f);
	dist_max = (text->size.x * 0.5) * (text->size.x * 0.5)
				+ (text->size.y * 0.5) * (text->size.y * 0.5);
	dist_px = (i.x - center.x) * (i.x - center.x)
		+ (i.y - center.y) * (i.y - center.y);
	dist_pourcent = dist_px / dist_max;
	color.px = text->pixels[i.x + i.y * text->size.x];
	color.bgra.r *= 1 - dist_pourcent;
	color.bgra.g *= 1 - dist_pourcent;
	color.bgra.b *= 1 - dist_pourcent;
	text->pixels[i.x + i.y * text->size.x] = color.px;
	return (OK);
}

static t_result	filter_color_with_circular_blend(t_texture *text, t_vec2i i)
{
	t_bgra	color;
	t_vec2i	center;
	float	dist_px;
	float	dist_max;
	float	dist_pourcent;

	center = ft_vec2i(text->size.x * 0.5f, text->size.y * 0.5f);
	dist_max = (text->size.x * 0.5) * (text->size.x * 0.5)
				+ (text->size.y * 0.5) * (text->size.y * 0.5);
	dist_px = (i.x - center.x) * (i.x - center.x)
		+ (i.y - center.y) * (i.y - center.y);
	dist_pourcent = dist_px / dist_max;
	color.px = text->pixels[i.x + i.y * text->size.x];
	color.bgra.a *= 1 - dist_pourcent;
	text->pixels[i.x + i.y * text->size.x] = color.px;
	return (OK);
}

static t_result	filter_color_with_blend(t_texture *text, t_vec2i i)
{
	t_bgra	color;

	color.px = text->pixels[i.x + i.y * text->size.x];
	color.bgra.a = 150;
	text->pixels[i.x + i.y * text->size.x] = color.px;
	return (OK);
}

t_result	filter_texture(t_texture *text, t_filter_type filter)
{
	t_vec2i	i;

	if (text == NULL)
		return (throw_error("fill_texture_with_image", "NULL pointer"));
	while (i.y < text->size.y)
	{
		i.x = 0;
		while (i.x < text->size.x)
		{
			if (filter == FILTER_CIRCULAR_SHADOW)
				filter_color_with_circular_shadow(text, i);
			else if (filter == FILTER_CIRCULAR_BLEND)
				filter_color_with_circular_blend(text, i);
			else if (filter == FILTER_BLEND)
				filter_color_with_blend(text, i);
			i.x++;
		}
		i.y++;
	}
	return (OK);
}