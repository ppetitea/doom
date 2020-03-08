/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:42:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 14:59:38 by ppetitea         ###   ########.fr       */
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
	mouse->state.pos = ft_vec2i(event.x, event.y);
	trigger_mouse_observers(&mouse->followers.motion);
	if (mouse->state.drag)
		return ;
	else if (mouse->state.down)
	{
		mouse->state.drag = TRUE;
		trigger_mouse_obs_on(&mouse->followers.drag, mouse->state);
	}
	else
	{
		trigger_mouse_obs_off(&mouse->followers.hover_end, mouse->state);
		trigger_mouse_obs_on(&mouse->followers.hover_start, mouse->state);
	}
}

void	handle_mouse_down(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	mouse->state.down = TRUE;
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (event.button == SDL_BUTTON_LEFT)
		trigger_mouse_obs_on(&mouse->followers.left_down, mouse->state);
	else if (event.button == SDL_BUTTON_RIGHT)
		trigger_mouse_obs_on(&mouse->followers.right_down, mouse->state);
}

void	handle_mouse_up(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (mouse->state.drag)
	{
		trigger_mouse_observers(&mouse->followers.drop);
	}
	else if (mouse->state.down && event.button == SDL_BUTTON_LEFT)
		trigger_mouse_obs_on(&mouse->followers.left_up, mouse->state);
	else if (mouse->state.down && event.button == SDL_BUTTON_RIGHT)
		trigger_mouse_obs_on(&mouse->followers.right_up, mouse->state);
	mouse->state.down = FALSE;
	mouse->state.drag = FALSE;
}

void	handle_mouse_wheel(t_mouse_observable *mouse,
			SDL_MouseWheelEvent event)
{
	if (event.y > 0)
		trigger_mouse_observers(&mouse->followers.wheel_normal);
	else if (event.y < 0)
		trigger_mouse_observers(&mouse->followers.wheel_flip);
	(void)mouse;
}

/* 
	Handle mouse in game

	mouse down -> fire
	mouse motion -> move camera
	

 */