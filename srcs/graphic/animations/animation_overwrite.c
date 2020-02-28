/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_overwrite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:53:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 11:40:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "events/action.h"
#include "utils/error.h"
#include "utils/parser.h"

t_result	update_animation_collide(t_animation_collide *collide,
				t_obj *collide_obj, t_mouse_observable *mouse)
{
	t_list_head		*pos;
	t_action_node	*action;

	if (collide == NULL || collide_obj == NULL)
		return (throw_error("update_animation_collide", "NULL pointer"));
	pos = (t_list_head*)collide_obj->value;
	while ((pos = pos->next) != (t_list_head*)collide_obj->value)
	{
		if ((action = init_new_action()))
		{
			// build_action_fn()
			// build_action_args()
			// list_add_entry(&action->node, &mouse->followers.hover);
		}
	}
	return (OK);
}

t_result	overwrite_animation(t_animation *self, t_obj *anim_obj,
				t_mouse_observable *mouse)
{
	t_vec2i	vec2i;
	t_bool	boolean;

	if (self == NULL || anim_obj == NULL)
		return (throw_error("overwrite_animation", "NULL pointer provided"));
	build_animation_status(&self->state, anim_obj);
	if (init_vec2i_with_obj(&vec2i, get_child_list(anim_obj, "anchor")))
		self->box.anchor = vec2i;
	if ((boolean = get_int_child(anim_obj, "display", -1)) != -1)
		self->suscribed = boolean ? TRUE : FALSE;
	return (OK);
}
