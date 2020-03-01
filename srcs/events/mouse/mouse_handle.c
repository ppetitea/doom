/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:42:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 02:39:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "events/mouse.h"
#include "resources/game.h"
#include "utils/error.h"
#include "events/action.h"

#include <stdio.h>

t_bool	is_mouse_collide_with_box(t_box *box, t_mouse mouse)
{
	t_vec2i	start;
	t_vec2i	end;

	start = box->offset;
	end.x = box->offset.x + box->size.x;
	end.y = box->offset.y + box->size.y;
	if (start.x <= mouse.pos.x && mouse.pos.x < end.x &&
		start.y <= mouse.pos.y && mouse.pos.y < end.y)
		return (TRUE);
	return (FALSE);
}

void	trigger_mouse_observers(t_list_head *observers, t_mouse mouse,
			t_bool start)
{
	t_mouse_observer	*observer;
	t_list_head			*pos;

	pos = observers;
	while ((pos = pos->next) != observers)
	{
		observer = (t_mouse_observer*)pos;
		if (is_mouse_collide_with_box(observer->render_box, mouse))
		{
			if (start)
				trigger_actions(&observer->start_actions);
			else
				trigger_actions(&observer->stop_actions);
		}
	}
}

void	handle_mouse_motion(t_mouse_observable *mouse,
			SDL_MouseMotionEvent event)
{
	if (mouse->state.drag)
		return ;
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (mouse->state.down && mouse->state.mode == POINTER_SELECT)
	{
		mouse->state.drag = TRUE;
		trigger_mouse_observers(&mouse->followers.drag, mouse->state, TRUE);
	}
	else if (!mouse->state.down && mouse->state.mode == POINTER_SELECT)
		trigger_mouse_observers(&mouse->followers.hover, mouse->state, TRUE);
	else
		throw_error("handle_mouse_motion", "UNKNOW pointer mode detected");
}

void	handle_mouse_down(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	mouse->state.down = TRUE;
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (mouse->state.mode == POINTER_SELECT && !mouse->state.drag)
		trigger_mouse_observers(&mouse->followers.select, mouse->state, TRUE);
	else if (mouse->state.mode == POINTER_DRAW)
		trigger_mouse_observers(&mouse->followers.draw, mouse->state, TRUE);
	else if (mouse->state.mode == POINTER_GAME)
		(void)mouse;
	else
		throw_error("handle_mouse_down", "UNKNOW pointer mode detected");
}

void	handle_mouse_up(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	// game->events.mouse.pos = ft_vec2i(event.x, event.y);
	// if (game->events.mouse.drag)
	// 	trigger_entities_by_drop(game);
	// game->events.mouse.down = FALSE;
	// game->events.mouse.drag = FALSE;
	(void)event;
	(void)mouse;
}