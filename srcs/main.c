/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:59:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/01 11:44:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "interface/sdl.h"
#include "time/time.h"
#include "log/log.h"
#include "maths/vec2i.h"
#include <stdio.h>

// t_result	loop(t_gui_interface *interface, t_sdl *sdl)
// {
// 	double	last_time;
// 	double	spf;
// 	t_gui	*scene;

// 	while (interface->is_running)
// 	{
// 		if (!(scene = interface->curr_scene))
// 			return (console(FATAL, __func__, __LINE__, "scene is null").err);
// 		last_time = get_wall_time();
// 		while (SDL_PollEvent(&sdl->event))
// 			handle_gui_events(interface, &sdl->event);
// 		render_gui(interface->curr_scene);
// 		if (SDL_UpdateTexture(sdl->texture, NULL, scene->layer.pixels,
// 			scene->layer.width * sizeof(uint32_t)) == SDL_ERROR)
// 			return (console(FATAL, __func__, __LINE__, "sdl fail").err);
// 		if (SDL_RenderClear(sdl->renderer) == SDL_ERROR)
// 			return (console(FATAL, __func__, __LINE__, "sdl fail").err);
// 		if (SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL))
// 			return (console(FATAL, __func__, __LINE__, "sdl fail").err);
// 		SDL_RenderPresent(sdl->renderer);
// 		spf = get_wall_time() - last_time;
// 		set_delta(spf);
// 	}
// 	return (OK);
// }

int		main()
{
	t_sdl sdl;
	t_vec2i	screen_size;

	screen_size = ft_vec2i(1080, 720);
	if (!init_sdl(&sdl, screen_size.x, screen_size.y))
		return (console(FATAL, __func__, __LINE__, "init sdl fail").err);
	if (!build_interface(screen_size))
		return (console(FATAL, __func__, __LINE__, "build fail").err);
	// loop(interface(), &sdl);
	return (0);
}
