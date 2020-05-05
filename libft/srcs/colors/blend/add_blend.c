/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_blend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 02:30:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/16 19:20:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"colors/color.h"

t_u32	blend_add_average(t_rgba current, t_rgba old)
{
	t_rgba	new;

	new.rgba.r = (current.rgba.r + old.rgba.r) * 0.5f;
	new.rgba.g = (current.rgba.g + old.rgba.g) * 0.5f;
	new.rgba.b = (current.rgba.b + old.rgba.b) * 0.5f;
	new.rgba.a = (current.rgba.a + old.rgba.a) * 0.5f;
	return (new.px);
}

t_u32	blend_add(t_rgba curr, t_rgba old)
{
	unsigned int	alpha;
	unsigned int	inv_alpha;
	t_rgba			new;

	alpha = curr.rgba.a + 1;
	inv_alpha = 256 - curr.rgba.a;
	new.rgba.r = (unsigned char)((alpha * curr.rgba.r + inv_alpha * old.rgba.r) >> 8);
	new.rgba.g = (unsigned char)((alpha * curr.rgba.g + inv_alpha * old.rgba.g) >> 8);
	new.rgba.b = (unsigned char)((alpha * curr.rgba.b + inv_alpha * old.rgba.b) >> 8);
	new.rgba.a = 0xff;
	return (new.px);
}