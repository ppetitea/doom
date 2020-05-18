/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 00:10:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/28 00:11:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"

t_vec2i	vec2i_mult(t_vec2i vec2i, float k)
{
	vec2i.x *= k;
	vec2i.y *= k;
	return (vec2i);
}