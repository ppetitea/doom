#ifndef COMPONENT_H
# define COMPONENT_H

# include "interface/layer.h"
# include "image/image.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"
# include "colors/color.h"
# include "SDL_ttf.h"
# include "SDL_surface.h"
# include "arg/arg.h"
# include "interface/events/observable.h"

/*
**	Comment faire des animations dans le temps ?
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
	t_result	(*destroy)(struct s_component_state*);
}				t_component_state;

t_result del_component_state(t_component_state *self);

t_result del_new_component_state(t_component_state *self);

t_result init_component_state(t_component_state *self);

t_component_state *init_new_component_state();

/*
** t_result	(*fn)(t_arg_list *args, t_component *self);
*/
typedef struct	s_component_observer
{
	t_list_head	node;
	t_result	(*fn)(t_arg_list *args, t_component *self);
	t_list_head	args;
	t_result	(*destroy)(struct s_component_observer*);
}				t_component_observer;

t_result del_component_observer(t_component_observer *self);

t_result del_new_component_observer(t_component_observer *self);

t_result del_component_observer_list(t_list_head *list);

t_result init_component_observer(t_component_observer *self);

t_component_observer *init_new_component_observer();

typedef struct	s_component
{
	t_node				node;
	char				*id;
	t_list_head			radio;
	TTF_Font			*font;
	SDL_Surface			*text_surface;
	t_layer				layer;
	t_component_state	last;
	t_component_state	curr;
	t_bool				up_to_date;
	t_list_head			state_observers;
	t_list_head			stream_observers;// follow event streams
	t_list_head			e_propagation_handlers;
	t_observable		events;
	t_result			(*destroy)(struct s_component*);
}				t_component;

t_result component_foreach_prev(t_component *self,
	t_result (*fn)(t_component *));

t_result destroy_component(t_component *self);

t_result del_component(t_component *self);

t_result del_new_component(t_component *self);

t_result init_component(t_component *self);

t_component *init_new_component();

#endif