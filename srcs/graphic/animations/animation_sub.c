/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:32:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 14:18:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"

t_result	animation_subscribe(t_animation *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("animation_sub", "NULL pointer provided"));
	if (self->subscribed == FALSE)
	{
		self->subscribed = TRUE;
		list_add_entry(&self->node, self->list);
	}
	return (OK);
}

t_result	animation_unsubscribe(t_animation *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("animation_unsub", "NULL pointer provided"));
	if (self->subscribed == TRUE)
	{
		self->subscribed = FALSE;
		list_del_entry(&self->node);
	}
	return (OK);
}