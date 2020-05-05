/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 00:14:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/28 00:17:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/color.h"

t_bgra ft_bgra(char r, char g, char b, char a)
{
	t_bgra bgra;

	bgra.bgra.b = b;
	bgra.bgra.g = g;
	bgra.bgra.r = r;
	bgra.bgra.a = a;
	return (bgra);
}