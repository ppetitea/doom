/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:13:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 17:23:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/mouse.h"
#include "events/observer.h"
#include "events/keyboard.h"
#include "resources/game.h"

#include <stdio.h>

void	handle_events(t_game *game)
{
	t_sdl *sdl;

	sdl = &game->interface.sdl;
	// if (sdl->event.type == SDL_MOUSEMOTION)
	// 	handle_mouse_motion(game, sdl->event.motion);
	if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
		handle_mouse_down(&game->curr_scene->events.mouse, sdl->event.button);
	// if (sdl->event.type == SDL_MOUSEBUTTONUP)
	// 	handle_mouse_up(game, sdl->event.button);
	// 	handle_keyboard_down(game->curr_scene, sdl->event.key.keysym.sym);
	// if (sdl->event.type == SDL_KEYUP)
	// 	handle_keyboard_up(game->curr_scene, sdl->event.key.keysym.sym);
	if (sdl->event.type == SDL_QUIT)
		game->is_running = FALSE;
	if (sdl->event.type == SDL_KEYDOWN && sdl->event.key.keysym.sym == SDLK_ESCAPE)
		game->is_running = FALSE;
}
