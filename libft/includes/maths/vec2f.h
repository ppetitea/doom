/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:19:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/02/06 22:43:48 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

#ifndef VEC2F_H
# define VEC2F_H

/*
** Two-dimensional float vector
*/
typedef struct	s_vec2f
{
	float	x;
	float	y;
}				t_vec2f;

typedef t_vec2f t_pos2f;

/*
** Constructors
*/
t_vec2f			ft_vec2f(float x, float y);

/*
** Operations
*/
t_vec2f			vec2f_opposite(t_vec2f v);
t_vec2f			vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f			vec2f_sub(t_vec2f a, t_vec2f b);
float			vec2f_dot(t_vec2f a, t_vec2f b);
t_vec2f			vec2f_scalar(t_vec2f src, float a);
float			vec2f_magnitude(t_vec2f v);
t_vec2f			vec2f_normalize(t_vec2f v);
t_bool			vec2f_equals(t_vec2f p1, t_vec2f p2);


#endif
