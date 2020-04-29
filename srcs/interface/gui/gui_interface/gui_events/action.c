/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:23:38 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/30 00:53:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg/arg.h"
#include "action/action.h"
#include "log/log.h"
#include <stdlib.h>

/*
** INIT ACTION
*/

t_result init_action(t_action *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->fn = NULL;
	self->active = TRUE;
	if (!init_arg(&self->args))
		return (console(FATAL, __func__, __LINE__, "init_arg fail").err);
	self->args.type = ARG_LIST;
	return (OK);
};

t_action *init_new_action()
{
	t_action *self;

	if (!(self = malloc(sizeof(t_action))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_action(self);
	return (self);
}

/*
** DEL ACTION
*/

t_result del_action(t_action *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	args_childs_del(&self->args);
	list_del_entry(&self->node);
	free(self);
	return (OK);
}

/*
** SET ACTION
*/

t_result	set_action(t_action *action, t_result (*fn)(), t_argv argv,
	t_arg_type arg_type)
{
	t_arg	*child;

	if (action == NULL || fn == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	action->fn = fn;
	if (!(child = set_new_arg(arg_type, argv)))
		return (console(FATAL, __func__, __LINE__, "new_arg fail").err);
	node_add_child(&action->args.node, &child->node);
	return (OK);
}

t_action	*set_new_action(t_result (*fn)(), t_argv argv, t_arg_type arg_type)
{
	t_action	*action;

	if (fn == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").null);
	if (!(action = init_new_action()))
		return (console(FATAL, __func__, __LINE__, "new_action fail").null);
	if (!set_action(action, fn, argv, arg_type) && del_action(action))
		return (console(FATAL, __func__, __LINE__, "set_action fail").null);
	return (action);
}

/*
** ADD ACTION
*/

t_action	*add_new_action(t_list_head *list, t_result (*fn)(), t_argv argv,
	t_arg_type arg_type)
{
	t_action	*action;

	if (!(action = set_new_action(fn, argv, arg_type)))
		return (console(FATAL, __func__, __LINE__, "new_action fail").null);
	list_add_entry(&action->node, list);
	return (action);
}

t_result	action_add_arg(t_action *action, t_argv argv, t_arg_type arg_type)
{
	t_arg	*child;

	if (action == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (!(child = set_new_arg(arg_type, argv)))
		return (console(FATAL, __func__, __LINE__, "new_arg fail").err);
	node_add_child(&action->args.node, &child->node);	
	return (OK);
}

/*
** TRIGGER ACTION
*/

t_argv	get_arg(t_arg *parent, int index)
{
	t_arg	*arg;

	if (!(arg = (t_arg*)node_get_child(&parent->node, index)))
		return ((t_argv)NULL);
	return (arg->value);
}

void	trigger_actions(t_list_head *actions)
{
	t_list_head	*curr;
	t_action	*action;
	t_arg		*args;
	int			args_amount;

	curr = actions;
	while ((curr = curr->next) != actions)
	{
		action = (t_action*)curr;
		args = &action->args;
		args_amount = node_childs_amount(&args->node);
		if (args_amount == 0)
			action->fn();
		else if (args_amount == 1)
			action->fn(get_arg(args, 0));
		else if (args_amount == 2)
			action->fn(get_arg(args, 0), get_arg(args, 1));
		else if (args_amount == 3)
			action->fn(get_arg(args, 0), get_arg(args, 1), get_arg(args, 2));
		else if (args_amount == 4)
			action->fn(get_arg(args, 0), get_arg(args, 1), get_arg(args, 2),
				get_arg(args, 3));
	}
}