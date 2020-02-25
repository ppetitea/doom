/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/25 13:20:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "resources/player.h"

// typedef struct	s_color_map
// {
// 	t_animation	*map;
// 	t_bool		display;
// 	t_vec2i		offset;
// 	t_vec2i		size;
// }				t_color_map;

// typedef struct	s_height_map
// {
// 	t_bool		display;
// 	t_animation	*map;
// 	t_vec2i		offset;
// 	t_vec2i		size;
// }				t_height_map;

// typedef struct	s_drop_map
// {
// 	t_bool		display;
// 	t_list_head	*render_list;
// 	t_list_head	*collide_list;
// 	t_animation	*map;
// 	t_vec2i		offset;
// 	t_vec2i		size;
// 	t_vec2i		icon_size;
// }				t_drop_map;

// typedef struct	s_render3d
// {
// 	t_bool		display;
// 	t_list_head	*render_list;
// 	t_animation	*sky;
// 	t_animation	*color;
// 	t_animation	*height;
// 	t_vec2i		offset;
// 	t_vec2i		size;
// }				t_render3d;

// typedef struct	s_map_render
// {
// 	t_render3d		render3d;
// 	t_color_map		color;
// 	t_height_map	height;
// 	t_drop_map		drop;
// }				t_map_render;

typedef struct	s_mouse_collider
{
	t_vec2i		mouse;
	t_list_head	hover;
	t_list_head	select;
	t_list_head	drag;
}				t_mouse_collider;

typedef struct	s_map_icons
{
	t_mouse_collider	collide;
	t_list_head			visibles;
	t_list_head			hiddens;
}				t_map_icons;

typedef struct	s_map_sprites
{
	t_list_head		visibles;
	t_list_head		hiddens;
	t_list_head		destructibles;
	t_player		player;
	t_list_head		mobs;
	t_list_head		objects;
}				t_map_sprites;

typedef struct	s_map_context
{
	t_animation		sky;
	t_animation		color;
	t_animation		height;
}				t_map_context;

typedef struct	s_map
{
	t_list_head		node;
	char			*name;
	t_map_icons		icons;
	t_map_sprites	sprites;
	t_map_context	context;
	// t_map_renderer	renderer;
}				t_map;
t_map			*init_new_map();

#endif
