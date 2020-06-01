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
// 	E_STREAM_MOUSE,
// 	E_STREAM_KEYS,
// 	E_STREAM_RADIO,
// 	// E_STREAM_ERROR,
// 	// E_STREAM_WARNINGS,
// 	// E_STREAM_INFO,
// 	// E_STREAM_DEBUG,
// 	E_STREAM_CUSTOM,
// }				t_event_stream_type;

typedef struct	s_event_stream
{
	t_list_head			node;
	char				*name;
	t_list_head			observers;
}				t_event_stream;

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

#endif