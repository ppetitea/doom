/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:55:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/09 14:26:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/images.h"
#include "graphic/texture.h"
#include "utils/error.h"
#include "utils/parser.h"
#include "utils/color.h"

static t_result	fill_texture_with_image(t_texture *text, t_bitmap *image)
{
	t_vec2f	scale;
	t_bgra	color;
	t_vec2i	i;
	t_vec2i	j;

	if (text == NULL || image == NULL)
		return (throw_error("fill_texture_with_image", "NULL pointer"));
	scale.x = (float)image->head.width / (float)text->size.x;
	scale.y = (float)image->head.height / (float)text->size.y;
	i.y = 0;
	while (i.y < text->size.y)
	{
		i.x = 0;
		while (i.x < text->size.x)
		{
			j = ft_vec2i(i.x * scale.x, i.y * scale.y);
			color.px = image->pixels[j.x + j.y * image->head.width];
			text->pixels[i.x + i.y * text->size.x] = color.px;
			i.x++;
		}
		i.y++;
	}
	return (OK);
}

t_texture	*add_new_texture(t_list_head *textures, char *name,
				t_vec2i size, t_filter_type filter)
{
	t_texture	*texture;
	t_bitmap	*image;

	if (textures == NULL || name == NULL)
		return (throw_null("add_new_texture", "NULL pointer provided"));
	if (size.x < 1 && 4096 < size.x && size.y < 1 && 4096 < size.y)
		return (throw_null("add_new_texture", "Wrong size detected"));
	if (!(image = get_image(name)))
		return (throw_null("add_new_texture", "Fail to get image"));
	if (!(texture = init_new_texture_with_size(size)))
		return (throw_null("build_new_texture", "Fail to init_new_texture"));
	fill_texture_with_image(texture, image);
	filter_texture(texture, filter);
	list_add_entry(&texture->node, textures);
	return (texture);
}
