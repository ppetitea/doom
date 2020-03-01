/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:42:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 14:26:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "events/mouse.h"
#include "events/observer.h"
#include "utils/error.h"

#include <stdio.h>

void	handle_mouse_motion(t_mouse_observable *mouse,
			SDL_MouseMotionEvent event)
{
	if (mouse->state.drag)
		return ;
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (mouse->state.down)
	{
		mouse->state.drag = TRUE;
		trigger_mouse_collide_on(&mouse->followers.drag, mouse->state);
	}
	else
	{
		trigger_mouse_collide_off(&mouse->followers.hover_stop, mouse->state);
		trigger_mouse_collide_on(&mouse->followers.hover_start, mouse->state);
	}
}

void	handle_mouse_down(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	mouse->state.down = TRUE;
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (mouse->state.mode == POINTER_GAME)
	{
		// Shoot ennemies
		(void)mouse;
	}
}

void	handle_mouse_up(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	if (mouse->state.down == FALSE)
		return ;
	mouse->state.down = FALSE;
	mouse->state.drag = FALSE;
	if (mouse->state.pos.x == event.x && mouse->state.pos.y == event.y)
	{
		if (mouse->state.mode == POINTER_SELECT)
			trigger_mouse_collide_on(&mouse->followers.select, mouse->state);
	}
	else
	{
		if (mouse->state.mode == POINTER_SELECT)
			trigger_mouse_observers(&mouse->followers.drop);
	}
	(void)event;
	(void)mouse;
}
