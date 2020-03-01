/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_collide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:56:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 12:18:01 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"

t_result	update_animation_collide_lists(t_animation *anim,
				t_mouse_followers *followers)
{
	if (anim == NULL || followers == NULL)
		return (throw_error("add_animation_collide_lists", "NULL pointer"));
	anim->collide.hover_start.list = &followers->hover_start;
	anim->collide.hover_stop.list = &followers->hover_stop;
	anim->collide.select.list = &followers->select;
	anim->collide.drag.list = &followers->drag;
	anim->collide.drop.list = &followers->drop;
	anim->collide.motion.list = &followers->motion;
	return (OK);
}
