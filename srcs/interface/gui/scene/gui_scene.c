/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 21:41:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/25 23:08:13 by ppetitea         ###   ########.fr       */
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

t_gui	*build_gui_button(char *name, t_vec2i size, t_pos2i pos)
{
	t_gui *button;

	if (!(button = set_new_gui(name, size.x, size.y)))
		return (console(FATAL, __func__, __LINE__, "init fail").null);
	button->pos = pos;
	return (button);
}

t_gui	*build_gui_scene(char *name, t_vec2i screen_size)
{
	t_gui *scene;

	if (!(scene = set_new_gui(name, screen_size.x, screen_size.y)))
		return (console(FATAL, __func__, __LINE__, "init fail").null);
	return (scene);
}