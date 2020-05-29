/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:04:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/29 12:58:46 by ppetitea         ###   ########.fr       */
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

/*
** L'event est passe a tout l'arbre de composants des feuilles a la racine
** comparer avec les event enregistre dans chaque component
*/
/*
**  Faire en sorte de ne pas allouer de memoire dynamiquement au milieu du programme ~ je sais pas trop je me tate pour cette regle ~ je pense que c'est trop restrictif
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
** 
** Chaque event est fournit a l'ensemble de l'arbre si la function handle_event() return CONTINUE
** 
** 
** 
** 
** 
*/


/*	Observables
** 
** l'interface observe/s'abonne aux observable de type
		- input (mouse, keyboard)
		- component
** Les components observent/s'abonnent aux observables de l'interface
** 
** 
*/

/*
** @streams = ARG_STRING -> char* || ARG_INT -> t_event_stream_type
** l'event transmis n'est qu'un etat ou un flag(ENUM)
** Il n'y a pas d'action enregistre dans l'event || pitetre que ce serait interessant dans certains cas
** dans le cas de la souris et du clavier lesw events ne sont destroy qu'a la fin du programme
** 
** 
** event.name = "radio_component_uncheck"
**	t_bool	event_name_match(t_arg_list args, t_event *event, void *observer_ref)		// CONDITION
**	{
**		t_argv name;
**		
**		name = get_arg(args, 0);
**		if (event.name == name.s) // "radio_component_uncheck"
**			return (TRUE);
**		return (FALSE);
**	}
**
**	t_result	component_uncheck(t_arg_list *args, t_event *event, void *observer_ref)	// ACTION
**	{
**		t_component *component;
**		
**		component = (t_component*)observer_ref;
**		component->curr.isChecked = FALSE;
**		component->up_to_date = FALSE;
**		return (OK);
**	}
** 
** 
**	event.name = "mouse_motion"
**	t_bool	event_name_match(t_arg_list args, t_event *event, void *observer_ref)		// CONDITION
**	{
**		t_argv		name;
**		
**		name = get_arg(args, 0);
**		if (event.name == name.s) // "mouse_motion"
**			return (TRUE);
**		return (FALSE);
**	}
**
**	t_result	component_set_mouse_offset(t_arg_list *args, t_event *event, void *observer_ref)	// ACTION
**	{
**		t_component *component;
**		t_mouse		*mouse;
**
**		component = (t_component*)observer_ref;
**		mouse = (t_mouse*)event->observable_ref;
**		component->curr.mouse_offset = vec2i_sub(mouse.pos, component->curr.pos);
**		component->up_to_date = FALSE;
**		return (OK);
**	}
**
**	t_bool	event_name_match(t_arg_list args, t_event *event, void *observer_ref)		// CONDITION
**	{
**		t_argv		name;
**		
**		name = get_arg(args, 0);
**		if (event.name == name.s) // "mouse_motion"
**			return (TRUE);
**		return (FALSE);
**	}
**
**	t_bool	component_is_hover(t_arg_list args, t_event *event, void *observer_ref)		// CONDITION
**	{
**		t_component *component;
**		t_mouse		*mouse;
**
**		component = (t_component*)observer_ref;
**		mouse = (t_mouse*)event->observable_ref;
**		if (is_vec2i_embedded(mouse->pos, component->curr.pos, component->curr.size)
**			return (TRUE);
**		return (FALSE);
**	}
**
**	t_result	component_set_hover_on(t_arg_list *args, t_event *event, void *observer_ref)	// ACTION
**	{
**		t_component *component;
**		
**		component = (t_component*)observer_ref;
**		component->curr.isHover = TRUE;
**		return (OK);
**	}
** 
** 	les states_observers check a chaque iteration tous les changements
** 
*/

typedef struct	s_event
{
	t_list_head			node;
	char				*name;
	void				*observable_ref;
	t_arg_list			args;
	t_arg_list			streams;
	t_result			(*destroy)(struct s_event*);
}				t_event;

typedef enum	e_observable_type
{
	OBSERVABLE_MOUSE,
	OBSERVABLE_KEYS,
	OBSERVABLE_INTERFACE,
	OBSERVABLE_COMPONENT,
	OBSERVABLE_LOGGER,
}				t_observable_type;

typedef struct	s_observable
{
	t_list_head			node;
	t_observable_type	type;
	void				*observable_ref;
	t_list_head 		*observables_ref;
	t_bool				subscribed;
	t_result			(*subscribe)(t_list_head*, t_list_head*);
	t_result			(*unsubscribe)(t_list_head*);
	t_list_head			queu;
}				t_observable;


typedef enum	e_mouse_button
{
	MOUSE_LEFT,
	MOUSE_RIGHT,
	MOUSE_WHEEL,
}				t_mouse_button;

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
}				t_mouse_state;

/*
** si pas d'event fourni par sdl 
** 		events.queu = empty  
** 		source.unsubscribe()
** les events sont inscrit a events.queu <=> ils sont fournis par la sdl
*/ 
typedef struct	s_mouse
{
	t_mouse_state	last;
	t_mouse_state	curr;
	t_event			mouse_up;
	t_event			mouse_down;
	t_event			mouse_wheel;
	t_event			mouse_motion;
	t_observable	events; 
}				t_mouse;

