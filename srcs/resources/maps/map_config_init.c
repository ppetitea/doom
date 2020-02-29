/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:03:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 12:18:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/map.h"
#include "utils/error.h"

t_result	init_map2d_config(t_map2d_config *self)
{
	if (self == NULL)
		return (throw_error("init_map2d_config", "NULL pointer provided"));
	self->display = FALSE;
	self->icon_size = ft_vec2i(32, 32);
	self->render_box.offset = ft_pos2i(0, 0);
	self->render_box.size = ft_vec2i(460, 320);
	return (OK);
}

t_result	init_map3d_config(t_map3d_config *self)
{
	if (self == NULL)
		return (throw_error("init_map3d_config", "NULL pointer provided"));
	self->display = FALSE;
	self->render_box.offset = ft_pos2i(0, 0);
	self->render_box.size = ft_vec2i(460, 320);
	// self->pre_render.columns_height = NULL;
	// self->pre_render.delta_dir = ft_vec2f(0, 1);
	// self->pre_render.index.min = 0;
	// self->pre_render.index.max = 100;
	// self->pre_render.slides = NULL;
	// self->pre_render.slides_amount = 0;
	return (OK);
}

t_result	init_map_config(t_map_config *self)
{
	if (self == NULL)
		return (throw_error("init_map_config", "NULL pointer provided"));
	init_map2d_config(&self->color);
	init_map2d_config(&self->drop);
	init_map2d_config(&self->height);
	init_map3d_config(&self->world3d);
	return (OK);
}
