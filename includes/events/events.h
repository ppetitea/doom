/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:48:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/25 15:57:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "resources/game.h"

typedef struct		s_drag_observer
{
	t_list_head		node;
	t_list_head		*drag_list;
	t_pos2i			*offset;
	t_vec2i			*size;
	t_result		(*subscribe)(struct s_drag_observer*, t_list_head*);
	t_result		(*unsubscribe)(struct s_drag_observer*);
	t_list_head		start_actions;
	t_list_head		stop_actions;
}					t_drag_observer;

typedef struct		s_select_observer
{
	t_list_head		node;
	t_list_head		*select_list;
	t_result		(*subscribe)(struct s_select_observer*, t_list_head*);
	t_result		(*unsubscribe)(struct s_select_observer*);
	t_list_head		start_actions;
	t_list_head		stop_actions;
}					t_select_observer;

typedef struct		s_hover_observer
{
	t_list_head		node;
	t_list_head		*hover_list;
	t_result		(*subscribe)(struct s_hover_observer*, t_list_head*);
	t_result		(*unsubscribe)(struct s_hover_observer*);
	t_list_head		start_actions;
	t_list_head		stop_actions;
}					t_hover_observer;

typedef struct		s_mouse_collider
{
	t_pos2i				offset;
	t_vec2i				size;
	t_hover_observer	hover;
	t_select_observer	select;
	t_drag_observer		drag;
}					t_mouse_collider;

typedef struct		s_mouse_observable
{
	t_list_head		drag_list;
	t_list_head		hover_list;
	t_list_head		select_list;
}					t_mouse_observable;

typedef struct		s_mouse
{
	t_pos2i				pos;
	t_bool				down;
	t_bool				drag;
	t_mouse_observable	*observable;
}					t_mouse;

typedef struct		s_events
{
	t_mouse		mouse;
}					t_events;
void				handle_events(t_game *game);

#endif