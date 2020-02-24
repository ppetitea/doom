/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:56:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 14:13:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_H
# define OBSERVER_H

# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"

// typedef struct			s_hover_observer
// {
// 	t_list_head			node;
// 	t_vec2i				*offset;
// 	t_vec2i				*size;
// 	t_list_head			*hoverable_list;
// 	t_bool				is_subscribed;
// 	t_bool				is_hover;
// 	//t_result			*start(resource, type, arg);
// 	//t_result			*end(resource, type, arg);
// }						t_hover_observer;
// t_result				init_hover_observer(t_hover_observer *self);

// typedef struct			s_select_observer
// {
// 	t_list_head			node;
// 	t_vec2i				*offset;
// 	t_vec2i				*size;
// 	t_list_head			*selectable_list;
// 	t_bool				is_subscribed;
// 	t_bool				is_selected;
// 	// t_result			*start(resource, type, arg);
// 	//t_result			*end(resource, type, arg);
// }						t_select_observer;
// t_result				init_select_observer(t_select_observer *self);

// typedef struct			s_drag_observer
// {
// 	t_list_head			node;
// 	t_vec2i				*offset;
// 	t_vec2i				*size;
// 	t_list_head			*draggable_list;
// 	t_bool				is_subscribed;
// 	t_bool				is_dragged;
// 	// t_result			*start(resource, type, arg);
// 	//t_result			*end(resource, type, arg);
// }						t_drag_observer;
// t_result				init_drag_observer(t_drag_observer *self);

typedef struct		s_mouse_collide_observer
{
	t_list_head		node;
	t_vec2i			*offset;
	t_vec2i			*size;
	t_list_head		*suscribe_list;
	t_bool			is_subscribed;
	t_bool			is_active;
	t_list_head		start;
	t_list_head		stop;
}					t_mouse_collide_observer;
t_result			init_mouse_collide_observer(t_mouse_collide_observer *self);

typedef struct		s_mouse_collide
{
	t_vec2i						offset;
	t_vec2i						size;
	t_mouse_collide_observer	hover;
	t_mouse_collide_observer	select;
	t_mouse_collide_observer	drag;
}					t_mouse_collide;
t_result			init_mouse_collide(t_mouse_collide *self);


#endif