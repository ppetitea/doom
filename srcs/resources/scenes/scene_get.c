/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 22:38:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 22:43:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "utils/error.h"

t_scene	*get_current_scene()
{
	t_game	*game;

	if (!(game = game_singleton(NULL)))
		return (throw_null("get_current_scene", "Game not found"));
	return (game->curr_scene);
}
