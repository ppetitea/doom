/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_contain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:27:53 by ppetitea          #+#    #+#             */
/*   Updated: 2019/11/23 15:37:24 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2i.h"
#include "sizes/usize.h"
#include "types.h"

t_bool	is_range_contain(t_pos2i min, t_pos2i pos, t_pos2i max)
{
	if (pos.x < min.x || max.x < pos.x)
		return (FALSE);
	if (pos.y < min.y || max.y < pos.y)
		return (FALSE);
	return (TRUE);
}

t_bool  is_size_contain(t_pos2i pos, t_usize size)
{
	if (pos.x < 0 || (int)size.x < pos.x)
		return (FALSE);
	if (pos.y < 0 || (int)size.y < pos.y)
		return (FALSE);
	return (TRUE);
}