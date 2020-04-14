/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 22:39:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_INIT_H
# define SCENE_INIT_H

# include "resources/map.h"
# include "utils/parser.h"

/*
** graphic user interface
** D'abord la scene rend le background puis le titre et les bouttons puis la map
*/
typedef struct			s_scene_gui
{
	t_animation			background;
	t_list_head			buttons;
	t_list_head			canvas;
	t_list_head			render_list;
}						t_scene_gui;
t_result				init_scene_gui(t_scene_gui *self);

/*
** events
*/
typedef struct			s_scene_events
{
	t_mouse_observable		mouse;
	t_keyboard_observable	keyboard;
	t_list_head				loop;
	t_list_head				timed;
	t_keyboard_observer		quit; // la scene observe l'event quit qui sera declenche par SDLK_ESCAPE
	t_time_observer			timer_test; // utiliser pour jouer des musiques les unes a la suite des autres ?
}						t_scene_events;

/*
** initialisation
*/
typedef struct			s_scene
{
	t_list_head			node;
	char				*name;
	t_scene_events		events;
	t_scene_gui			gui;
}						t_scene;
t_scene				*init_new_scene();

/*
** render
*/
t_result			render_scene(t_scene *scene);

/*
** getter
*/
t_scene				*get_current_scene();

#endif