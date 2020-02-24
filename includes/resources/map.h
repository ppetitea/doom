/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 15:58:58 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "resources/player.h"

typedef struct	s_color_map
{
	t_animation	*map;
	t_bool		display;
	t_vec2i		offset;
	t_vec2i		size;
}				t_color_map;

typedef struct	s_height_map
{
	t_animation	*map;
	t_bool		display;
	t_vec2i		offset;
	t_vec2i		size;
}				t_height_map;

typedef struct	s_drop_map
{
	t_animation	*map;
	t_list_head	collide_list;
	t_bool		display;
	t_vec2i		offset;
	t_vec2i		size;
	t_vec2i		icon_size;
}				t_drop_map;

typedef struct	s_render3d
{
	t_bool		display;
	t_animation	sky;
	t_animation	*color;
	t_animation	*height;
	t_vec2i		offset;
	t_vec2i		size;
}				t_render3d;

typedef struct	s_map
{
	t_list_head		node;
	char			*name;
	t_list_head		render_list;
	t_player		player;
	t_list_head		mobs;
	t_list_head		objects;
	t_animation		color;
	t_animation		height;
	t_render3d		render3d;
	t_drop_map		drop;
}				t_map;
t_map			*init_new_map();

#endif
