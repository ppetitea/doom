/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:42:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 19:44:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "events/mouse.h"
#include "resources/game.h"
#include "utils/error.h"

#include <stdio.h>

void	handle_mouse_motion(t_game *game, SDL_MouseMotionEvent event)
{
	if (game == NULL)
		return (throw_void("handle_mouse_motion", "NULL pointer provided"));
	// game->events.mouse.pos = ft_vec2i(event.x, event.y);
	// if (game->events.mouse.down == TRUE &&
	// 	game->events.mouse.drag == FALSE)
	// {
	// 	game->events.mouse.drag = TRUE;
	// 	trigger_entities_by_drag(game);
	// }
	// else
	// 	trigger_entities_by_hover(game);
	(void)event;
	(void)game;
}

void	handle_mouse_down(t_game *game, SDL_MouseButtonEvent event)
{
	// game->events.mouse.down = TRUE;
	// game->events.mouse.pos = ft_vec2i(event.x, event.y);
	// if (!game->events.mouse.drag)
	// 	trigger_entities_by_select(game);
	(void)event;
	(void)game;
}

void	handle_mouse_up(t_game *game, SDL_MouseButtonEvent event)
{
	// game->events.mouse.pos = ft_vec2i(event.x, event.y);
	// if (game->events.mouse.drag)
	// 	trigger_entities_by_drop(game);
	// game->events.mouse.down = FALSE;
	// game->events.mouse.drag = FALSE;
	(void)event;
	(void)game;
}