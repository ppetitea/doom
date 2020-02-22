/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:37:26 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 20:05:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "interface/sdl.h"
#include "utils/error.h"

void	destroy_sdl(t_sdl *self)
{
	if (self != NULL)
	{
		if (self->renderer != NULL)
			SDL_DestroyRenderer(self->renderer);
		if (self->texture != NULL)
			SDL_DestroyTexture(self->texture);
		if (self->window != NULL)
			SDL_DestroyWindow(self->window);
		SDL_Quit();
	}
	else
		throw_void("destroy_sdl", "NULL pointer provided");
}