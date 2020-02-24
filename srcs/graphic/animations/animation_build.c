/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:53:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:41:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"
#include "utils/parser.h"

static t_result	build_animation_status(t_animation_status *self,
				t_dnon_object *anim_obj)
{
	if (self == NULL || anim_obj == NULL)
		return (throw_error("build_animation_status", "NULL pointer provided"));
	if (strcmp_obj("animation", "stop", anim_obj))
		*self = STOP;
	else if (strcmp_obj("animation", "in_progress", anim_obj))
		*self = IN_PROGRESS;
	else if (strcmp_obj("animation", "final", anim_obj))
		*self = FINAL;
	else if (strcmp_obj("animation", "ephemeral", anim_obj))
		*self = EPHEMERAL;
	else if (strcmp_obj("animation", "infinite", anim_obj))
		*self = INFINITE;
	else
		*self = NONE;
	return (OK);
}

t_result	build_animation(t_animation *self, t_dnon_object *anim_obj)
{
	t_vec2i	vec2i;
	t_bool	boolean;

	if (self == NULL || anim_obj == NULL)
		return (throw_error("build_animation", "NULL pointer provided"));
	if (!build_textures(&self->textures,
			get_child_list(anim_obj, "textures")))
		return (throw_error("build_animation", "Fail to build_textures"));
	if (list_lenght(&self->textures) == 0)
		return (throw_error("build_animation", "Texture list is empty"));
	build_animation_status(&self->state, anim_obj);
	if (init_vec2i_with_obj(&vec2i, get_child_list(anim_obj, "anchor")))
		self->anchor = vec2i;
	if ((boolean = get_int_value_by_key(anim_obj, "display", -1)) != -1)
		self->is_render = boolean ? TRUE : FALSE;
	return (OK);
}
