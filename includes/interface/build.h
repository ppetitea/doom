/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:19:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/03 23:48:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

#include "interface/gui.h"

/*
** BUILD INTERFACE
*/
t_gui_interface	*interface();
t_result		build_interface(t_vec2i screen_size);
SDL_Keycode		interface_get_key();
t_result		update_gui_text(t_gui *gui);

/*
** BUILD SCENES
*/
t_gui			*build_home_scene(t_gui_interface *interface,
	t_vec2i screen_size);

#endif