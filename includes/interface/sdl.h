/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:51:42 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/03 14:24:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_INIT_H
# define SDL_INIT_H

# include <SDL_video.h>
# include <SDL_render.h>
# include <SDL_events.h>
# include <SDL2/SDL_ttf.h>
# include <string.h>
# include "types.h"

# define SDL_OK 0
# define SDL_ERROR -1

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
}					t_sdl;

t_result			init_sdl(t_sdl *self, size_t width, size_t height);
t_result			destroy_sdl(t_sdl *self);

/*
**	SDL_TTF lifecyle
**
** TTF_Init()
**
** TTF_Font police
** police = TTF_OpenFont("angelina.ttf", 65);
**
** SDL_Surface surface
** SDL_Color color = {0, 0, 0};
**
** surface = TTF_RenderText_Solid(police, "text example", color);
** surface = TTF_RenderText_Shaded(police, "text example", color);
** surface = TTF_RenderText_Blended(police, "text example", color);
**
** TTF_CloseFont(police);
** TTF_Quit();
*/

#endif