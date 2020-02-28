/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:03:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 18:23:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "utils/error.h"

t_result	init_mouse_observer(t_mouse_observer *self)
{
	if (self == NULL)
		return (throw_error("init_observer", "NULL pointer provided"));
	init_list_head(&self->node);
	self->render_box = NULL;
	self->list = NULL;
	self->suscribe = mouse_observer_subscribe;
	self->unsuscribe = mouse_observer_unsubscribe;
	self->suscribed = FALSE;
	self->active = FALSE;
	init_list_head(&self->start_actions);
	init_list_head(&self->stop_actions);
	return (OK);
}
