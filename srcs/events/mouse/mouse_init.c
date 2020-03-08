/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 19:11:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 19:15:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/mouse.h"
#include "utils/error.h"

t_result	init_mouse_observable(t_mouse_observable *self)
{
	if (self == NULL)
		return (throw_error("init_mouse_observable", "NULL pointer"));
	init_list_head(&self->followers.hover_start);
	init_list_head(&self->followers.hover_end);
	init_list_head(&self->followers.right_up);
	init_list_head(&self->followers.right_down);
	init_list_head(&self->followers.left_up);
	init_list_head(&self->followers.left_down);
	init_list_head(&self->followers.drag);
	init_list_head(&self->followers.drop);
	init_list_head(&self->followers.motion);
	init_list_head(&self->followers.wheel_normal);
	init_list_head(&self->followers.wheel_flip);
	self->state.drag = FALSE;
	self->state.down = FALSE;
	self->state.hover = FALSE;
	self->state.pos = ft_vec2i(0, 0);
	self->state.mode = POINTER_SELECT;
	return (OK);
}

t_result	init_mouse_observer(t_mouse_observer *self)
{
	if (self == NULL)
		return (throw_error("init_observer", "NULL pointer provided"));
	init_list_head(&self->node);
	self->render_box = NULL;
	self->list = NULL;
	self->subscribe = mouse_observer_subscribe;
	self->unsubscribe = mouse_observer_unsubscribe;
	self->subscribed = FALSE;
	init_list_head(&self->actions);
	return (OK);
}
