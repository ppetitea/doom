/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:56:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 17:22:32 by ppetitea         ###   ########.fr       */
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
	t_result		(*suscribe)(struct s_mouse_observer*);
	t_result		(*unsuscribe)(struct s_mouse_observer*);
	t_bool			suscribed;
	t_bool			active;
	t_list_head		start_actions;
	t_list_head		stop_actions;
}					t_mouse_observer;
t_result			init_mouse_observer(t_mouse_observer *self);

typedef struct		s_mouse_followers
{
	t_list_head		hover;
	t_list_head		select;
	t_list_head		drag;
	t_list_head		draw;
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
void			handle_mouse_down(t_mouse_observable *mouse,
					SDL_MouseButtonEvent event);

/*
** keyboard
*/
typedef struct		s_keyboard_observer
{
	t_list_head		node;
	SDL_Keycode		key;
	t_list_head		*list;
	t_result		(*suscribe)(struct s_keyboard_observer*, t_list_head*);
	t_result		(*unsuscribe)(struct s_keyboard_observer*);
	t_bool			suscribed;
	t_bool			active;
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


#endif
