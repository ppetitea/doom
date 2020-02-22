/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:32:01 by ppetitea          #+#    #+#             */
/*   Updated: 2019/11/25 17:24:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2f.h"

t_vec2f	vec2f_normalize(t_vec2f v)
{
	t_vec2f	ret;
	float	magnitude;

	magnitude = vec2f_magnitude(v);
	ret.x = v.x / magnitude;
	ret.y = v.y / magnitude;
	return (ret);
}