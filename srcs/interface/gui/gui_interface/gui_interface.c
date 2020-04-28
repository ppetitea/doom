/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 15:00:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/26 14:09:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "log/log.h"
#include <stdlib.h>

t_result init_gui_interface(t_gui_interface *self)
{
	if (!init_node(&self->scenes))
		return (console(FATAL, __func__, __LINE__, "init_node fail").err);
	self->curr_scene = NULL;
	init_list_head(&self->images);
	init_list_head(&self->songs);
	self->mouse_pos = ft_vec2i(0, 0);
	self->mouse_ishover = FALSE;
	self->mouse_isdown = FALSE;
	self->mouse_isdrag = FALSE;
	init_list_head(&self->mouse_hover_start);
	init_list_head(&self->mouse_hover_end);
	init_list_head(&self->mouse_left_up);
	init_list_head(&self->mouse_left_down);
	init_list_head(&self->mouse_right_up);
	init_list_head(&self->mouse_right_down);
	init_list_head(&self->mouse_drag);
	init_list_head(&self->mouse_drop);
	init_list_head(&self->mouse_motion);
	init_list_head(&self->mouse_wheel_normal);
	init_list_head(&self->mouse_wheel_flip);
	init_list_head(&self->key_up);
	init_list_head(&self->key_down);
	init_list_head(&self->time);
	self->is_running = TRUE;
	return (OK);
};

t_gui_interface *init_new_gui_interface()
{
	t_gui_interface *self;

	if (!(self = malloc(sizeof(t_gui_interface))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_gui_interface(self);
	return (self);
}

t_result del_gui_interface(t_gui_interface *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	return (OK);
}
