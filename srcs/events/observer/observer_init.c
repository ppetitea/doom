/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:03:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:37:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "utils/time.h"
#include "utils/error.h"

t_result	init_observer(t_observer *self)
{
	if (self == NULL)
		return (throw_error("init_observer", "NULL pointer provided"));
	init_list_head(&self->node);
	self->list = NULL;
	self->subscribe = observer_subscribe;
	self->unsubscribe = observer_unsubscribe;
	self->subscribed = FALSE;
	init_list_head(&self->actions);
	return (OK);
}

t_result	set_observer(t_observer *self, t_list_head *list, t_bool subscribe)
{
	if (self == NULL || list == NULL)
		return (throw_error("set_observer", "NULL pointer provided"));
	self->list = list;
	if (subscribe && !self->subscribed)
		self->subscribe(self);
	else if (!subscribe && self->subscribed)
		self->unsubscribe(self);
	return (OK);
}

t_result	init_time_observer(t_time_observer *self)
{
	if (self == NULL)
		return (throw_error("init_time_observer", "NULL pointer provided"));
	init_list_head(&self->node);
	self->seconds = get_wall_time();
	self->list = NULL;
	self->subscribe = time_observer_subscribe;
	self->unsubscribe = time_observer_unsubscribe;
	self->subscribed = FALSE;
	init_list_head(&self->actions);
	return (OK);
}

t_result	set_time_observer(t_time_observer *self, t_list_head *list, t_bool subscribe,
				double seconds)
{
	if (self == NULL || list == NULL)
		return (throw_error("set_time_observer", "NULL pointer provided"));
	self->list = list;
	self->seconds += seconds;
	if (subscribe && !self->subscribed)
		self->subscribe(self);
	else if (!subscribe && self->subscribed)
		self->unsubscribe(self);
	return (OK);
}