/*
** key state
** followed by component to up to date its own state
** plus besoin de stocker les hold key il suffit que l'observer check:
	for (down of keys.curr.down)
	{
		if (keys_list_contain(keys.curr.down, down) &&
			keys_list_contain(keys.last.down, down))
			trigger_action()
	}, key.curr)
*/
typedef struct	s_keys_state
{
	t_list_head		up;
	t_list_head		down;
}				t_keys_state;

/*
** si pas d'event fourni par sdl 
** 		events.queu = empty  
** 		source.unsubscribe()
** les events sont inscrit a events.queu <=> ils sont fournis par la sdl
*/ 
typedef struct	s_keys
{
	t_keys_state	last;
	t_keys_state	curr;
	t_event			key_up;
	t_event			key_down;
	t_observable	events; 
}				t_keys;

/* if event.stream has type == CUSTOM
** 		use stream name
**
**	exemple streamName = "game"
**	exemple streamName = "player"
**	exemple streamName = "destructibles"
*/
typedef enum	e_event_stream_type
{
	E_STREAM_COMPONENT_TREE,
	E_STREAM_INTERFACE,
	E_STREAM_MOUSE,
	E_STREAM_KEYS,
	E_STREAM_RADIO,
	E_STREAM_ERROR,
	E_STREAM_WARNINGS,
	E_STREAM_INFO,
	E_STREAM_DEBUG,
	E_STREAM_CUSTOM,
}				t_event_stream_type;

typedef struct	s_event_stream
{
	t_list_head			node;
	t_node				*tree; // le flux peux s'addresser autant a une liste qu'a un arbre
	t_event_stream_type	type;
	char				*name;
	t_list_head			observers;
}				t_event_stream;

/*
** lorsqu'une source creer possede un evenement dans sa liste
** elle s'inscrit a la liste des sources de l'event_interface
** l'interface parcours la liste des events des sources inscrites
** puis l'interface transmet chaque evenements au canaux correspondants 
*/

typedef struct	s_event_interface
{
	t_list_head sources;
	t_list_head streams;
}				t_event_interface;


/* 
**	t_bool	condition(t_arg_list args, t_event *event, void *observer_ref)
*/
typedef struct	s_condition
{
	t_list_head	node;
	t_bool		(*fn)();
	t_arg_list	args;
}				t_condition;

/* 
**	t_result	action(t_arg_list *args, t_event *event, void *observer_ref)
**
** l'event transmis n'est qu'un etat ou un flag(ENUM)
*/
typedef struct	s_event_observer
{
	t_list_head	node;
	t_result	(*fn)(t_arg_list *args, t_event *event, void *observer_ref);
	t_arg_list	args;
	t_list_head	conditions;
}				t_event_observer;

typedef struct	s_stream_observer
{
	t_list_head			node;
	t_event_stream 		*stream_ref;
	t_bool				subscribed;
	t_result			(*subscribe)(t_list_head*, t_list_head*);
	t_result			(*unsubscribe)(t_list_head*);
	void				*observer_ref;
	t_list_head			event_observers;
}				t_stream_observer;

/*
**	Component drag event
**	if (mouse.last.is_drag == false && mouse.curr.is_drag == true
**		&& component.is_hover == true)
**		component->is_drag = true;
*/

/*
** INTERNAL COMMUNICATION ?
*/
typedef struct	s_component_state
{
	// t_time		time;
	int			z_index;
	t_pos2i		pos;
	t_vec2i		size;
	t_bgra		bg_color;
	t_bgra		color;
	t_bool		is_layer_up_to_date;
	t_bool		is_visible;
	t_bool		is_hover;
	t_bool		is_focus;
	t_pos2i		mouse_offset;
	t_pos2i		drag_offset;
	t_bool		is_drag;
	char		*bg_image;
	char		*font_family;
	char		*text;
	t_list_head	filters;
}				t_component_state;

/*
** t_result	(*fn)(t_arg_list *args, t_component *self);
*/
typedef struct	s_cpt_state_observer
{
	t_list_head	node;
	t_result	(*fn)();
	t_arg_list	args;
}				t_cpt_state_observer;

typedef struct	s_component
{
	t_node				node;
	char				*id;
	t_arg_list			radio;
	TTF_Font			*font;
	SDL_Surface			*text_surface;
	t_layer				layer;
	t_component_state	last;
	t_component_state	curr;
	t_bool				up_to_date;
	t_list_head			state_observers;
	t_list_head			stream_observers;// follow event streams
	t_observable		events;
}				t_component;

typedef struct	s_scene
{
	t_list_head	node;
	char		*name;
	t_node		components_tree;
}				t_scene;


/*
** l'interface est abonnee a E_STREAM_MOUSE et diffuse les events (mouse) a chaque component par son
** stream_observer de type E_STREAM_COMPONENT_TREE
*/
typedef struct	s_interface
{
	t_list_head	scenes;
	t_scene		*curr;
	t_list_head	stream_observers;// follow event streams 
}				t_interface;

#endif