/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:44:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/17 13:06:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/matrix.h"

t_matrix    translate (float x, float y)
{
    t_matrix ret;

    ret.x[0] = 1;
    ret.x[1] = 0;
    ret.x[2] = x;
    ret.y[0] = 0;
    ret.y[1] = 1;
    ret.y[2] = y;
    ret.z[0] = 0;
    ret.z[1] = 0;
    ret.z[2] = 1;
    return ret;
}