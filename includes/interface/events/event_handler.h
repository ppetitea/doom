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

t_result del_condition(t_condition *self);

t_result del_new_condition(t_condition *self);

t_result del_condition_list(t_list_head *list);

t_result init_condition(t_condition *self);

t_condition *init_new_condition();

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

t_result del_event_handler(t_event_handler *self);

t_result del_new_event_handler(t_event_handler *self);

t_result del_event_handler_list(t_list_head *list);

t_result init_event_handler(t_event_handler *self);

t_event_handler *init_new_event_handler();

#endif