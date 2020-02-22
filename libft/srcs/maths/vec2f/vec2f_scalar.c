/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:30:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/17 21:23:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec2f.h"

t_vec2f	vec2f_scalar(t_vec2f src, float a)
{
	t_vec2f		ret;
	ret.x = src.x * a;
	ret.y = src.y * a;
	return (ret);
}
