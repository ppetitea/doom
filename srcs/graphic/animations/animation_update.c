/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:07:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 14:18:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"

t_result	update_animation_render_box(t_animation *anim)
{
	t_vec2i	offset;

	anim->box.offset = anim->curr->offset;
	anim->box.render_box.size = anim->curr->size;
	offset = ft_vec2i(0, 0);
	if (anim->box.parent_box)
		offset = anim->box.parent_box->offset;
	offset = vec2i_add(offset, anim->box.anchor);
	offset = vec2i_add(offset, anim->box.offset);
	anim->box.render_box.offset = offset;
	return (OK);
}