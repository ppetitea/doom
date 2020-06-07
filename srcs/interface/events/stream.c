/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:16:36 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/06 18:34:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/events/stream.h"
#include "interface/events/event_handler.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_stream_observer(t_stream_observer *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (self->subscribed)
		self->unsubscribe(&self->node);
	self->stream_ref = NULL;
	self->subscribe = NULL;
	self->unsubscribe = NULL;
	self->observer_ref = NULL;
	del_event_handler_list(&self->event_handlers);
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_stream_observer(t_stream_observer *self)
{
	if (!del_stream_observer(self))
		return (console(FATAL, __func__, __LINE__, "del_stream_observer fail").err);
	free(self);
	return (OK);
}

t_result del_stream_observer_list(t_list_head *list)
{
	t_list_head			*curr;
	t_list_head			*next;
	t_stream_observer	*stream_observer;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		stream_observer = (t_stream_observer*)curr;
		stream_observer->destroy(stream_observer);
	}
	return (OK);
}

t_result init_stream_observer(t_stream_observer *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->stream_ref = NULL;
	self->subscribed = FALSE;
	self->subscribe = list_add_entry;
	self->unsubscribe = list_del_entry;
	self->observer_ref = NULL;
	if (!init_list_head(&self->event_handlers))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->destroy = del_stream_observer;
	return (OK);
};

t_stream_observer *init_new_stream_observer()
{
	t_stream_observer *self;

	if (!(self = malloc(sizeof(t_stream_observer))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_stream_observer(self);
	self->destroy = del_new_stream_observer;
	return (self);
}

// t_result set_stream_observer(t_stream_observer *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_stream_observer *set_new_stream_observer()
// {
// 	t_stream_observer *self;

// 	if (!(self = init_new_stream_observer()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_stream_observer fail").null);
// 	if (!(set_stream_observer(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_stream_observer fail").null);
// 	return (self);
// }

t_result del_event_stream(t_event_stream *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (self->name)
		free(self->name);
	list_del_entry(&self->node);
	list_del_entry(&self->observers);
	return (OK);
}

t_result del_new_event_stream(t_event_stream *self)
{
	if (!del_event_stream(self))
		return (console(FATAL, __func__, __LINE__, "del_event_stream fail").err);
	free(self);
	return (OK);
}

t_result del_event_stream_list(t_list_head *list)
{
	t_list_head		*curr;
	t_list_head		*next;
	t_event_stream	*event_stream;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		event_stream = (t_event_stream*)curr;
		event_stream->destroy(event_stream);
	}
	return (OK);
}

t_result init_event_stream(t_event_stream *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->name = NULL;
	if (!init_list_head(&self->observers))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->destroy = del_event_stream;
	return (OK);
};

t_event_stream *init_new_event_stream()
{
	t_event_stream *self;

	if (!(self = malloc(sizeof(t_event_stream))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_event_stream(self);
	self->destroy = del_new_event_stream;
	return (self);
}

// t_result set_event_stream(t_event_stream *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_event_stream *set_new_event_stream()
// {
// 	t_event_stream *self;

// 	if (!(self = init_new_event_stream()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_event_stream fail").null);
// 	if (!(set_event_stream(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_event_stream fail").null);
// 	return (self);
// }





