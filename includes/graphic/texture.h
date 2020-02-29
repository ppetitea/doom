/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 14:15:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "containers/list.h"
# include "utils/parser.h"
# include "maths/vec2i.h"

/*
**	render
*/
typedef struct		s_render_box
{
	t_vec2i			offset;
	t_vec2i			size;
	t_vec2f			scale;
	t_vec2i			start;
	t_vec2i			end;
}					t_render_box;


/*
** init
*/
typedef struct		s_texture
{
	t_list_head	node;
	t_vec2i		offset;
	t_vec2i		size;
	t_u32		*pixels;
	t_u32		delay_ms;
}					t_texture;
t_result			init_texture(t_texture *self);
t_texture			*init_new_texture();
t_texture			*init_new_texture_with_size(t_vec2i size);

/*
** filter
*/
typedef enum		e_filter_type
{
	FILTER_CIRCULAR_SHADOW,
	FILTER_CIRCULAR_BLEND,
	FILTER_BLEND,
	FILTER_NONE,
}					t_filter_type;
t_result			filter_texture(t_texture *text, t_filter_type filter);

/*
** build
*/
t_texture			*build_new_texture(t_obj *texture_obj);
t_result			build_textures(t_list_head *textures,
						t_obj *textures_obj);

/*
**	copy
*/
t_result			copy_texture_list(t_list_head *dest, t_list_head *src);

/*
**	add
*/
t_texture			*add_new_texture(t_list_head *textures, char *name,
						t_vec2i size, t_filter_type filter);

#endif
