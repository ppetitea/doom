/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:20:46 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 19:07:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphic/texture.h"
#include "containers/list.h"
#include "utils/error.h"

t_result	init_texture(t_texture *self)
{
	if (self == NULL)
		return (throw_error("init_texture", "NULL pointer provided"));
	init_list_head(&self->node);
	self->offset = ft_vec2i(0, 0);
	self->size = ft_vec2i(1, 1);
	self->pixels = NULL;
	self->delay_ms = 100;
	return (OK);
}

t_texture	*init_new_texture(t_vec2i size)
{
	t_texture	*self;

	if (size.x < 1 || 4096 < size.x || size.y < 1 || 4096 < size.y)
		return (throw_null("init_new_texture", "size < 1 || size > 4096"));
	if (!(self = malloc(sizeof(t_texture))))
		return (throw_null("init_new_texture", "malloc failed"));
	if (!init_texture(self))
		return (throw_null("init_new_texture", "init_texture failed"));
	self->size = size;
	if (!(self->pixels = malloc(sizeof(t_u32) * self->size.x * self->size.y)))
		return (throw_null("init_new_texture", "malloc failed"));
	return (self);
}
