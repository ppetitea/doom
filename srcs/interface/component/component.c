/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:01:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/08 15:09:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/component.h"
#include "interface/events/stream.h"
#include "interface/events/event_handler.h"
#include "log/log.h"
#include <stdlib.h>

t_result component_foreach_prev(t_component *self,
	t_result (*fn)(t_component *))
{
	t_node		*curr;
	t_node		*prev;
	t_component	*component;

	if (self == NULL)
		return (ERROR);
	curr = self->node.childs;
	prev = curr->prev;
	if (self->node.childs)
	{
		while ((curr = prev) != self->node.childs)
		{
			prev = prev->prev;
			component = (t_component*)curr;
			node_foreach_prev(component, fn);
			fn(component);
		}
	}
	return (OK);
}

t_result destroy_component(t_component *self)
{
	self->destroy(self);
	return (OK);
}

t_result del_component(t_component *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	component_foreach_prev(self, destroy_component);
	if (self->id)
		free(self->id);
	del_args_list(&self->radio);
	self->font = NULL; // SDL_FREE ?
	self->text_surface = NULL; // SDL_FREE ?
	self->layer.destroy(&self->layer);
	self->last.destroy(&self->last);
	self->curr.destroy(&self->curr);
	self->up_to_date = FALSE;
	del_component_observer_list(&self->state_observers);
	del_stream_observer_list(&self->stream_observers);
	del_event_handler_list(&self->e_propagation_handlers);
	self->events.destroy(&self->events);
	del_node(&self->node);
	self->destroy = NULL;
	return (OK);
}

t_result del_new_component(t_component *self)
{
	if (!del_component(self))
		return (console(FATAL, __func__, __LINE__, "del_component fail").err);
	free(self);
	return (OK);
}

t_result init_component(t_component *self)
{
	if (!init_list(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->id = NULL;
	init_list_head(&self->radio);
	self->font = NULL;
	self->text_surface = NULL;
	if (!init_layer(&self->layer))
		return (console(FATAL, __func__, __LINE__, "init_layer fail").err);
	if (!init_component_state(&self->last))
		return (console(FATAL, __func__, __LINE__, "init_cpt_state fail").err);
	if (!init_component_state(&self->curr))
		return (console(FATAL, __func__, __LINE__, "init_cpt_state fail").err);
	self->up_to_date = FALSE;
	if (!init_list_head(&self->state_observers))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->stream_observers))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->e_propagation_handlers))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!(init_observable(&self->events)))
		return (console(FATAL, __func__, __LINE__, "init_observable fail").err);
	self->destroy = del_component;
	return (OK);
};

t_component *init_new_component()
{
	t_component *self;

	if (!(self = malloc(sizeof(t_component))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_component(self);
	self->destroy = del_new_component;
	return (self);
}

// t_result set_component(t_component *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_component *set_new_component()
// {
// 	t_component *self;

// 	if (!(self = init_new_component()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_component fail").null);
// 	if (!(set_component(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_component fail").null);
// 	return (self);
// }

