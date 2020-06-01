/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:04:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/01 11:44:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_EVENT_H
# define GUI_EVENT_H

# include "containers/list.h"
# include "arg/arg.h"

typedef struct	s_event
{
	t_list_head			node;
	char				*name;
	void				*observable_ref;
	t_arg_list			args;
	t_arg_list			streams;
	t_result			(*destroy)(struct s_event*);
}				t_event;

t_result del_event(t_event *self);

t_result del_new_event(t_event *self);

t_result del_event_list(t_list_head *list);

t_result init_event(t_event *self);

t_event *init_new_event();

t_result	add_event_arg(t_event *event, t_arg_type type, t_argv value);

t_result	add_event_stream(t_event *event, char *stream);

t_result	add_event_stream2(t_event *event, char *stream1, char *stream2);

t_result	add_event_stream3(t_event *event, char *stream1, char *stream2,
	char *stream3);

t_result set_event(t_event *self, char *name, void *observable_ref,
	char *stream);

t_event *set_new_event(char *name, void *observable_ref, char *stream);

#endif