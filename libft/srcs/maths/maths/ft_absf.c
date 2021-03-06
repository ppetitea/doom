/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:27:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/17 23:55:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"

float	ft_absf(float f)
{
	return ((f < 0) ? -f : f);
}
