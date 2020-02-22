/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 22:52:07 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 20:14:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "interface/screen.h"
# include "interface/sdl.h"
# include "events/keyboard.h"
# include "events/mouse.h"
# include "resources/scene.h"
# include "containers/list.h"

typedef struct			s_game_resources
{
	t_list_head			images;
	t_list_head			songs;
	t_list_head			buttons;
	t_list_head			titles;
	t_list_head			players;
	t_list_head			mobs;
	t_list_head			objects;
	t_list_head			maps;
	t_list_head			scenes;
}						t_game_resources;

typedef struct			s_game_interface
{
	t_sdl				sdl;
	t_screen			screen;
}						t_game_interface;

typedef struct			s_game_events
{
	t_mouse				mouse;
	t_keyboard			keyboard;
}						t_game_events;

typedef struct			s_game
{
	t_game_interface	interface;
	t_game_resources	resources;
	t_game_events		events;
	t_scene				*curr_scene;
	t_map				*curr_map;
	t_bool				is_running;
}						t_game;

t_game					*init_new_game();
t_game					*game_singleton(t_game *init);

void					loop(t_game *game, t_screen *screen, t_sdl *sdl);


#endif
