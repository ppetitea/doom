/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:00:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 11:03:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "utils/error.h"

t_map	*get_current_map()
{
	t_game	*game;

	if (!(game = game_singleton(NULL)))
		return (throw_null("get_current_map", "Game not found"));
	return (game->curr_map);
}
