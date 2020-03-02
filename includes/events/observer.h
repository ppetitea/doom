/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:56:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 17:09:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_H
# define OBSERVER_H

# include "events/keyboard.h"
# include "events/mouse.h"
# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"
# include "SDL_keycode.h"
# include "SDL_events.h"

typedef struct	s_box
{
	t_pos2i		offset;
	t_vec2i		size;
}				t_box;

typedef struct		s_mouse_observer
{
	t_list_head		node;
	t_box			*render_box;
	t_list_head		*list;
	t_result		(*subscribe)(struct s_mouse_observer*);
	t_result		(*unsubscribe)(struct s_mouse_observer*);
	t_bool			subscribed;
	t_bool			active;
	t_list_head		actions;
}					t_mouse_observer;
t_result			init_mouse_observer(t_mouse_observer *self);


typedef struct	s_mouse_observers
{
	t_mouse_observer	hover_start;
	t_mouse_observer	hover_end;
	t_mouse_observer	left_up;
	t_mouse_observer	left_down;
	t_mouse_observer	right_up;
	t_mouse_observer	right_down;
	t_mouse_observer	drag;
	t_mouse_observer	drop;
	t_mouse_observer	motion;
	t_mouse_observer	wheel_normal;
	t_mouse_observer	wheel_flip;
}				t_mouse_observers;

typedef struct		s_mouse_followers
{
	t_list_head		hover_start;
	t_list_head		hover_end;
	t_list_head		right_down;
	t_list_head		right_up;
	t_list_head		left_down;
	t_list_head		left_up;
	t_list_head		drag;
	t_list_head		drop;
	t_list_head		motion;
	t_list_head		wheel_normal;
	t_list_head		wheel_flip;
}					t_mouse_followers;
t_result			init_mouse_followers(t_mouse_followers *self);

typedef struct		s_mouse_observable
{
	t_mouse				state;
	t_mouse_followers	followers;
}					t_mouse_observable;
t_result			init_mouse_observable(t_mouse_observable *self);

/*
** mouse handle
*/

void			handle_mouse_motion(t_mouse_observable *mouse,
					SDL_MouseMotionEvent event);
void			handle_mouse_down(t_mouse_observable *mouse,
					SDL_MouseButtonEvent event);
void			handle_mouse_up(t_mouse_observable *mouse,
					SDL_MouseButtonEvent event);
void			handle_mouse_wheel(t_mouse_observable *mouse,
					SDL_MouseWheelEvent event);
/*
** mouse getters
*/
t_mouse_observable	*get_mouse_observable();
t_mouse_followers	*get_mouse_followers();
t_mouse				*get_mouse_state();

/*
** mouse update
*/
t_result			update_mouse_observers_lists(t_mouse_observers *mouse_obs,
						t_mouse_followers *followers);


/*
** keyboard
*/
typedef struct		s_keyboard_observer
{
	t_list_head		node;
	SDL_Keycode		key;
	t_list_head		*list;
	t_result		(*subscribe)(struct s_keyboard_observer*, t_list_head*);
	t_result		(*unsubscribe)(struct s_keyboard_observer*);
	t_bool			subscribed;
	t_list_head		start_actions;
	t_list_head		stop_actions;
}					t_keyboard_observer;
t_result			init_keyboard_observer(t_keyboard_observer *self);

typedef struct		s_keyboard_observable
{
	t_keyboard		*state;
	t_list_head		press;
	t_list_head		hold;
}					t_keyboard_observable;
t_result			init_keyboard_observable(t_keyboard_observable *self);

/*
** sub
*/
t_result			mouse_observer_subscribe(t_mouse_observer *self);
t_result			mouse_observer_unsubscribe(t_mouse_observer *self);

/*
** trigger
*/
t_bool				trigger_mouse_observers(t_list_head *observers);
t_bool				trigger_mouse_mouse_obs_on(t_list_head *observers,
						t_mouse mouse);
t_bool				trigger_mouse_mouse_obs_off(t_list_head *observers,
						t_mouse mouse);

#endif
