/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:13:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:41:02 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "types.h"
# include "SDL_keycode.h"
# include "events/observer.h"


typedef struct	s_keyboard
{
	t_bool		w;
	t_bool		a;
	t_bool		s;
	t_bool		d;
	SDL_Keycode	key;
}				t_keyboard;

typedef struct		s_keyboard_observer
{
	t_list_head		node;
	SDL_Keycode		key;
	t_list_head		*list;
	t_result		(*subscribe)(struct s_keyboard_observer*);
	t_result		(*unsubscribe)(struct s_keyboard_observer*);
	t_bool			subscribed;
	t_bool			active;
	t_list_head		actions;
}					t_keyboard_observer;
t_result			init_keyboard_observer(t_keyboard_observer *self);
t_result			set_keyboard_observer(t_keyboard_observer *self,
						t_list_head *list, SDL_Keycode key, t_bool subscribe);

typedef struct	s_keyboard_observers
{
	t_keyboard_observer	down;
	t_keyboard_observer	up;
}				t_keyboard_observers;

typedef struct		s_keyboard_followers
{
	t_list_head	down;
	t_list_head	up;
}					t_keyboard_followers;
t_result			init_keyboard_followers(t_keyboard_followers *self);

typedef struct		s_keyboard_observable
{
	t_keyboard				state;
	t_keyboard_followers	followers;
}					t_keyboard_observable;
t_result			init_keyboard_observable(t_keyboard_observable *self);

/*
** keyboard handle
*/

void			handle_keyboard_down(t_keyboard_observable *keyboard,
					SDL_KeyboardEvent event);
void			handle_keyboard_up(t_keyboard_observable *keyboard,
					SDL_KeyboardEvent event);
/*
** keyboard getters
*/
t_keyboard_observable	*get_keyboard_observable();
t_keyboard_followers	*get_keyboard_followers();
t_keyboard				*get_keyboard_state();

/*
** keyboard update
*/
t_result			update_keyboard_observers_lists(
						t_keyboard_observers *keyboard_obs,
						t_keyboard_followers *followers);

/*
** sub
*/
t_result			keyboard_observer_subscribe(t_keyboard_observer *self);
t_result			keyboard_observer_unsubscribe(t_keyboard_observer *self);

/*
** trigger
*/
t_bool				trigger_keyboard_observers(t_list_head *observers);
t_bool				trigger_keyboard_observers_on(t_list_head *observers,
						t_keyboard keyboard);

#endif