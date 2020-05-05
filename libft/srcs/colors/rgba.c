/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 00:14:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/28 00:19:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/color.h"

t_rgba ft_rgba(char r, char g, char b, char a)
{
	t_rgba rgba;

	rgba.rgba.b = b;
	rgba.rgba.g = g;
	rgba.rgba.r = r;
	rgba.rgba.a = a;
	return (rgba);
}