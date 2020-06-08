#ifndef EVENT_STREAM_H
# define EVENT_STREAM_H

# include "containers/list.h"

/* if event.stream has type == CUSTOM
** 		use stream name
**
**	exemple streamName = "game"
**	exemple streamName = "player"
**	exemple streamName = "destructibles"
*/
// typedef enum	e_event_stream_type
// {
// 	E_STREAM_INTERFACE,
// 	E_STREAM_TIME,
// 	E_STREAM_MOUSE,
// 	E_STREAM_KEYS,
// 	E_STREAM_RADIO,
// 	// E_STREAM_ERROR,
// 	// E_STREAM_WARNINGS,
// 	// E_STREAM_INFO,
// 	// E_STREAM_DEBUG,
// 	E_STREAM_CUSTOM,
// }				t_event_stream_type;

/*
** Modifier t_result			(*unsubscribe)(t_list_head*);
** Par t_result					(*unsubscribe)(struct s_stream_observer*);
**	Pour pouvoir set suscribed a false en plus de supprimer le noeud
*/

typedef struct	s_stream_observer
{
	t_list_head			node;
	t_event_stream 		*stream_ref;
	t_bool				subscribed;
	t_result			(*subscribe)(t_list_head*, t_list_head*);
	t_result			(*unsubscribe)(t_list_head*);
	void				*observer_ref;
	t_list_head			event_handlers;
	t_result			(*destroy)(struct s_stream_observer*);
}				t_stream_observer;

t_result del_stream_observer(t_stream_observer *self);

t_result del_new_stream_observer(t_stream_observer *self);

t_result del_stream_observer_list(t_list_head *list);

t_result init_stream_observer(t_stream_observer *self);

t_stream_observer *init_new_stream_observer();


// stream.name: "interface" || "mouse" || "keys" || "time" || "radio"

typedef struct	s_event_stream
{
	t_list_head			node;
	char				*name;
	t_list_head			observers;
	t_result			(*destroy)(struct s_event_stream*);
}				t_event_stream;

t_result del_event_stream(t_event_stream *self);

t_result del_new_event_stream(t_event_stream *self);

t_result del_event_stream_list(t_list_head *list);

t_result init_event_stream(t_event_stream *self);

t_event_stream *init_new_event_stream();

#endif