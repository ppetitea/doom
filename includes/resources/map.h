/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 13:07:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "resources/player.h"

typedef struct	s_map_context
{
	t_animation		sky;
	t_result		(*render_skybox)(t_animation*, float, t_box);
	t_animation		color;
	t_animation		height;
}				t_map_context;
t_result		init_map_context(t_map_context *self);

/*
**	C'est la map2d qui se rend elle-meme
**	C'est la map2d qui check les collisions avec la souris
*/
typedef struct	s_map2d
{
	t_bool					display;
	t_box					render_box;
	t_vec2i					icon_size;
	t_mouse_observable		mouse;
	t_animation				*map;
	t_result				(*render_map)(t_animation*, t_box);
	t_list_head				icons;
	t_result				(*render_icons)(t_list_head*, t_vec2i, t_box);
}				t_map2d;
t_result		init_map2d(t_map2d *self);

typedef struct	s_map_sprites
{
	t_player		player;
	t_list_head		mobs;
	t_list_head		objects;
	t_list_head		destructibles;
}				t_map_sprites;
t_result		init_map_sprites(t_map_sprites *self);

/*
**	C'est la map3d qui se rend elle-meme
*/
typedef struct	s_map3d
{
	t_bool			display;
	t_box			render_box;
	t_list_head		sprites_list;
	t_result		(*render_world)(t_map_context*, t_list_head*, t_box);
	t_result		(*render_player)(t_player*, t_box);
}				t_map3d;
t_result		init_map3d(t_map3d *self);

typedef struct	s_map
{
	t_list_head		node;
	char			*name;
	t_map_context	context;
	t_map_sprites	sprites;
	t_map2d			drop;
	t_map2d			color;
	t_map2d			height;
	t_map3d			world3d;
	t_result		(*render)(struct s_map*);
}				t_map;
t_map			*init_new_map();

#endif
