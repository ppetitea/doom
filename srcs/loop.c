/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 23:07:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "libft.h"
#include "resources/game.h"
#include "interface/sdl.h"
#include "events/events.h"
#include "utils/error.h"
#include "utils/time.h"

#include <stdio.h>

void	loop(t_game *game, t_screen *screen, t_sdl *sdl)
{
	double	last_time;
	double	spf;

	game->is_running = TRUE;
	while (game->is_running)
	{
		last_time = get_wall_time();
		if (game->curr_scene->events.mouse.state.mode == POINTER_GAME)
			SDL_WarpMouseInWindow(sdl->window, (uint16_t)(game->interface.screen.size.x / 2),
			(uint16_t)(game->interface.screen.size.y / 2));
		while (SDL_PollEvent(&sdl->event))
			handle_events(game);
		trigger_observers(&game->curr_scene->events.loop);
		trigger_time_observers(&game->curr_scene->events.timed, last_time);
		reset_screen(*screen);
		render_scene(game->curr_scene);
		if (SDL_UpdateTexture(sdl->texture, NULL, screen->pixels,
			screen->size.x * sizeof(uint32_t)) == SDL_ERROR)
			return (throw_void("loop", "SDL_UpdateTexture failed"));
		if (SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL))
			return (throw_void("loop", "SDL_RenderCopy failed"));
		SDL_RenderPresent(sdl->renderer);
		if (SDL_RenderClear(sdl->renderer) == SDL_ERROR)
			return (throw_void("loop", "SDL_RenderClear failed"));
		spf = get_wall_time() - last_time;
		// printf("fps: %f\n", 1.0f / spf);
		set_delta(spf);
	}
	destroy_sdl(&game->interface.sdl);
}
