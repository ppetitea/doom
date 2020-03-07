/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 16:41:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "resources/player.h"

typedef struct	s_map_context
{
	t_animation		sky;
	t_animation		color;
	t_animation		height;
}				t_map_context;
t_result		init_map_context(t_map_context *self);

typedef struct	s_map_sprites
{
	t_player		player;
	t_list_head		mobs;
	t_list_head		objects;
	t_list_head		destructibles;
	t_list_head		icons; // icons displayed on a canvas
}				t_map_sprites;
t_result		init_map_sprites(t_map_sprites *self);

typedef struct	s_map
{
	t_list_head		node;
	char			*name;
	t_map_context	context;
	t_map_sprites	sprites;
}				t_map;
t_map			*init_new_map();



/*
** prerender
*/
typedef struct	s_render_slide
{
	float	dist_to_slide;
	float	dist_ratio;
	float	slide_width;
	float	slide_half;
	float	slide_delta;
}				t_render_slide;

typedef struct	s_rangei
{
	int	min;
	int	max;
}				t_rangei;

typedef struct	s_pre_render3d
{
	t_render_slide	*slides;
	size_t			slides_amount;
	t_rangei		index;
	t_u32			*columns_height;
	t_vec2f			delta_dir;
}				t_pre_render3d;

/*
** getter
*/
t_map			*get_current_map();

#endif
