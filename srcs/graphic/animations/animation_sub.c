/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:32:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 12:40:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"

t_result	animation_subscribe(t_animation *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("animation_subscription", "NULL pointer provided"));
	if (self->suscribed == FALSE)
	{
		self->suscribed = TRUE;
		list_add_entry(&self->node, self->list);
	}
	return (OK);
}

t_result	animation_unsubscribe(t_animation *self)
{
	if (self == NULL || self->list == NULL)
		return (throw_error("animation_subscription", "NULL pointer provided"));
	if (self->suscribed == TRUE)
	{
		self->suscribed = FALSE;
		list_del_entry(&self->node);
	}
	return (OK);
}