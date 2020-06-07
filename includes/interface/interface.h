#ifndef INTERFACE_H
# define INTERFACE_H

# include "interface/component.h"
# include "interface/inputs/mouse.h"
# include "interface/inputs/keyboard.h"

typedef struct	s_scene
{
	t_list_head	node;
	t_component	tree;
	t_result	(*destroy)(struct s_scene*);
}				t_scene;

/*
** l'interface est abonnee a E_STREAM_MOUSE et diffuse les events (mouse)
** a la current scene qui les diffuses a tous les components 
** les events qui se propagent dans l'arbre sont gere par component.event_propagation_handlers
*/
typedef struct	s_interface
{
	t_list_head		scenes;
	t_scene			*curr;
	t_mouse			mouse;
	t_keys			keys;
	// t_time		time;
	t_observable	events;
	t_list_head		observables;
	t_list_head		streams;
	t_list_head		stream_observers;
	t_result	(*destroy)(struct s_interface*);
}				t_interface;

#endif