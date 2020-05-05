/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:50:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/02 13:03:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "interface/sdl.h"
#include "log/log.h"

t_result	init_sdl(t_sdl *self, size_t width, size_t height)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (SDL_Init(SDL_INIT_VIDEO) == SDL_ERROR)
		return (console(FATAL, __func__, __LINE__, "sdl init fail").err);
	if (!(self->window = SDL_CreateWindow("DOUM", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN)))
		return (console(FATAL, __func__, __LINE__, "sdl fail").err);
	if (!(self->renderer = SDL_CreateRenderer(self->window, -1,
		SDL_RENDERER_SOFTWARE)))
		return (console(FATAL, __func__, __LINE__, "sdl fail").err);
	SDL_SetRenderDrawBlendMode(self->renderer, SDL_BLENDMODE_ADD);
	if (!(self->texture =  SDL_CreateTexture(self->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height)))
		return (console(FATAL, __func__, __LINE__, "sdl fail").err);
	SDL_SetTextureBlendMode(self->texture, SDL_BLENDMODE_ADD);
	if (TTF_Init() == SDL_ERROR)
		return (console(FATAL, __func__, __LINE__, "init ttf fail").err);
	return (OK);
}