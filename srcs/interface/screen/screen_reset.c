/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:24:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 18:44:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/screen.h"

void	reset_screen(t_screen screen)
{
	size_t	i;

	i = 0;
	while (i < screen.size.x * screen.size.y)
	{
		screen.pixels[i] = 0x00000000;
		i++;
	}
}