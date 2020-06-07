/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:10:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/06 18:34:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/component.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_component_state(t_component_state *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->z_index = 0;	
	if (self->bg_image)
		free(self->bg_image);
	if (self->font_family)
		free(self->font_family);
	if (self->text)
		free(self->text);
	del_args_list(&self->filters);
	return (OK);
}

t_result del_new_component_state(t_component_state *self)
{
	if (!del_component_state(self))
		return (console(FATAL, __func__, __LINE__, "del_component_state fail").err);
	free(self);
	return (OK);
}

t_result init_component_state(t_component_state *self)
{
	self->z_index = 0;
	self->pos = ft_vec2i(0, 0);
	self->size = ft_vec2i(0, 0);
	self->bg_color = ft_bgra(0, 0, 0, 0);
	self->color = ft_bgra(0, 0, 0, 0);
	self->is_layer_up_to_date = FALSE;
	self->is_visible = TRUE;
	self->is_hover = FALSE;
	self->is_focus = FALSE;
	self->mouse_offset = ft_vec2i(0, 0);
	self->drag_offset = ft_vec2i(0, 0);
	self->is_drag = FALSE;
	self->bg_image = NULL;
	self->font_family = NULL;
	self->text = NULL;
	if (!(init_list_head(&self->filters)))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->destroy = del_component_state;
	return (OK);
};

t_component_state *init_new_component_state()
{
	t_component_state *self;

	if (!(self = malloc(sizeof(t_component_state))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_component_state(self);
	self->destroy = del_new_component_state;
	return (self);
}

// t_result set_component_state(t_component_state *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_component_state *set_new_component_state()
// {
// 	t_component_state *self;

// 	if (!(self = init_new_component_state()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_component_state fail").null);
// 	if (!(set_component_state(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_component_state fail").null);
// 	return (self);
// }
