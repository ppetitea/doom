/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:44:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/17 13:06:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/matrix.h"
#include <math.h>

t_matrix    rotate(float alpha)
{
    t_matrix ret;
    float c;
    float s;
    
    c = cos(alpha);
    s = sin(alpha);
    ret.x[0] = c;
    ret.x[1] = -s;
    ret.x[2] = 0;
    ret.y[0] = s;
    ret.y[1] = c;
    ret.y[2] = 0;
    ret.z[0] = 0;
    ret.z[1] = 0;
    ret.z[2] = 1;
    return ret;
}