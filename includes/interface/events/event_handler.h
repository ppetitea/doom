#ifndef EVENT_HANDLER_H
# define EVENT_HANDLER_H

#include "interface/events/event.h"
/* 
**	t_bool	condition(t_arg_list args, t_event *event, void *observer_ref)
*/
typedef struct	s_condition
{
	t_list_head	node;
	t_bool		(*fn)();
	t_list_head	args;
	t_result	(*destroy)(struct s_condition*);
}				t_condition;

/* 
**	t_result	action(t_arg_list *args, t_event *event, void *observer_ref)
**
** l'event transmis n'est qu'un etat ou un flag(ENUM)
*/
typedef struct	s_event_handler
{
	t_list_head	node;
	t_result	(*fn)(t_list_head *args, t_event *event, void *observer_ref);
	t_list_head	args;
	t_list_head	conditions;
	t_result	(*destroy)(struct s_event_handler*);
}				t_event_handler;

#endif