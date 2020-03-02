/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:39:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 16:46:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"

t_result	transform_anim_on_mouse(t_animation	*anim)
{
	t_mouse	*mouse;
	t_vec2i	anchor;

	if (!(mouse = get_mouse_state()))
		return (throw_error("set_mouse_as_anchor", "Mouse not found"));
	anchor = ft_vec2i(0, 0);
	if (anim->box.parent_box)
		anchor = anim->box.parent_box->offset;
	anim->box.anchor = vec2i_sub(mouse->pos, anchor);
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}

t_result	set_mouse_as_anchor(t_animation *anim)
{
	t_mouse	*mouse;
	t_vec2i	anchor;

	if (!(mouse = get_mouse_state()))
		return (throw_error("set_mouse_as_anchor", "Mouse not found"));
	anchor = ft_vec2i(0, 0);
	if (anim->box.parent_box)
		anchor = anim->box.parent_box->offset;
	anim->box.offset = vec2i_sub(anim->box.render_box.offset, mouse->pos);
	anim->box.anchor = vec2i_sub(mouse->pos, anchor);
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}

t_result	elevate_animation_anchor(t_animation *anim)
{
	anim->box.anchor.y++;
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}

t_result	lower_animation_anchor(t_animation *anim)
{
	anim->box.anchor.y--;
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}
