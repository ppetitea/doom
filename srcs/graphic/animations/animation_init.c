/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:57:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 01:19:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "containers/list.h"
#include "graphic/animation.h"
#include "events/observer.h"
#include "utils/error.h"

t_result	init_mouse_collide_observer(t_mouse_collide_observer *self)
{
	if (self == NULL)
		return (throw_error("init_observer", "NULL pointer provided"));
	init_list_head(&self->node);
	self->offset = NULL;
	self->size = NULL;
	self->suscribe_list = NULL;
	self->is_subscribed = FALSE;
	self->is_active = FALSE;
	return (OK);
}

t_result	init_mouse_collide(t_mouse_collide *self)
{
	if (self == NULL)
		return (throw_error("init_collide", "NULL pointer provided"));
	self->offset = ft_pos2i(0, 0);
	self->size = ft_pos2i(1, 1);
	init_mouse_collide_observer(&self->hover);
	self->hover.offset = &self->offset;
	self->hover.size = &self->size;
	init_mouse_collide_observer(&self->select);
	self->select.offset = &self->offset;
	self->select.size = &self->size;
	init_mouse_collide_observer(&self->drag);
	self->drag.offset = &self->offset;
	self->drag.size = &self->size;
	return (OK);
}

t_result	init_animation(t_animation *self)
{
	if (self == NULL)
		return (throw_error("init_animation", "NULL pointer provided"));
	self->state = STOP;
	gettimeofday(&self->last, NULL);
	self->curr = NULL;
	init_list_head(&self->textures);
	self->anchor = ft_pos2i(0, 0);
	init_mouse_collide(&self->collide);
	return (OK);
}

t_result	init_oriented_animations(t_oriented_animations *self)
{
	if (self == NULL)
		return (throw_error("init_oriented_animation", "NULL pointer"));
	init_animation(&self->f);
	init_animation(&self->fr);
	init_animation(&self->fl);
	init_animation(&self->r);
	init_animation(&self->l);
	init_animation(&self->b);
	init_animation(&self->br);
	init_animation(&self->bl);
	return (OK);
}
