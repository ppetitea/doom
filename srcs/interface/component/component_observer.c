/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_observer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:11:21 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/07 17:42:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/component.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_component_observer(t_component_observer *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->fn = NULL;
	del_args_list(&self->args);
	self->destroy = NULL;
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_component_observer(t_component_observer *self)
{
	if (!del_component_observer(self))
		return (console(FATAL, __func__, __LINE__, "del_cpt_obs fail").err);
	free(self);
	return (OK);
}

t_result del_component_observer_list(t_list_head *list)
{
	t_list_head				*curr;
	t_list_head				*next;
	t_component_observer	*component_observer;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		component_observer = (t_component_observer*)curr;
		component_observer->destroy(component_observer);
	}
	return (OK);
}

t_result init_component_observer(t_component_observer *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->fn = NULL;
	if (!init_list_head(&self->args))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->destroy = del_component_observer;
	return (OK);
};

t_component_observer *init_new_component_observer()
{
	t_component_observer *self;

	if (!(self = malloc(sizeof(t_component_observer))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_component_observer(self);
	self->destroy = del_new_component_observer;
	return (self);
}

// t_result set_component_observer(t_component_observer *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_component_observer *set_new_component_observer()
// {
// 	t_component_observer *self;

// 	if (!(self = init_new_component_observer()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_component_observer fail").null);
// 	if (!(set_component_observer(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_component_observer fail").null);
// 	return (self);
// }

