/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:54:46 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/07 17:42:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYER_H
# define LAYER_H

# include "types.h"
# include <stdlib.h>

typedef enum		e_filter
{
	FILTER_CIRCULAR_SHADOW,
	FILTER_CIRCULAR_BLEND,
	FILTER_LIGHT,
	FILTER_DARK,
	FILTER_BLEND,
	FILTER_NONE,
}					t_filter;

typedef struct	s_layer
{
	int			width;
	int			height;
	t_u32		*pixels;
	t_result	(*destroy)(struct s_layer*);
}				t_layer;

t_result del_layer(t_layer *self);

t_result del_new_layer(t_layer *self);

t_result init_layer(t_layer *self);

t_layer *init_new_layer();

t_result set_layer(t_layer *self, int width, int height);

t_layer *set_new_layer(width, height);

#endif