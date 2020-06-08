/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:48:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/08 15:09:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/interface.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_interface(t_interface *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	del_scene_list(&self->scenes);
	self->curr = NULL;
	self->mouse.destroy(&self->mouse);
	self->keys.destroy(&self->keys);
	del_observable_list(&self->observables);
	del_stream_list(&self->streams);
	del_stream_observer_list(&self->stream_observers);
	return (OK);
}

t_result del_new_interface(t_interface *self)
{
	if (!del_interface(self))
		return (console(FATAL, __func__, __LINE__, "del_interface fail").err);
	free(self);
	return (OK);
}

t_result init_interface(t_interface *self)
{
	if (!init_list_head(&self->scenes))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->curr = NULL;
	if (!init_mouse(&self->mouse))
		return (console(FATAL, __func__, __LINE__, "init_mouse fail").err);
	if (!init_keys(&self->keys))
		return (console(FATAL, __func__, __LINE__, "init_keys fail").err);
	if (!init_observable(&self->events))
		return (console(FATAL, __func__, __LINE__, "init_observable fail").err);
	if (!init_list_head(&self->observables))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->streams))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->stream_observers))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->destroy = del_interface;
	return (OK);
};

t_interface *init_new_interface()
{
	t_interface *self;

	if (!(self = malloc(sizeof(t_interface))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_interface(self);
	self->destroy = del_new_interface;
	return (self);
}


// t_result set_interface(t_interface *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self -
// 		return (OK);
// };

// t_interface *set_new_interface()
// {
// 	t_interface *self;

// 	if (!(self = init_new_interface()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_interface fail").null);
// 	if (!(set_interface(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_interface fail").null);
// 	return (self);
// }

