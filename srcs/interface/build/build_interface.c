/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:14:56 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/03 23:48:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/build.h"
#include "ft/str.h"
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

SDL_Keycode	interface_get_key()
{
	t_gui_interface *gui_interface;

	gui_interface = interface();
	return (gui_interface->key);
}

t_result	add_letter_to_text(t_gui *gui, char letter)
{
	char	l[2];	
	char	*new;

	l[0] = letter;
	l[1] = '\0';
	if (!(new = ft_strjoin(gui->text, &(l[0]))))
			return (console(FATAL, __func__, __LINE__, "strjoin fail").err);
	set_gui_text(gui, new, gui->color);
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	free(new);
	return (OK);
}

t_result	remove_letter_to_text(t_gui *gui)
{
	char	*new;
	int		len;

	if (gui->text == NULL)
		set_gui_text(gui, "", gui->color);
	else if (*gui->text == '\0')
		return (OK);
	else if ((len = ft_strlen(gui->text)) < 2)
		set_gui_text(gui, "", gui->color);
	else
	{
		if (!(new = ft_strndup(gui->text, len -1)))
			return (console(FATAL, __func__, __LINE__, "strndup fail").err);
		set_gui_text(gui, new, gui->color);
		free(new);
	}
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	update_gui_text(t_gui *gui)
{
	char	l;	

	l = (char)interface_get_key();
	if (SDLK_SPACE <= l && l <= SDLK_z)
		add_letter_to_text(gui, l);
	else if (l == SDLK_BACKSPACE)
		remove_letter_to_text(gui);
	return (OK);
}
