/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:45:09 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 19:46:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "utils/error.h"

void	handle_keyboard_down(t_keyboard_observable *keyboard,
					SDL_KeyboardEvent event)
{
	keyboard->state.key = event.keysym.sym;
	if (event.keysym.sym == SDLK_w)
		keyboard->state.w = TRUE;
	else if (event.keysym.sym == SDLK_a)
		keyboard->state.a = TRUE;
	else if (event.keysym.sym == SDLK_s)
		keyboard->state.s = TRUE;
	else if (event.keysym.sym == SDLK_d)
		keyboard->state.d = TRUE;
	trigger_keyboard_observers_on(&keyboard->followers.down, keyboard->state);
	(void)keyboard;
	(void)event;
}

void	handle_keyboard_up(t_keyboard_observable *keyboard,
					SDL_KeyboardEvent event)
{
	keyboard->state.key = event.keysym.sym;
	if (event.keysym.sym == SDLK_w)
		keyboard->state.w = FALSE;
	else if (event.keysym.sym == SDLK_a)
		keyboard->state.a = FALSE;
	else if (event.keysym.sym == SDLK_s)
		keyboard->state.s = FALSE;
	else if (event.keysym.sym == SDLK_d)
		keyboard->state.d = FALSE;
	trigger_keyboard_observers_on(&keyboard->followers.up, keyboard->state);
	(void)keyboard;
	(void)event;
}



/*
	le player veut avancer en diagonale de maniere fluide et norme
	le player qui observe les touches WASD et
	associe une action down qui set les directions du prochain mouvement
	associe une action up qui unset les directions du prochain mouvement
	associe une action update qui update la position du player
		en fonction des directions set
	
	le user appuie sur les touches W & D
	le player set les touches W & D a true
 */