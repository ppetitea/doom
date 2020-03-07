/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:56:24 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 16:39:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/map.h"
#include "utils/error.h"

t_result	init_map_context(t_map_context *self)
{
	if (!init_new_animation(&self->color))
		return (throw_error("init_map_context", "init_new_animation failed"));
	if (!init_new_animation(&self->height))
		return (throw_error("init_map_context", "init_new_animation failed"));
	if (!init_new_animation(&self->sky))
		return (throw_error("init_map_context", "init_new_animation failed"));
	return (OK);
}

t_result	init_map_sprites(t_map_sprites *self)
{
	init_player(&self->player);
	init_list_head(&self->mobs);
	init_list_head(&self->objects);
	init_list_head(&self->destructibles);
	init_list_head(&self->icons);
}

t_map	*init_new_map()
{
	t_map	*self;

	if (!(self = malloc(sizeof(t_map*))))
		return (throw_null("init_new_map", "malloc failed"));
	init_list_head(&self->node);
	init_map_context(&self->context);
	init_map_sprites(&self->sprites);
	self->name = NULL;
	return (self);
}
