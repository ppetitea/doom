/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_trigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:03:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 02:08:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/action.h"

t_arg	get_arg(t_list_head *args, int offset)
{
	return (((t_arg_node*)list_get(args, offset))->arg);
}

void	trigger_actions(t_list_head *actions)
{
	t_list_head		*pos;
	t_action_node	*action;
	t_list_head		*args;
	int				args_amount;

	pos = actions;
	while ((pos = pos->next) != actions)
	{
		action = (t_action_node*)pos;
		args = &action->args;
		args_amount = list_lenght(args);
		if (args_amount == 0)
			action->fn();
		else if (args_amount == 1)
			action->fn(get_arg(args, 1));
		else if (args_amount == 2)
			action->fn(get_arg(args, 1), get_arg(args, 2));
		else if (args_amount == 3)
			action->fn(list_get(args, 1), get_arg(args, 2), get_arg(args, 3));
		else if (args_amount == 4)
			action->fn(list_get(args, 1), get_arg(args, 2), get_arg(args, 3),
				get_arg(args, 4));
	}
}
