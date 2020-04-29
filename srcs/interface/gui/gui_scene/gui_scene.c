/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 21:41:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/30 00:33:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "interface/build.h"
#include "image/image.h"
#include "log/log.h"
#include "action/action.h"

t_gui	*build_gui_image(char *name, t_vec2i size, t_pos2i pos, char *img_src)
{
	t_gui_interface	*gui_interface;
	t_gui			*image;
	t_list_head		*list;

	if (!(gui_interface = interface()))
		return (console(FATAL, __func__, __LINE__, "no interface").null);
	if (!(list = &gui_interface->images))
		return (console(FATAL, __func__, __LINE__, "no images").null);
	if (!(image = set_new_gui(name, size.x, size.y)))
		return (console(FATAL, __func__, __LINE__, "set_new_gui fail").null);
	if (!(image->background = image_find(list, img_src))
		&& del_gui(&image->node))
		return (console(WARN, __func__, __LINE__, "get_image fail").null);
	image->pos = pos;
	return (image);
}

/*
** todo
** add default action like set dark filter when mouse over event occurs
*/

t_result	build_gui_observers(t_gui_interface *interface, t_gui *gui)
{
	gui->hover_start.list = &interface->mouse_hover_start;
	gui->hover_start.gui = gui;
	gui->hover_end.list = &interface->mouse_hover_end;
	gui->hover_end.gui = gui;
	gui->left_up.list = &interface->mouse_left_up;
	gui->left_up.gui = gui;
	gui->left_down.list = &interface->mouse_left_down;
	gui->left_down.gui = gui;
	gui->right_up.list = &interface->mouse_right_up;
	gui->right_up.gui = gui;
	gui->right_down.list = &interface->mouse_right_down;
	gui->right_down.gui = gui;
	gui->drag.list = &interface->mouse_drag;
	gui->drag.gui = gui;
	gui->drop.list = &interface->mouse_drop;
	gui->drop.gui = gui;
	gui->motion.list = &interface->mouse_motion;
	gui->motion.gui = gui;
	gui->wheel_normal.list = &interface->mouse_wheel_normal;
	gui->wheel_normal.gui = gui;
	gui->wheel_flip.list = &interface->mouse_wheel_flip;
	gui->wheel_flip.gui = gui;
	gui->key_up.list = &interface->key_up;
	gui->key_up.gui = gui;
	gui->key_down.list = &interface->key_down;
	gui->key_down.gui = gui;
	gui->time_obs.list = &interface->time;
	gui->time_obs.gui = gui;
	return (OK);
}

t_result	build_gui_hover_default_events(t_gui *gui)
{
	t_argv		argv;
	t_list_head	*list;

	argv.ref = gui;
	list = &gui->hover_start.actions;
	add_new_action(list, lighten_gui_layer, argv, ARG_REF);
	argv.ref = &gui->hover_start;
	add_new_action(list, mouse_obs_unsubscribe, argv, ARG_REF);
	argv.ref = &gui->hover_end;
	add_new_action(list, mouse_obs_subscribe, argv, ARG_REF);
	mouse_obs_subscribe(&gui->hover_start);
	list = &gui->hover_end.actions;
	argv.ref = gui;
	add_new_action(list, filter_reset_gui_layer, argv, ARG_REF);
	argv.ref = &gui->hover_end;
	add_new_action(list, mouse_obs_unsubscribe, argv, ARG_REF);
	argv.ref = &gui->hover_start;
	add_new_action(list, mouse_obs_subscribe, argv, ARG_REF);
	return (OK);
}

t_gui	*build_gui_button(char *name, t_pos2i pos, t_vec2i size,
			t_gui_interface *interface)
{
	t_gui *button;

	if (!(button = set_new_gui(name, size.x, size.y)))
		return (console(FATAL, __func__, __LINE__, "init fail").null);
	button->pos = pos;
	build_gui_observers(interface, button);
	build_gui_hover_default_events(button);
	return (button);
}

t_result	build_checkbox_default_events(t_gui *checkbox)
{
	t_list_head		*list;
	t_argv			argv;

	list = &checkbox->left_down.actions;
	argv.ref = checkbox;
	add_new_action(list, toogle_colorize_gui, argv, ARG_REF);
	mouse_obs_subscribe(&checkbox->left_down);
	return (OK);
}

t_gui	*build_gui_checkbox(char *name, t_pos2i pos, t_vec2i size,
			t_gui_interface *interface)
{
	t_gui	*checkbox;

	if (!(checkbox = set_new_gui(name, size.x, size.y)))
		return (console(FATAL, __func__, __LINE__, "init fail").null);
	checkbox->pos = pos;
	checkbox->bg_color = ft_bgra(159, 159, 159, 255);
	build_gui_observers(interface, checkbox);
	build_checkbox_default_events(checkbox);
	return (checkbox);
}

t_result	build_radio_default_events(t_gui *radio, t_arg *radio_list)
{
	t_action	*action;
	t_list_head	*list;
	t_argv		argv;

	list = &radio->left_down.actions;
	argv.ref = radio;
	add_new_action(list, check_gui, argv, ARG_REF);
	action = add_new_action(list, checkout_gui_list, argv, ARG_REF);
	node_add_child(&action->args.node, &radio_list->node);
	mouse_obs_subscribe(&radio->left_down);
	return (OK);
}

t_gui	*build_gui_radio(char *name, t_pos2i pos, t_vec2i size,
			t_gui_interface *interface)
{
	t_gui	*radio;

	if (!(radio = set_new_gui(name, size.x, size.y)))
		return (console(FATAL, __func__, __LINE__, "init fail").null);
	radio->pos = pos;
	radio->bg_color = ft_bgra(159, 159, 159, 255);
	build_gui_observers(interface, radio);
	return (radio);
}

t_gui	*build_gui_scene(char *name, t_vec2i screen_size)
{
	t_gui *scene;

	if (!(scene = set_new_gui(name, screen_size.x, screen_size.y)))
		return (console(FATAL, __func__, __LINE__, "init fail").null);
	return (scene);
}