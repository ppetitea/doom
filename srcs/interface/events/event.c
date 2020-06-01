#include "interface/events/event.h"
#include "interface/events/stream.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_event(t_event *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (self->name)
		free(self->name);
	self->observable_ref = NULL;
	del_arg_list(&self->args);
	del_arg_list(&self->streams);
	self->destroy = NULL;
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_event(t_event *self)
{
	if (!del_event(self))
		return (console(FATAL, __func__, __LINE__, "del_event fail").err);
	free(self);
	return (OK);
}

t_result del_event_list(t_list_head *list)
{
	t_list_head	*curr;
	t_list_head	*next;
	t_event		*event;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		event = (t_event*)curr;
		event->destroy(event);
	}
	return (OK);
}

t_result init_event(t_event *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->args))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->streams))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->name = NULL;
	self->observable_ref = NULL;
	self->destroy = del_event;
	return (OK);
};

t_event *init_new_event()
{
	t_event *self;

	if (!(self = malloc(sizeof(t_event))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	if (!init_event(self))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	self->destroy = del_new_event;
	return (self);
}

t_result	add_event_arg(t_event *event, t_arg_type type, t_argv value)
{
	t_arg_list	*stream_arg;

	if (!(stream_arg = set_new_arg_list(type, value)))
		return (console(FATAL, __func__, __LINE__, "set_new_arg fail").err);
	list_add_entry(&stream_arg->node, &event->args);
	return (OK);
}

t_result	add_event_stream(t_event *event, char *stream)
{
	t_arg_list	*stream_arg;

	if (!(stream_arg = set_new_arg_list(ARG_STRING, (t_argv)stream)))
		return (console(FATAL, __func__, __LINE__, "set_new_arg fail").err);
	list_add_entry(&stream_arg->node, &event->streams);
	return (OK);
}

t_result	add_event_stream2(t_event *event, char *stream1, char *stream2)
{
	if (!add_event_stream(event, stream1))
		return (console(FATAL, __func__, __LINE__, "add_e_stream fail").err);
	if (!add_event_stream(event, stream2))
		return (console(FATAL, __func__, __LINE__, "add_e_stream fail").err);
	return (OK);
}

t_result	add_event_stream3(t_event *event, char *stream1, char *stream2,
	char *stream3)
{
	if (!add_event_stream(event, stream1))
		return (console(FATAL, __func__, __LINE__, "add_e_stream fail").err);
	if (!add_event_stream(event, stream2))
		return (console(FATAL, __func__, __LINE__, "add_e_stream fail").err);
	if (!add_event_stream(event, stream3))
		return (console(FATAL, __func__, __LINE__, "add_e_stream fail").err);
	return (OK);
}

t_result set_event(t_event *self, char *name, void *observable_ref,
	char *stream)
{
	if (!self || !name || !observable_ref || !stream)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (!add_event_stream(self, stream))
		return (console(FATAL, __func__, __LINE__, "add_e_stream fail").err);
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->name = ft_strdup(name);
	self->observable_ref = observable_ref;
	return (OK);
};

t_event *set_new_event(char *name, void *observable_ref, char *stream)
{
	t_event *self;

	if (!(self = init_new_event()))
		return (console(FATAL, __func__, __LINE__, "init_new_event fail").null);
	if (!(set_event(self, name, observable_ref, stream)))
		return (console(FATAL, __func__, __LINE__, "set_event fail").null);
	return (self);
}
