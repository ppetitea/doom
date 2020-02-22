/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 00:57:34 by freezee           #+#    #+#             */
/*   Updated: 2020/01/30 23:42:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3f.h"

t_vec3f	vec3f_sub(t_vec3f a, t_vec3f b)
{
	t_vec3f	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}
