/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 21:41:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/29 00:36:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "interface/build.h"
#include "image/image.h"
#include "log/log.h"

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
	t_arg		arg;
	t_list_head	*list;

	arg.pointer = gui;
	list = &gui->hover_start.actions;
	add_new_action(list, lighten_gui_layer, "lighten", arg);
	arg.pointer = &gui->hover_start;
	add_new_action(list, mouse_obs_unsubscribe, "unsubscribe", arg);
	arg.pointer = &gui->hover_end;
	add_new_action(list, mouse_obs_subscribe, "subscribe", arg);
	mouse_obs_subscribe(&gui->hover_start);
	list = &gui->hover_end.actions;
	arg.pointer = gui;
	add_new_action(list, filter_reset_gui_layer, "filterReset", arg);
	arg.pointer = &gui->hover_end;
	add_new_action(list, mouse_obs_unsubscribe, "unsubscribe", arg);
	arg.pointer = &gui->hover_start;
	add_new_action(list, mouse_obs_subscribe, "subscribe", arg);
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
	t_arg			arg;

	list = &checkbox->left_down.actions;
	arg.pointer = checkbox;
	add_new_action(list, toogle_colorize_gui, "toogle_color", arg);
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

t_result	build_radio_default_events(t_gui *radio, t_list_head *radio_list)
{
	t_action_node	*action;
	t_list_head		*list;
	t_arg			arg;

	list = &radio->left_down.actions;
	arg.pointer = radio;
	add_new_action(list, check_gui, "check_gui", arg);
	action = add_new_action(list, checkout_gui_list, "checkout_gui_list", arg);
	arg.pointer = radio_list;
	add_action_arg(action, arg);
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