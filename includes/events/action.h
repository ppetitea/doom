/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:39:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 00:26:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "containers/list.h"
# include "utils/parser.h"

typedef enum	e_arg_type
{
	TYPE_NONE,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_CHAR,
	TYPE_POINTER,
}				t_arg_type;

typedef	union	u_arg
{
	int		integer;
	float	floating;
	char	character;
	void	*pointer;
}				t_arg;

typedef struct	s_arg_node
{
	t_list_head		node;
	t_arg			arg;
	t_arg_type		arg_type;
}				t_arg_node;
t_result		init_new_arg(t_arg arg, t_arg_type type);

typedef struct	s_action_node
{
	t_list_head		node;
	t_result		(*action)();
	t_list_head		args;
}				t_action_node;
t_result		init_new_action();

/*
INIT:
	if (!(action = init_new_action()))
		return (error);
	list_add_entry(&action->node, action_list);


USAGE:
	Sans arguments:
		add_new_action(action_list, (*fn));
	
	Avec 1 seul argument:
		add_new_action_with_arg(action_list, (*fn), arg, ARG_TYPE);

	Plus d'un argument
		if (!(action = add_new_action_with_arg(action_list, (*fn), arg, ARG_TYPE)))
			return (error);
		add_action_arg(action, arg, TYPE);
		add_action_arg(action, arg, TYPE);
		add_action_arg(action, arg, TYPE);
*/

#endif