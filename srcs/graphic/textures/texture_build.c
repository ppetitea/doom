/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:55:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:33:02 by ppetitea         ###   ########.fr       */
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

t_texture	*build_new_texture(t_dnon_object *texture_obj)
{
	t_texture	*texture;
	t_bitmap	*image;
	t_vec2i		size;

	if (texture_obj == NULL)
		return (throw_null("build_new_texture", "NULL pointer provided"));
	if (!(image = get_image(texture_obj->key)))
		return (throw_null("build_new_texture", "Fail to get image"));
	size = get_vec2i(get_child_list(texture_obj, "size"), -1, -1);
	if (!(texture = init_new_texture(size)))
		return (throw_null("build_new_texture", "Fail to init_new_texture"));
	texture->delay_ms = get_int_value_by_key(texture_obj, "delay_ms", 100);
	texture->offset = get_vec2i(get_child_list(texture_obj, "size"), 0, 0);
	fill_texture_with_image(texture, image);
	if (strcmp_obj("filter", "circular_shadow", texture_obj))
		filter_texture(texture, FILTER_CIRCULAR_SHADOW);
	else if (strcmp_obj("filter", "circular_blend", texture_obj))
		filter_texture(texture, FILTER_CIRCULAR_BLEND);
	else if (strcmp_obj("filter", "blend", texture_obj))
		filter_texture(texture, FILTER_BLEND);
	return (texture);
}

t_result	build_textures(t_list_head *textures, t_dnon_object *textures_obj)
{
	t_list_head		*pos;
	t_dnon_object	*texture_obj;
	t_texture		*texture;

	if (textures == NULL || textures_obj == NULL)
		return (throw_error("build_textures", "NULL pointer provided"));
	pos = (t_list_head*)textures_obj->value;
	if (textures_obj->type != LIST)
		return (throw_error("build_textures", "texture_obj must be a list"));
	while ((pos = pos->next) != (t_list_head*)textures_obj->value)
	{
		texture_obj = (t_dnon_object*)pos;
		if ((texture = build_new_texture(texture_obj)))
			list_add_entry(&texture->node, textures);
	}
	return (OK);
}
