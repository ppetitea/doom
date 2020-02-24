/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:59:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 13:08:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "utils/error.h"

int		main()
{
	t_game *game;

	// build();
	if ((game = build()) != NULL)
		loop(game, &game->interface.screen, &game->interface.sdl);
	return (0);
}
