/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:30:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/06 18:34:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/events/event_handler.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_condition(t_condition *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	del_args_list(&self->args);
	self->fn = NULL;
	self->destroy = NULL;
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_condition(t_condition *self)
{
	if (!del_condition(self))
		return (console(FATAL, __func__, __LINE__, "del_condition fail").err);
	free(self);
	return (OK);
}

t_result del_condition_list(t_list_head *list)
{
	t_list_head		*curr;
	t_list_head		*next;
	t_arg_list		*condition;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		condition = (t_condition*)curr;
		condition->destroy(condition);
	}
	return (OK);
}

t_result init_condition(t_condition *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->args))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->fn = NULL;
	self->destroy = del_condition;
	return (OK);
};

t_condition *init_new_condition()
{
	t_condition *self;

	if (!(self = malloc(sizeof(t_condition))))
		return (console(FATAL, __func__, __LINE__, "malloc fail").null);
	init_condition(self);
	self->destroy = del_new_condition;
	return (self);
}

// t_result set_condition(t_condition *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_condition *set_new_condition()
// {
// 	t_condition *self;

// 	if (!(self = init_new_condition()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_condition fail").null);
// 	if (!(set_condition(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_condition fail").null);
// 	return (self);
// }

t_result del_event_handler(t_event_handler *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->fn = NULL;
	del_args_list(&self->args);
	del_condition_list(&self->conditions);
	self->destroy = NULL;	
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_event_handler(t_event_handler *self)
{
	if (!del_event_handler(self))
		return (console(FATAL, __func__, __LINE__, "del_event_handler fail").err);
	free(self);
	return (OK);
}

t_result del_event_handler_list(t_list_head *list)
{
	t_list_head		*curr;
	t_list_head		*next;
	t_event_handler	*event_handler;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		event_handler = (t_event_handler*)curr;
		event_handler->destroy(event_handler);
	}
	return (OK);
}

t_result init_event_handler(t_event_handler *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->args))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->conditions))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->fn = NULL;
	self->destroy = del_event_handler;
	return (OK);
};

t_event_handler *init_new_event_handler()
{
	t_event_handler *self;

	if (!(self = malloc(sizeof(t_event_handler))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_event_handler(self);
	self->destroy = del_new_event_handler;
	return (self);
}

// t_result set_event_handler(t_event_handler *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_event_handler *set_new_event_handler()
// {
// 	t_event_handler *self;

// 	if (!(self = init_new_event_handler()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_event_handler fail").null);
// 	if (!(set_event_handler(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_event_handler fail").null);
// 	return (self);
// }

