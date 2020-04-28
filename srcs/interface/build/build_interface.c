/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:14:56 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/26 15:35:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/build.h"
#include "log/log.h"

t_gui_interface	*interface()
{
	static t_gui_interface interface;
	return (&interface);
}

t_result		build_interface(t_vec2i screen_size)
{
	t_gui_interface *gui_interface;
	
	if (!(gui_interface = interface()))
		return (console(FATAL, __func__, __LINE__, "interface fail").err);
	if (!init_gui_interface(gui_interface))
		return (console(FATAL, __func__, __LINE__, "init_interface fail").err);
	gui_interface->curr_scene = build_home_scene(gui_interface, screen_size);
	return (OK);
}