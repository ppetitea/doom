/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:24:16 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:53:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/screen.h"

void	reset_screen(t_screen screen)
{
	int	i;
	int	screen_size;

	screen_size = screen.size.x * screen.size.y;
	i = -1;
	while (++i < screen_size)
	{
		screen.pixels[i] = 0x00000000;
	}
}