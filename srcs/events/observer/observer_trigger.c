/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_trigger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:55:11 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 14:49:39 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "events/action.h"

static t_bool	is_mouse_mouse_obs_with_box(t_box *box, t_mouse mouse)
{
	t_vec2i	start;
	t_vec2i	end;

	start = box->offset;
	end.x = box->offset.x + box->size.x;
	end.y = box->offset.y + box->size.y;
	if (start.x <= mouse.pos.x && mouse.pos.x < end.x &&
		start.y <= mouse.pos.y && mouse.pos.y < end.y)
		return (TRUE);
	return (FALSE);
}

t_bool	trigger_mouse_observers(t_list_head *observers)
{
	t_mouse_observer	*observer;
	t_list_head			*pos;
	t_list_head			*next;

	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_mouse_observer*)pos;
		trigger_actions(&observer->actions);
	}
	return (FALSE);
}

t_bool	trigger_mouse_mouse_obs_on(t_list_head *observers, t_mouse mouse)
{
	t_mouse_observer	*observer;
	t_list_head			*pos;
	t_list_head			*next;

	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_mouse_observer*)pos;
		if (is_mouse_mouse_obs_with_box(observer->render_box, mouse))
		{
			trigger_actions(&observer->actions);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	trigger_mouse_mouse_obs_off(t_list_head *observers, t_mouse mouse)
{
	t_mouse_observer	*observer;
	t_list_head			*pos;
	t_list_head			*next;

	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		observer = (t_mouse_observer*)pos;
		if (!is_mouse_mouse_obs_with_box(observer->render_box, mouse))
		{
			trigger_actions(&observer->actions);
			return (TRUE);
		}
	}
	return (FALSE);
}

