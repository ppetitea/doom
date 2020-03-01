/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:39:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 02:13:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "containers/list.h"
# include "utils/parser.h"

// typedef enum	e_arg_type
// {
// 	TYPE_INT,
// 	TYPE_FLOAT,
// 	TYPE_CHAR,
// 	TYPE_POINTER,
// }				t_arg_type;

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
}				t_arg_node;
t_result		init_new_arg(t_arg arg);

typedef struct	s_action_node
{
	t_list_head		node;
	t_result		(*fn)();
	t_list_head		args;
}				t_action_node;
t_action_node	*init_new_action();

/*
**	add
*/
t_action_node	*add_new_basic_action(t_list_head*, t_result (*fn)());
t_action_node	*add_new_action(t_list_head*, t_result (*fn)(), t_arg arg);
t_arg_node		*add_new_arg(t_list_head *args, t_arg arg);
t_result		add_action_arg(t_action_node *action, t_arg arg);

/*
** trigger
*/
void			trigger_actions(t_list_head *actions);

#endif