/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:34:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 17:23:40 by ppetitea         ###   ########.fr       */
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
		reset_screen(*screen);
		render_scene(game->curr_scene);
		if (SDL_UpdateTexture(sdl->texture, NULL, screen->pixels,
			screen->size.x * sizeof(uint32_t)) == SDL_ERROR)
			return (throw_void("loop", "SDL_UpdateTexture failed"));
		while (SDL_PollEvent(&sdl->event))
			handle_events(game);
		// trigger_key_hold_bindings(&game->curr_scene->interface.key_hold_binds);
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
