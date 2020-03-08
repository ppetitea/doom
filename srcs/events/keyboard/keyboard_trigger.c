/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_trigger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:55:11 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 19:29:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/keyboard.h"
#include "events/action.h"

t_bool	trigger_keyboard_observers(t_list_head *observers)
{
	t_keyboard_observer	*observer;
	t_list_head			*pos;
	t_list_head			*next;
	t_bool				ret;

	ret = FALSE;
	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_keyboard_observer*)pos;
		trigger_actions(&observer->actions);
		ret = TRUE;
	}
	return (ret);
}

t_bool	trigger_keyboard_observers_on(t_list_head *observers,
			t_keyboard keyboard)
{
	t_keyboard_observer	*observer;
	t_list_head			*pos;
	t_list_head			*next;
	t_bool				ret;

	ret = FALSE;
	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_keyboard_observer*)pos;
		if (observer->key == keyboard.key)
		{
			trigger_actions(&observer->actions);
			ret = TRUE;
		}
	}
	return (ret);
}
