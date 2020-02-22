/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_magnitude.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:29:38 by ppetitea          #+#    #+#             */
/*   Updated: 2019/11/25 17:25:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2f.h"
#include <math.h>

float	vec2f_magnitude(t_vec2f v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}