/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:22:56 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "containers/list.h"
# include "utils/parser.h"
# include "maths/vec2i.h"

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
t_texture			*init_new_texture(t_vec2i size);

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
t_texture			*build_new_texture(t_dnon_object *texture_obj);
t_result			build_textures(t_list_head *textures,
						t_dnon_object *textures_obj);

#endif
