/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 14:20:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/30 00:49:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "log/log.h"
#include "maths/vec2i.h"
#include "data/data.h"

t_gui *build_start_button(t_gui_interface *interface, t_gui *home)
{
	t_gui		*start;
	t_pos2i		pos;
	t_pos2i		size;

	pos = vec2i_mult(home->size, 0.5f);
	size = vec2i_mult(home->size, 0.2f);
	if (!(start = build_gui_button("Start button", pos, size, interface)))
		return (console(FATAL, __func__, __LINE__, "build_button fail").null);
	start->bg_color = ft_bgra(150, 50, 100, 255);
	start->display = TRUE;
	node_add_child(&home->node, &start->node);
	(void)interface;
	return (start);
}

t_gui *build_random_checkbox(t_gui_interface *interface, t_gui *home)
{
	t_gui		*checkbox;
	t_pos2i		pos;
	t_pos2i		size;

	pos = vec2i_mult(home->size, 0.9f);
	size = ft_vec2i(20, 20);
	if (!(checkbox = build_gui_checkbox("Checkbox", pos, size, interface)))
		return (console(FATAL, __func__, __LINE__, "build_checkbox fail").null);
	checkbox->display = TRUE;
	node_add_child(&home->node, &checkbox->node);
	(void)interface;
	return (checkbox);
}

t_gui *build_radio1(t_gui_interface *interface, t_gui *home)
{
	t_arg			*string;
	t_arg			*list;
	t_gui			*radio;
	t_pos2i			pos;
	t_pos2i			size;

	pos = vec2i_mult(home->size, 0.1f);
	size = ft_vec2i(20, 20);
	if (!(radio = build_gui_radio("radio1", pos, size, interface)))
		return (console(FATAL, __func__, __LINE__, "build_radio fail").null);
	if (!(list = set_new_arg(ARG_LIST, (t_argv)NULL)) && del_gui(&radio->node))
		return (console(FATAL, __func__, __LINE__, "new_arg fail").null);
	if ((string = set_new_arg(ARG_STRING, (t_argv)"radio2")))
		node_add_child(&list->node, &string->node);
	if ((string = set_new_arg(ARG_STRING, (t_argv)"radio3")))
		node_add_child(&list->node, &string->node);
	build_radio_default_events(radio, list);
	radio->display = TRUE;
	radio->bg_color = ft_bgra(82, 216, 105, 255);
	node_add_child(&home->node, &radio->node);
	(void)interface;
	return (radio);
}

t_gui *build_radio2(t_gui_interface *interface, t_gui *home)
{
	t_arg			*string;
	t_arg			*list;
	t_gui			*radio;
	t_pos2i			pos;
	t_pos2i			size;

	pos = vec2i_mult(home->size, 0.2f);
	size = ft_vec2i(20, 20);
	if (!(radio = build_gui_radio("radio2", pos, size, interface)))
		return (console(FATAL, __func__, __LINE__, "build_radio fail").null);
	if (!(list = set_new_arg(ARG_LIST, (t_argv)NULL)) && del_gui(&radio->node))
		return (console(FATAL, __func__, __LINE__, "new_arg fail").null);
	if ((string = set_new_arg(ARG_STRING, (t_argv)"radio1")))
		node_add_child(&list->node, &string->node);
	if ((string = set_new_arg(ARG_STRING, (t_argv)"radio3")))
		node_add_child(&list->node, &string->node);
	build_radio_default_events(radio, list);
	radio->display = TRUE;
	node_add_child(&home->node, &radio->node);
	(void)interface;
	return (radio);
}

t_gui *build_radio3(t_gui_interface *interface, t_gui *home)
{
	t_arg			*string;
	t_arg			*list;
	t_gui			*radio;
	t_pos2i			pos;
	t_pos2i			size;

	pos = vec2i_mult(home->size, 0.3f);
	size = ft_vec2i(20, 20);
	if (!(radio = build_gui_radio("radio3", pos, size, interface)))
		return (console(FATAL, __func__, __LINE__, "build_radio fail").null);
	if (!(list = set_new_arg(ARG_LIST, (t_argv)NULL)) && del_gui(&radio->node))
		return (console(FATAL, __func__, __LINE__, "new_arg fail").null);
	if ((string = set_new_arg(ARG_STRING, (t_argv)"radio1")))
		node_add_child(&list->node, &string->node);
	if ((string = set_new_arg(ARG_STRING, (t_argv)"radio2")))
		node_add_child(&list->node, &string->node);
	build_radio_default_events(radio, list);
	radio->display = TRUE;
	node_add_child(&home->node, &radio->node);
	(void)interface;
	return (radio);
}

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
	build_start_button(interface, home);
	build_random_checkbox(interface, home);
	build_radio1(interface, home);
	build_radio2(interface, home);
	build_radio3(interface, home);
	node_add_prev(&interface->scenes, &home->node);
	return (home);
}
