/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:48:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 14:37:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "resources/game.h"

/*
** add_select_start_action_to_animation();
** add_select_stop_action_to_animation();
** add_hover_start_action_to_animation();
** add_hover_stop_action_to_animation();
** add_drag_start_action_to_animation();
** add_drag_stop_action_to_animation();
** add_draw_start_action_to_animation();
** add_draw_stop_action_to_animation();

** add_animation_action(animation, TRIGGER_TYPE, (*fn), t_list_head args);
*/
typedef struct		s_events
{
	t_mouse		mouse;
}					t_events;

void				handle_events(t_game *game);

#endif