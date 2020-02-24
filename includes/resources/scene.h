/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:27:20 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 15:37:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_INIT_H
# define SCENE_INIT_H

# include "resources/map.h"
# include "utils/parser.h"

typedef struct			s_scene_interface
{
	// mouse params
	t_list_head			key_binds;
	t_list_head			key_hold_binds;
}						t_scene_interface;

typedef struct			s_map2d_config
{
	t_bool				display;
	t_vec2i				offset;
	t_vec2i				size;
	t_vec2i				icon_size;
}						t_map2d_config;

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
	t_bool				is_running;
	t_vec2i				anchor;
	t_vec2i				offset;
	t_usize				size;
	t_vec2f				scale;
	t_vec2f				inv_scale;
	size_t				horizon;
	float				horizon_dist;
	t_pre_render3d		pre_render;
}						t_map3d_config;

typedef struct			s_map_config
{
	t_map2d_config	color_map;
	t_map2d_config	height_map;
	t_map2d_config	drop_map;
	t_map3d_config	map_3d;
	t_map			*map_ref;
	t_dnon_object	*character_obj;
}						t_map_config;

typedef struct			s_scene
{
	t_list_head			node;
	char				*name;
	t_scene_interface	interface;
	t_animation			background;
	t_animation			title;
	t_list_head			render_list;
	t_list_head			buttons;
	t_map_config		map_config;
}						t_scene;

t_scene				*init_new_scene();
t_result			init_map_config(t_map_config *config);

#endif
