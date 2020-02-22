/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_vtx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:44:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/06 19:35:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/matrix.h"

t_vec2f	to_vtx(t_matrix m, t_vec2f vtx)
{
    t_vec2f ret;

    ret.x = m.x[0] * vtx.x + m.x[1] * vtx.y + m.x[2] * 1;
    ret.y = m.y[0] * vtx.x + m.y[1] * vtx.y + m.y[2] * 1;
    return ret;
}