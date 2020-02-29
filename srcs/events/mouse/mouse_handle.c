/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:42:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 17:43:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"
#include "events/mouse.h"
#include "resources/game.h"
#include "utils/error.h"

#include <stdio.h>

void	handle_mouse_motion(t_game *game, SDL_MouseMotionEvent event)
{
	if (game == NULL)
		return (throw_void("handle_mouse_motion", "NULL pointer provided"));
	// game->events.mouse.pos = ft_vec2i(event.x, event.y);
	// if (game->events.mouse.down == TRUE &&
	// 	game->events.mouse.drag == FALSE)
	// {
	// 	game->events.mouse.drag = TRUE;
	// 	trigger_entities_by_drag(game);
	// }
	// else
	// 	trigger_entities_by_hover(game);
	(void)event;
	(void)game;
}

#include "events/action.h"
#include "maths/maths.h"

t_list_head *list_get(t_list_head *list, int offset)
{
	t_list_head	*pos;
	int	sign;
	int	i;

	sign = (offset >= 0) ? 1 : -1;
	pos = list;
	i = 0;
	while (ft_abs(i) < ft_abs(offset) && (pos = pos->next) != list)
		i += sign;
	if (i == 0 || pos == list)
		return (NULL);
	return (pos);
}

t_arg	*get_arg(t_list_head *args, int offset)
{
	return ((t_arg*)list_get(args, offset));
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
			action->fn(get_arg(args, 1)->integer);
		else if (args_amount == 2)
			action->fn(*list_get(args, 1), *list_get(args, 2));
		else if (args_amount == 3)
			action->fn(list_get(args, 1), *list_get(args, 2),
				*list_get(args, 3));
		else if (args_amount == 4)
			action->fn(list_get(args, 1), *list_get(args, 2),
				*list_get(args, 3), *list_get(args, 4));
		else
			printf("wrong args amount %d\n", args_amount);
	}
}

void	update_mouse_select_observers(t_list_head *observers)
{
	t_list_head			*pos;
	t_mouse_observer	*observer;
	
	pos = observers;
	while ((pos = pos->next) != observers)
	{
		observer = (t_mouse_observer*)pos;
		trigger_actions(&observer->start_actions);		
	}
}

void	handle_mouse_down(t_mouse_observable *mouse, SDL_MouseButtonEvent event)
{
	mouse->state.down = TRUE;
	mouse->state.pos = ft_vec2i(event.x, event.y);
	if (mouse->state.mode == POINTER_SELECT)
	{
		if (!mouse->state.drag)
			update_mouse_select_observers(&mouse->followers.select);
	}
	(void)event;
	(void)mouse;
}

void	handle_mouse_up(t_game *game, SDL_MouseButtonEvent event)
{
	// game->events.mouse.pos = ft_vec2i(event.x, event.y);
	// if (game->events.mouse.drag)
	// 	trigger_entities_by_drop(game);
	// game->events.mouse.down = FALSE;
	// game->events.mouse.drag = FALSE;
	(void)event;
	(void)game;
}