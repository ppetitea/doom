/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:21:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 01:01:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "events/action.h"
#include "utils/error.h"

t_action_node	*add_new_basic_action(t_list_head *actions, t_result (*fn)())
{
	t_action_node	*action;

	if (!(action = init_new_action()))
		return (throw_null("add_new_basic_action", "init_new_action failed"));
	action->fn = fn;
	list_add_entry(&action->node, actions);
	return (action);
}

t_arg_node		*add_new_arg(t_list_head *args, t_arg arg)
{
	t_arg_node	*self;
	
	if (args == NULL)
		return (throw_null("add_new_arg", "NUL pointer provided"));
	if (!(self = malloc(sizeof(t_arg_node))))
		return (throw_null("add_new_arg", "malloc failed"));
	init_list_head(&self->node);
	self->arg = arg;
	list_add_entry(&self->node, args);
	return (self);
}

t_action_node	*add_new_action(t_list_head *actions, t_result (*fn)(),
					t_arg arg)
{
	t_action_node	*action;
	
	if (actions == NULL || fn == NULL)
		return (throw_null("add_new_action", "NULL pointer provided"));
	if (!(action = init_new_action()))
		return (throw_null("add_new_action", "init_new_action failed"));
	action->fn = fn;
	add_new_arg(&action->args, arg);
	list_add_entry(&action->node, actions);
	return (action);
}

t_result		add_action_arg(t_action_node *action, t_arg arg)
{
	if (action == NULL)
		return (throw_error("add_action_arg", "NULL pointer provided"));
	add_new_arg(&action->args, arg);
	return (OK);
}