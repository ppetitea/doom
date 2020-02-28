/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:57:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 18:20:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "containers/list.h"
#include "graphic/animation.h"
#include "events/observer.h"
#include "utils/error.h"


t_result	init_animation_collide(t_animation_collide *self,
				t_animation_box *box)
{
	if (self == NULL || box == NULL)
		return (throw_error("init_collide", "NULL pointer provided"));
	init_mouse_observer(&self->hover);
	self->hover.render_box = &box->render_box;
	init_mouse_observer(&self->select);
	self->select.render_box = &box->render_box;
	init_mouse_observer(&self->drag);
	self->drag.render_box = &box->render_box;
	init_mouse_observer(&self->draw);
	self->draw.render_box = &box->render_box;
	return (OK);
}

t_result		init_animation_box(t_animation_box *self)
{
	if (self == NULL)
		return (throw_error("init_animation_box", "NULL pointer provided"));
	self->parent_box = NULL;
	self->anchor = ft_pos2i(0, 0);
	self->offset = ft_pos2i(0, 0);
	self->render_box.offset = ft_pos2i(0, 0);
	self->render_box.size = ft_vec2i(1, 1);
	return (OK);
}

t_result	init_animation(t_animation *self)
{
	if (self == NULL)
		return (throw_error("init_animation", "NULL pointer provided"));
	init_list_head(&self->node);
	self->state = STOP;
	gettimeofday(&self->last, NULL);
	init_animation_box(&self->box);
	init_animation_collide(&self->collide, &self->box);
	self->curr = NULL;
	init_list_head(&self->textures);
	self->list = NULL;
	self->subscribe = animation_subscribe;
	self->unsubscribe = animation_unsubscribe;
	self->suscribed = FALSE;
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
