/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:46:12 by freezee           #+#    #+#             */
/*   Updated: 2020/01/26 17:09:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"

t_vec2i	vec2i_add(t_vec2i a, t_vec2i b)
{
	t_vec2i	retval;

	retval.x = a.x + b.x;
	retval.y = a.y + b.y;
	return (retval);
}
