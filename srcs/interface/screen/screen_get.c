/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:32:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 15:35:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "interface/screen.h"
#include "utils/error.h"

t_screen *get_screen()
{
	t_game	*game;

	if (!(game = game_singleton(NULL)))
		return (throw_null("get_screen", "Game not found"));
	return (&game->interface.screen);
}
