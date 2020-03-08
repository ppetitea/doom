/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:03:48 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:59:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "utils/error.h"

t_result	observer_subscribe(t_observer *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("observer_sub", "NULL pointer provided"));
	if (self->subscribed == FALSE)
	{
		self->subscribed = TRUE;
		list_add_entry(&self->node, self->list);
	}
	return (OK);
}

t_result	observer_unsubscribe(t_observer *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("observer_unsub", "NULL pointer provided"));
	if (self->subscribed == TRUE)
	{
		self->subscribed = FALSE;
		list_del_entry(&self->node);
	}
	return (OK);
}

t_result	time_observer_subscribe(t_time_observer *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("time_observer_sub", "NULL pointer provided"));
	if (self->subscribed == FALSE)
	{
		self->subscribed = TRUE;
		list_add_entry(&self->node, self->list);
	}
	return (OK);
}

t_result	time_observer_unsubscribe(t_time_observer *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("time_observer_unsub", "NULL pointer provided"));
	if (self->subscribed == TRUE)
	{
		self->subscribed = FALSE;
		list_del_entry(&self->node);
	}
	return (OK);
}
