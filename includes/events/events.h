/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:48:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 14:22:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "resources/game.h"

typedef struct		s_events
{
	t_mouse		mouse;
}					t_events;

void				handle_events(t_game *game);

#endif