/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:44:43 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/17 13:06:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "maths/matrix.h"

t_matrix    mult(t_matrix m1, t_matrix m2)
{
    t_matrix ret;
    int     i;

    i = 0;
    while (i < 3)
    {
        ret.x[i] = m1.x[0] * m2.x[i] + m1.x[1] * m2.y[i] + m1.x[2] * m2.z[i];
        ret.y[i] = m1.y[0] * m2.x[i] + m1.y[1] * m2.y[i] + m1.y[2] * m2.z[i];
        ret.z[i] = m1.z[0] * m2.x[i] + m1.z[1] * m2.y[i] + m1.z[2] * m2.z[i];
        i++;
    }
    return ret;
}