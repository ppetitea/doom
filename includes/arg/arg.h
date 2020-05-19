/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:07:29 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/19 22:40:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# include "log/log.h"
# include "data/data.h"
# include "containers/node.h"
# include "containers/list.h"

typedef	union	u_argv
{
	int			i;
	float		f;
	char		c;
	char		*s;
	char		*p;
	void		*ref;
	t_node		*list;
}				t_argv;

typedef enum	e_arg_type
{
	ARG_INT,
	ARG_FLOAT,
	ARG_CHAR,
	ARG_STRING,
	ARG_POINTER,
	ARG_REF,
	ARG_LIST,
}				t_arg_type;

/*
** arguments list without deep nodes
*/
typedef struct	s_arg_list
{
	t_list_head	node;
	t_arg_type	type;
	t_argv		value;
}				t_arg_list;

t_bool		is_arg_list_type_valid(t_arg_type type);

t_bool		is_arg_match(t_arg_list *node, t_arg_type type, t_argv value);

t_result	init_arg_list(t_arg_list *self);

t_arg_list	*init_new_arg_list();

t_result	del_arg_list(t_arg_list *self);

t_result	del_new_arg_list(t_arg_list *self);

t_result	set_arg_list(t_arg_list *self, t_arg_type type, t_argv value);

t_arg_list	*set_new_arg_list(t_arg_type type, t_argv value);

t_arg_list	*list_add_new_arg_list(t_list_head *list, t_arg_type type,
	t_argv value);

t_arg_list	*arg_list_find(t_list_head *list, t_arg_type type, t_argv value);

/*
** arguments list with deep nodes
*/
typedef struct	s_arg
{
	t_node		node;
	t_arg_type	type;
	t_argv		value;
}				t_arg;


t_result	arg_foreach_prev(t_arg *self, t_result (*fn)(t_arg*));

t_result	arg_foreach_next(t_arg *self, t_result (*fn)(t_arg*));

/*
** PRINT ARG
*/

t_result	print_arg(t_arg *self);

t_result	print_args(t_arg *self);

/*
** INIT ARG
*/
t_result	init_arg(t_arg *self);

t_arg		*init_new_arg();

/*
** DELETE ARG
*/

t_result	arg_del(t_arg *self);

t_result	del_new_arg(t_arg *self);

t_result	args_childs_del(t_arg *self);

t_result	args_del(t_arg *self);

t_res		args_del_and_quit(t_arg *self);

/*
** ARG SETUP
*/

t_result set_arg(t_arg *self, t_arg_type type, t_argv val);

t_arg	*set_new_arg(t_arg_type type, t_argv val);

t_arg	*data_to_arg(t_data *data);

t_arg	*data_list_to_arg_list(t_data *parent);

#endif