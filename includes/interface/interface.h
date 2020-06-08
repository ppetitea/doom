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

t_result del_scene(t_scene *self);

t_result del_new_scene(t_scene *self);

t_result del_scene_list(t_list_head *list);

t_result init_scene(t_scene *self);

t_scene *init_new_scene();

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

t_result del_interface(t_interface *self);

t_result del_new_interface(t_interface *self);

t_result init_interface(t_interface *self);

t_interface *init_new_interface();

/*
** Getters
*/

t_interface *static_interface(t_interface *init);

t_interface *get_interface();

t_keys *get_keys();

t_mouse *get_mouse();

t_scene *get_current_scene();

#endif