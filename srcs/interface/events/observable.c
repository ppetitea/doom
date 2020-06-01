/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:42:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/01 11:44:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/events/observable.h"
#include "interface/events/event.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_observable(t_observable *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->type = OBSERVABLE_NONE;
	if (self->subscribed && self->unsubscribe)
		self->unsubscribe(&self->node);
	self->observable_ref = NULL;
	self->observables_ref = NULL;
	self->subscribe = NULL;
	self->unsubscribe = NULL;
	del_event_list(&self->queu);
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_observable(t_observable *self)
{
	if (!del_observable(self))
		return (console(FATAL, __func__, __LINE__, "del_observable fail").err);
	free(self);
	return (OK);
}

t_result del_observable_list(t_list_head *list)
{
	t_list_head		*curr;
	t_list_head		*next;
	t_observable	*observable;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		observable = (t_observable*)curr;
		observable->destroy(observable);
	}
	return (OK);
}

t_result init_observable(t_observable *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->type = OBSERVABLE_NONE;
	self->observable_ref = NULL;
	self->observables_ref = NULL;
	self->subscribed = FALSE;
	self->subscribe = list_add_entry;
	self->unsubscribe = list_del_entry;
	if (!init_list_head(&self->queu))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->destroy = del_observable;
	return (OK);
}

t_observable *init_new_observable()
{
	t_observable *self;

	if (!(self = malloc(sizeof(t_observable))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_observable(self);
	self->destroy = del_new_observable;
	return (self);
}

t_result set_observable(t_observable *self, t_observable_type type,
	void *observable_ref)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->type = type;
	self->observable_ref = observable_ref;
	return (OK);
};

t_observable *set_new_observable(t_observable_type type, void *observable_ref)
{
	t_observable *self;

	if (!(self = init_new_observable()))
		return (console(FATAL, __func__, __LINE__, "init_new_observable fail").null);
	if (!(set_observable(self, type, observable_ref)))
		return (console(FATAL, __func__, __LINE__, "set_observable fail").null);
	return (self);
}

