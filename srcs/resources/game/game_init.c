/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:36:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 20:11:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "resources/map.h"
#include "utils/error.h"
#include "libft.h"

t_game	*game_singleton(t_game *init)
{
	static t_game *game = NULL;

	if (game == NULL && init == NULL)
		return (throw_null("game_singleton", "NULL pointer provided at init"));
	if (game == NULL)
		game = init;
	return (game);
}

t_result	init_game_resources(t_game_resources *self)
{
	if (self == NULL)
		return (throw_error("init_game_resources", "NULL pointer provided"));
	init_list_head(&self->images);
	init_list_head(&self->songs);
	init_list_head(&self->buttons);
	init_list_head(&self->titles);
	init_list_head(&self->players);
	init_list_head(&self->mobs);
	init_list_head(&self->objects);
	init_list_head(&self->maps);
	init_list_head(&self->scenes);
	return (OK);
}

t_result	init_game_events(t_game_events *self)
{
	if (self == NULL)
		return (throw_error("init_game_events", "NULL pointer provided"));
	self->keyboard.w = FALSE;
	self->keyboard.a = FALSE;
	self->keyboard.s = FALSE;
	self->keyboard.d = FALSE;
	self->mouse.down = FALSE;
	self->mouse.drag = FALSE;
	self->mouse.pos = ft_vec2i(0, 0);
	return (OK);
}

t_game	*init_new_game(t_usize window_size)
{
	t_game	*self;

	if (!(self = (t_game*)malloc(sizeof(t_game))))
		return(throw_null("build_game", "malloc failed"));
	if (!(init_sdl(&self->interface.sdl, window_size.x, window_size.y)))
		return(throw_null("build_game", "build_sdl failed"));
	if (!init_screen(&self->interface.screen, window_size))
		return(throw_null("build_game", "screen initialization failed"));
	init_game_resources(&self->resources);
	init_game_events(&self->events);
	self->curr_scene = NULL;
	self->curr_map = NULL;
	self->is_running = FALSE;
	game_singleton(self);
	return (self);
}
