/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:03:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 12:15:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "utils/error.h"

t_result	init_scene_gui(t_scene_gui *self)
{
	if (self == NULL)
		return (throw_error("init_scene_gui", "NULL pointer provided"));
	init_new_animation(&self->background);
	init_list_head(&self->buttons);
	init_list_head(&self->canvas);
	init_list_head(&self->render_list);
	return (OK);
}

t_result	init_scene_events(t_scene_events *self)
{
	if (self == NULL)
		return (throw_error("init_scene_events", "NULL pointer provided"));
	init_mouse_observable(&self->mouse);
	init_keyboard_observable(&self->keyboard);
	init_list_head(&self->loop);
	init_list_head(&self->timed);
	init_keyboard_observer(&self->quit);
	return (OK);
}

t_scene		*init_new_scene()
{
	t_scene	*self;

	if (!(self = malloc(sizeof(t_scene))))
		return (throw_null("init_new_scene", "malloc failed"));
	init_list_head(&self->node);
	self->name = NULL;
	init_scene_gui(&self->gui);
	init_scene_events(&self->events);
	return (self);
}
