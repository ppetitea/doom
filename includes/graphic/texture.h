/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 18:11:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "containers/list.h"
# include "maths/vec2i.h"

typedef struct			s_texture
{
	t_list_head	node;
	t_vec2i		offset;
	t_vec2i		size;
	t_u32		*pixels;
	t_u32		delay_ms;
}						t_texture;
t_result				init_texture(t_texture *self);
t_texture				*init_new_texture();

#endif
