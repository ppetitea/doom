/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:25:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:41:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/button.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "ft/str.h"

static t_button	*build_new_button(t_dnon_object *button_obj)
{
	t_button	*self;

	if (button_obj == NULL)
		return (throw_null("build_new_button", "NULL pointer provided"));
	if (!(self = init_new_button()))
		return (throw_null("build_new_button", "init_new_button failed"));
	if (!(self->name = ft_strdup(button_obj->key)))
		return (throw_null("build_new_button", "ft_strdup failed"));
	if (!build_animation(&self->animation,
		get_child_list(button_obj, "animation")))
		return (throw_null("build_new_button", "Fail to build_animation"));
	return (self);
}

t_result	build_new_buttons(t_list_head *buttons, char *path)
{
	t_dnon_object	*buttons_obj;
	t_dnon_object	*button_obj;
	t_button		*button;
	t_list_head		*pos;

	if (buttons == NULL || path == NULL)
		return (throw_error("build_new_buttons", "NULL pointer provided"));
	if (!(buttons_obj = parse_dnon_file(path)))
		return (throw_error("build_new_buttons", "buttons.doom: parsing fail"));
	if (buttons_obj->type != LIST)
		return (throw_error("resources_load_buttons", "obj isn't list"));
	pos = (t_list_head*)buttons_obj->value;
	while ((pos = pos->next) != (t_list_head*)buttons_obj->value)
	{
		button_obj = (t_dnon_object*)pos;
		if ((button = build_new_button(button_obj)))
			list_add_entry(&button->node, buttons);
	}
	return (OK);
}