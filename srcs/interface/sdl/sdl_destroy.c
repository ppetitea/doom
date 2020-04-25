/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:37:26 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/25 19:23:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "interface/sdl.h"
#include "log/log.h"

t_result	destroy_sdl(t_sdl *self)
{
	if (self == NULL)
		return (console(WARN, __func__, __LINE__, "null pointer").warn);
	if (self->renderer != NULL)
		SDL_DestroyRenderer(self->renderer);
	if (self->texture != NULL)
		SDL_DestroyTexture(self->texture);
	if (self->window != NULL)
		SDL_DestroyWindow(self->window);
	SDL_Quit();
	return (OK);
}
