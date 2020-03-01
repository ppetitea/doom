/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observable_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:24:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 14:10:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "utils/error.h"

t_result	init_mouse_observable(t_mouse_observable *self)
{
	if (self == NULL)
		return (throw_error("init_mouse_observable", "NULL pointer"));
	init_list_head(&self->followers.hover_start);
	init_list_head(&self->followers.hover_stop);
	init_list_head(&self->followers.select);
	init_list_head(&self->followers.drag);
	init_list_head(&self->followers.drop);
	init_list_head(&self->followers.motion);
	self->state.drag = FALSE;
	self->state.down = FALSE;
	self->state.hover = FALSE;
	self->state.pos = ft_vec2i(0, 0);
	self->state.mode = POINTER_SELECT;
	return (OK);
}

t_result	init_keyboard_observable(t_keyboard_observable *self)
{
	if (self == NULL)
		return (throw_error("init_keyboard_observable", "NULL pointer"));
	// init_list_head(&self->followers.hover);
	// init_list_head(&self->followers.select);
	// init_list_head(&self->followers.drag);
	// init_list_head(&self->followers.draw);
	// self->state.drag = FALSE;
	// self->state.down = FALSE;
	// self->state.pos = ft_vec2i(0, 0);
	// self->state.mode = POINTER_SELECT;
	return (OK);
}
