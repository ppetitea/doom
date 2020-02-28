/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:55:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 18:19:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/texture.h"
#include "utils/error.h"

t_result	copy_texture_list(t_list_head *dest, t_list_head *src)
{
	t_texture		*texture_src;
	t_texture		*texture_dest;
	t_list_head		*pos;

	if (dest == NULL || src == NULL)
		return (throw_error("copy_texture_list", "NULL pointer provided"));
	pos = src;
	while ((pos = pos->next) != src)
	{
		texture_src = (t_texture*)pos;
		if ((texture_dest = init_new_texture()))
		{
			texture_dest->size = texture_src->size;
			texture_dest->offset = texture_src->offset;
			texture_dest->pixels = texture_src->pixels;
			texture_dest->delay_ms = texture_src->delay_ms;
		}
	}
	return (OK);
}
