/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:04:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/19 22:55:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_EVENT_H
# define GUI_EVENT_H

# include "containers/node.h"
# include "containers/list.h"
# include "image/image.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"
# include "SDL_keycode.h"
# include "colors/color.h"
# include "action/action.h"
# include "SDL_ttf.h"
# include "SDL_surface.h"
# include "data/data.h"

typedef enum	e_mouse_button
{
	MOUSE_LEFT,
	MOUSE_RIGHT,
	MOUSE_WHEEL,
}				t_mouse_button;

typedef enum	e_mouse_e_type
{
	MOUSE_UP,
	MOUSE_DOWN,
	MOUSE_MOTION,
	MOUSE_WHEEL_NORMAL,
	MOUSE_WHEEL_FLIP,
}				t_mouse_e_type;

/*
** mouse state
** followed by component to up to date its own state
*/
typedef struct	s_mouse_state
{
	int				x;
	int				y;
	float			wheel;
	t_vec2f			velocity;
	t_bool			is_press;
	t_bool			is_move;
	t_bool			is_clic;
	t_bool			is_drag;
	t_mouse_button	button;
	t_mouse_e_type	type;
}				t_mouse_state;

typedef struct	s_mouse
{
	t_mouse_state	last;
	t_mouse_state	curr;
}				t_mouse;

/*
** key state
** followed by component to up to date its own state
*/
typedef struct	s_keys_state
{
	t_list_head		up;
	t_list_head		down;
}				t_keys_state;

typedef struct	s_keys
{
	t_keys_state	last;
	t_keys_state	curr;
}				t_keys;

/*
** L'event est passe a tout l'arbre de composants des feuilles a la racine
** comparer avec les event enregistre dans chaque component
*/
typedef struct	s_event
{
	t_mouse			mouse;
	t_keys			keys;
}				t_event;

/*
**  Faire en sorte qu'un component puisse recevoir un event sur le "flux input"
** 
**  Faire en sorte qu'un button de type radio peu envoyer un event sur le "flux radio"
**  auxquels sont abonne tous les button de type radio
** 
**  Faire en sorte que un component parent puisse envoyer un event
**  a tous ses enfants
**  a tous ses enfants de profondeur 2
**  a tous ses enfants jusqu'a la profondeur 3
** 
**  Drag un component du clic gauche et le drop du clic droit
** 
*/

typedef struct	s_component_event
{
	t_list_head		node;
	char			*target;
	t_list_head		actions;
}				t_component_event;

/*
**	Component drag event
**	if (mouse.last.is_drag == false && mouse.curr.is_drag == true
**		&& component.is_hover == true)
**		component->is_drag = true;
*/

typedef struct	s_component_state
{
	t_pos2i		pos;
	t_vec2i		size;
	t_bgra		bg_color;
	t_bgra		color;
	t_bool		is_up_to_date;
	t_bool		is_visible;
	t_bool		is_hover;
	t_bool		is_focus;
	t_pos2i		mouse_offset;
	t_bool		is_drag;
}				t_component_state;

typedef struct	s_component
{
	t_node				node;
	char				*id;
	t_list_head			radio;
	char				*bg_image;
	char				*font_family;
	TTF_Font			*font;
	char				*text;
	SDL_Surface			*text_surface;
	t_layer				layer;
	t_filter			filter;
	t_component_state	last;
	t_component_state	curr;
	t_list_head			listeners;
	int					z_index;
}				t_component;

typedef struct	s_listener
{
	t_list_head		node;
	char			*name;
	t_list_head		*list;
	t_bool			is_listen;
	void			*gui;
	t_list_head		conditions;
	t_mouse			mouse;
	t_keys			keys;
	t_list_head		actions;
}				t_listener;

t_bool		condition(t_listener *listener, t_event *event);


#endif