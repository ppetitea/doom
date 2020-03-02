/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_observer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:33:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 16:34:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"

t_result	animation_hover_start(t_animation *anim)
{
	anim->mouse_obs.hover_start.unsubscribe(&anim->mouse_obs.hover_start);
	anim->mouse_obs.hover_end.subscribe(&anim->mouse_obs.hover_end);
	return (OK);
}
t_result	animation_hover_end(t_animation *anim)
{
	anim->mouse_obs.hover_end.unsubscribe(&anim->mouse_obs.hover_end);
	anim->mouse_obs.hover_start.subscribe(&anim->mouse_obs.hover_start);
	return (OK);
}
t_result	animation_wheel_start(t_animation *anim)
{
	anim->mouse_obs.wheel_normal.subscribe(&anim->mouse_obs.wheel_normal);
	anim->mouse_obs.wheel_flip.subscribe(&anim->mouse_obs.wheel_flip);
	return (OK);
}
t_result	animation_wheel_end(t_animation *anim)
{
	anim->mouse_obs.wheel_normal.unsubscribe(&anim->mouse_obs.wheel_normal);
	anim->mouse_obs.wheel_flip.unsubscribe(&anim->mouse_obs.wheel_flip);
	return (OK);
}
t_result	animation_drag_start(t_animation *anim)
{
	anim->mouse_obs.drag.unsubscribe(&anim->mouse_obs.drag);
	anim->mouse_obs.motion.subscribe(&anim->mouse_obs.motion);
	anim->mouse_obs.drop.subscribe(&anim->mouse_obs.drop);
	return (OK);
}
t_result	animation_drag_end(t_animation *anim)
{
	anim->mouse_obs.drop.unsubscribe(&anim->mouse_obs.drop);
	anim->mouse_obs.motion.unsubscribe(&anim->mouse_obs.motion);
	anim->mouse_obs.drag.subscribe(&anim->mouse_obs.drag);
	return (OK);
}