/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:18:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 15:27:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "resources/images.h"
#include "resources/button.h"
#include "utils/error.h"
#include "utils/parser.h"
#include "libft.h"
#include "build.h"

#include <stdio.h>

t_game	*build()
{
	t_game_resources	*r;
	t_game				*game;
	t_usize 			window;

	window = ft_usize(1080, 720);
	if (!(game = init_new_game(window)))
		return (throw_null("build_game", "Fail to init_new_game"));
	r = &game->resources;
	if (!resources_load_images(&r->images, "resources/path"))
		return (throw_null("build_game", "Fail to load images"));
	game->curr_scene = add_test_scene(&game->resources.scenes);
	// if (!build_new_buttons(&r->buttons, "resources/ui_buttons.doom"))
	// 	return (throw_null("build_game", "Fail to load buttons"));
	// printf("list len %ld\n", list_lenght(&game->resources.images));
	// if (!build_game_resources(game, obj))
	// 	return (throw_null("build_game", "build_resources failed"));
	return (game);
}
