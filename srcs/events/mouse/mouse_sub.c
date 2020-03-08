/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:03:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 19:26:48 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/mouse.h"
#include "utils/error.h"

t_result	mouse_observer_subscribe(t_mouse_observer *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("mouse_observer_sub", "NULL pointer provided"));
	if (self->subscribed == FALSE)
	{
		self->subscribed = TRUE;
		list_add_entry(&self->node, self->list);
	}
	return (OK);
}

t_result	mouse_observer_unsubscribe(t_mouse_observer *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("mouse_observer_unsub", "NULL pointer provided"));
	if (self->subscribed == TRUE)
	{
		self->subscribed = FALSE;
		list_del_entry(&self->node);
	}
	return (OK);
}
