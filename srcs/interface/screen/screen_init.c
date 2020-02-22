/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:09:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 18:44:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/screen.h"
#include "resources/game.h"
#include "utils/error.h"

t_result	init_screen(t_screen *self, t_usize window_size)
{
	if (!self)
		return (throw_error("initialize_screen", "NULL pointer provided"));
	self->size = window_size;
	self->pixels = NULL;
	if (!(self->pixels = (t_u32*)malloc(sizeof(t_u32)
		* window_size.x * window_size.y)))
		return (throw_error("initialize_screen", "malloc failed"));
	return (OK);
}

t_screen	*game_screen()
{
	t_game *game;

	if (!(game = game_singleton(NULL)))
		return (throw_null("game_screen", "game is NULL"));
	return (&game->interface.screen);
}
