/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:46:12 by freezee           #+#    #+#             */
/*   Updated: 2020/03/01 22:09:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"

t_vec2i	vec2i_sub(t_vec2i a, t_vec2i b)
{
	t_vec2i	retval;

	retval.x = a.x - b.x;
	retval.y = a.y - b.y;
	return (retval);
}
