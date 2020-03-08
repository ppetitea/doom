/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:56:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:40:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_H
# define OBSERVER_H

# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"
# include "SDL_keycode.h"
# include "SDL_events.h"

/*
** init
*/
typedef struct		s_observer
{
	t_list_head		node;
	t_list_head		*list;
	t_result		(*subscribe)(struct s_observer*);
	t_result		(*unsubscribe)(struct s_observer*);
	t_bool			subscribed;
	t_bool			active;
	t_list_head		actions;
}					t_observer;
t_result			init_observer(t_observer *self);
t_result			set_observer(t_observer *self, t_list_head *list,
						t_bool subscribe);

typedef struct		s_time_observer
{
	t_list_head		node;
	double			seconds;
	t_list_head		*list;
	t_result		(*subscribe)(struct s_time_observer*);
	t_result		(*unsubscribe)(struct s_time_observer*);
	t_bool			subscribed;
	t_bool			active;
	t_list_head		actions;
}					t_time_observer;
t_result			init_time_observer(t_time_observer *self);
t_result			set_time_observer(t_time_observer *self, t_list_head *list,
						t_bool subscribe, double seconds);

/*
** sub
*/
t_result			observer_subscribe(t_observer *self);
t_result			observer_unsubscribe(t_observer *self);
t_result			time_observer_subscribe(t_time_observer *self);
t_result			time_observer_unsubscribe(t_time_observer *self);

/*
** trigger
*/
t_bool				trigger_observers(t_list_head *observers);
t_bool				trigger_time_observers(t_list_head *observers);


#endif
