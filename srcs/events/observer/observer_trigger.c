/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_trigger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:55:11 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:59:06 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "events/action.h"

t_bool	trigger_observers(t_list_head *observers)
{
	t_observer	*observer;
	t_list_head	*pos;
	t_list_head	*next;
	t_bool		ret;

	ret = FALSE;
	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_observer*)pos;
		trigger_actions(&observer->actions);
		ret = TRUE;
	}
	return (ret);
}

t_bool	trigger_time_observers(t_list_head *observers, double time)
{
	t_time_observer	*observer;
	t_list_head	*pos;
	t_list_head	*next;
	t_bool		ret;

	ret = FALSE;
	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_time_observer*)pos;
		if (observer->seconds < time)
			trigger_actions(&observer->actions);
		ret = TRUE;
	}
	return (ret);
}
