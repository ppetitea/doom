#ifndef EVENT_OBSERVABLE_H
# define EVENT_OBSERVABLE_H

# include "types.h"
# include "containers/list.h"

typedef enum	e_observable_type
{
	OBSERVABLE_MOUSE,
	OBSERVABLE_KEYS,
	OBSERVABLE_INTERFACE,
	OBSERVABLE_COMPONENT,
	OBSERVABLE_LOGGER,
	OBSERVABLE_NONE,
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
	t_result			(*destroy)(struct s_observable*);
}				t_observable;

t_result del_observable(t_observable *self);

t_result del_new_observable(t_observable *self);

t_result del_observable_list(t_list_head *list);

t_result init_observable(t_observable *self);

t_observable *init_new_observable();

t_result set_observable(t_observable *self, t_observable_type type,
	void *observable_ref);

t_observable *set_new_observable(t_observable_type type, void *observable_ref);

#endif