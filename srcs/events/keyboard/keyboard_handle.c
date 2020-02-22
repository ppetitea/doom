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

void	handle_keyboard_down(t_scene *scene, SDL_Keycode key)
{
	if (scene == NULL)
		return (throw_void("handle_keyboard_down", "NULL pointer provided"));
	// trigger_key_bindings(&scene->interface.key_binds, key);
	// active_key_hold_binding(&scene->interface.key_hold_binds, key);
	(void)scene;
	(void)key;
}

void	handle_keyboard_up(t_scene *scene, SDL_Keycode key)
{
	// disable_key_hold_bindings(&scene->interface.key_hold_binds, key);
	(void)scene;
	(void)key;
}
