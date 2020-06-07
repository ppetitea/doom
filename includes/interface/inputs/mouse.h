#ifndef MOUSE_H
# define MOUSE_H

# include "maths/vec2f.h"
# include "interface/events/event.h"
# include "interface/events/observable.h"

typedef enum	e_mouse_button
{
	MOUSE_LEFT,
	MOUSE_RIGHT,
	MOUSE_WHEEL,
	MOUSE_NONE,
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
	t_result		(*destroy)(struct s_mouse*);
}				t_mouse;

t_result init_mouse_state(t_mouse_state *self)
{
	self->x = 0;
	self->y = 0;
	self->wheel = 0.0f;
	self->velocity = ft_vec2f(0, 0);
	self->is_press = FALSE;
	self->is_move = FALSE;
	self->is_clic = FALSE;
	self->is_drag = FALSE;
	self->button = MOUSE_NONE;
	return (OK);
};

t_result del_mouse(t_mouse *self);

t_result del_new_mouse(t_mouse *self);

t_result init_mouse(t_mouse *self);

t_mouse *init_new_mouse();

t_result set_mouse_pos(t_mouse *self, int x, int y);

#endif