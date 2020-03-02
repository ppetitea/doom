/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:38:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 18:50:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "utils/error.h"

t_mouse_observable	*get_mouse_observable()
{
	t_game	*game;
	
	if (!(game = game_singleton(NULL)))
		return (throw_null("get_mouse", "game is NULL"));
	if (!game->curr_scene)
		return (throw_null("get_mouse", "Current scene is NULL"));
	return (&game->curr_scene->events.mouse);
}

t_mouse_followers	*get_mouse_followers()
{
	t_game	*game;
	
	if (!(game = game_singleton(NULL)))
		return (throw_null("get_mouse", "game is NULL"));
	if (!game->curr_scene)
		return (throw_null("get_mouse", "Current scene is NULL"));
	return (&game->curr_scene->events.mouse.followers);
}

t_mouse	*get_mouse_state()
{
	t_game	*game;

	if (!(game = game_singleton(NULL)))
		return (throw_null("get_mouse", "game is NULL"));
	if (!game->curr_scene)
		return (throw_null("get_mouse", "Current scene is NULL"));
	return (&game->curr_scene->events.mouse.state);
}
