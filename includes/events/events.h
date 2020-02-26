/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:48:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/26 14:49:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "resources/game.h"

typedef struct		s_mouse
{
	t_pos2i				pos;
	t_bool				down;
	t_bool				drag;
	t_mouse_followers	followers;
}					t_mouse;

typedef struct		s_events
{
	t_mouse		mouse;
}					t_events;

void				handle_events(t_game *game);

#endif