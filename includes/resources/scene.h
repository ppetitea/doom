/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 13:25:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_INIT_H
# define SCENE_INIT_H

# include "resources/map.h"
# include "utils/parser.h"

/*
** map render configuration
*/
typedef struct			s_map2d_config
{
	t_bool		display;
	t_box		render_box;
	t_vec2i		icon_size;
}						t_map2d_config;
t_result				init_map2d_config(t_map2d_config *self);

typedef struct		s_render_slide
{
	float	dist_to_slide;
	float	dist_ratio;
	float	slide_width;
	float	slide_half;
	float	slide_delta;
}					t_render_slide;

typedef struct		s_rangei
{
	int	min;
	int	max;
}					t_rangei;

typedef struct		s_pre_render3d
{
	t_render_slide	*slides;
	size_t			slides_amount;
	t_rangei		index;
	t_u32			*columns_height;
	t_vec2f			delta_dir;
}					t_pre_render3d;

typedef struct			s_map3d_config
{
	t_bool				display;
	t_box				render_box;
	t_pre_render3d		pre_render;
}						t_map3d_config;
t_result				init_map3d_config(t_map3d_config *self);

typedef struct			s_map_config
{
	t_map2d_config		color;
	t_map2d_config		height;
	t_map2d_config		drop;
	t_map3d_config		world3d;
}						t_map_config;
t_result				init_map_config(t_map_config *self);

/*
** graphic user interface
** D'abord la scene rend le background puis le titre et les bouttons puis la map
*/
typedef struct			s_scene_gui
{
	t_animation			background;
	t_animation			title;
	t_list_head			buttons;
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
	t_map_config		map_config;
}						t_scene;
t_scene				*init_new_scene();

#endif
