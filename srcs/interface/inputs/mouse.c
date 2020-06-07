/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:57:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/05 18:54:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/events/event.h"
#include "interface/inputs/mouse.h"
#include "log/log.h"
#include <stdlib.h>

t_result init_mouse_state(t_mouse_state *self)
{
	self->x = 0;
	self->y = 0;
	self->wheel = 0.0f;
	self->velocity = ft_vec2f(0, 0);
	self->is_press = FALSE;
	self->is_move = FALSE;
	self->is_clic = FALSE;
	self->is_drag = FALSE;
	self->button = MOUSE_NONE;
	return (OK);
};

t_result del_mouse(t_mouse *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->mouse_up.destroy(&self->mouse_up);
	self->mouse_down.destroy(&self->mouse_down);
	self->mouse_motion.destroy(&self->mouse_motion);
	self->mouse_wheel.destroy(&self->mouse_wheel);
	self->events.destroy(&self->events);
	self->destroy = NULL;
	return (OK);
}

t_result del_new_mouse(t_mouse *self)
{
	if (!del_mouse(self))
		return (console(FATAL, __func__, __LINE__, "del_mouse fail").err);
	free(self);
	return (OK);
}

t_result init_mouse(t_mouse *self)
{
	if (!init_mouse_state(&self->last))
		return (console(FATAL, __func__, __LINE__, "init_mouse fail").err);
	if (!init_mouse_state(&self->curr))
		return (console(FATAL, __func__, __LINE__, "init_mouse fail").err);
	if (!init_event(&self->mouse_up))
		return (console(FATAL, __func__, __LINE__, "init_event fail").err);
	if (!init_event(&self->mouse_down))
		return (console(FATAL, __func__, __LINE__, "init_event fail").err);
	if (!init_event(&self->mouse_motion))
		return (console(FATAL, __func__, __LINE__, "init_event fail").err);
	if (!init_event(&self->mouse_wheel))
		return (console(FATAL, __func__, __LINE__, "init_event fail").err);
	if (!init_observable(&self->events))
		return (console(FATAL, __func__, __LINE__, "init_observable fail").err);
	self->destroy = del_mouse;
	return (OK);
};

t_mouse *init_new_mouse()
{
	t_mouse *self;

	if (!(self = malloc(sizeof(t_mouse))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_mouse(self);
	self->destroy = del_new_mouse;
	return (self);
}

t_result set_mouse_pos(t_mouse *self, int x, int y)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->curr.x = x;
	self->curr.y = y;
	return (OK);
};
