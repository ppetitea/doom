/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 14:20:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/26 00:37:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "log/log.h"

t_gui *build_home_scene(t_gui_interface *interface, t_vec2i screen_size)
{
	t_gui *home;

	if (!(home = build_gui_scene("Home", screen_size)))
		return (console(FATAL, __func__, __LINE__, "init_interface fail").null);
	home->bg_color.bgra.r = 150;
	home->bg_color.bgra.g = 50;
	home->bg_color.bgra.b = 200;
	home->bg_color.bgra.a = 255;
	home->display = TRUE;
	home->filter = FILTER_DARK;
	node_add_prev(&interface->scenes, &home->node);
	return (home);
}
