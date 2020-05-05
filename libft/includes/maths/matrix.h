/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:43:29 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/17 13:05:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "maths/vec2f.h"

typedef struct	s_matrix
{
	float x[3];
	float y[3];
	float z[3];
}				t_matrix;

t_matrix	scale(float k);
t_matrix	translate (float x, float y);
t_matrix	rotate(float alpha);
t_matrix	mult(t_matrix m1, t_matrix m2);
t_vec2f		to_vtx(t_matrix m, t_vec2f vtx);

#endif