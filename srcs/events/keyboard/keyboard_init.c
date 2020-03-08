/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 19:11:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 19:40:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/keyboard.h"
#include "utils/error.h"

t_result	init_keyboard_observable(t_keyboard_observable *self)
{
	if (self == NULL)
		return (throw_error("init_keyboard_observable", "NULL pointer"));
	init_list_head(&self->followers.down);
	init_list_head(&self->followers.up);
	self->state.w = FALSE;
	self->state.a = FALSE;
	self->state.s = FALSE;
	self->state.d = FALSE;
	self->state.key = -42;
	return (OK);
}

t_result	init_keyboard_observer(t_keyboard_observer *self)
{
	if (self == NULL)
		return (throw_error("init_observer", "NULL pointer provided"));
	init_list_head(&self->node);
	self->key = -42;
	self->list = NULL;
	self->subscribe = keyboard_observer_subscribe;
	self->unsubscribe = keyboard_observer_unsubscribe;
	self->subscribed = FALSE;
	init_list_head(&self->actions);
	return (OK);
}

t_result	set_keyboard_observer(t_keyboard_observer *self, t_list_head *list, 
				SDL_Keycode key, t_bool subscribe)
{
	if (self == NULL || list == NULL)
		return (throw_error("set_keyboard_observer", "NULL pointer provided"));
	self->key = key;
	self->list = list;
	if (subscribe && !self->subscribed)
		self->subscribe(self);
	else if (!subscribe && self->subscribed)
		self->unsubscribe(self);
	return (OK);
}
