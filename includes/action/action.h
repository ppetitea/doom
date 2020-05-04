/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:24:08 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/03 15:08:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "containers/list.h"
# include "arg/arg.h"

typedef struct	s_action
{
	t_list_head	node;
	t_result	(*fn)();
	t_bool		active;
	t_arg		args;
}				t_action;

/*
** INIT ACTION
*/

t_result init_action(t_action *self);

t_action *init_new_action();

/*
** DEL ACTION
*/

t_result del_action(t_action *self);

/*
** SET ACTION
*/

t_result	set_action(t_action *action, t_result (*fn)(), t_argv argv,
	t_arg_type arg_type);

t_action	*set_new_action(t_result (*fn)(), t_argv argv,
	t_arg_type arg_type);

/*
** ADD ACTION
*/
t_action	*add_new_basic_action(t_list_head *list, t_result (*fn)());

t_action	*add_new_action(t_list_head *list, t_result (*fn)(), t_argv argv,
	t_arg_type arg_type);

t_result	action_add_arg(t_action *action, t_argv argv, t_arg_type arg_type);


t_argv	get_arg(t_arg *parent, int index);

void	trigger_actions(t_list_head *actions);

#endif