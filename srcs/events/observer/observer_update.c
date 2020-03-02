/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_observers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:56:13 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 14:22:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/observer.h"
#include "utils/error.h"

t_result	update_mouse_observers_lists(t_mouse_observers *mouse_obs,
				t_mouse_followers *followers)
{
	if (mouse_obs == NULL || followers == NULL)
		return (throw_error("add_mouse_observers_lists", "NULL pointer"));
	mouse_obs->hover_start.list = &followers->hover_start;
	mouse_obs->hover_end.list = &followers->hover_end;
	mouse_obs->right_up.list = &followers->right_up;
	mouse_obs->right_down.list = &followers->right_down;
	mouse_obs->left_up.list = &followers->left_up;
	mouse_obs->left_down.list = &followers->left_down;
	mouse_obs->drag.list = &followers->drag;
	mouse_obs->drop.list = &followers->drop;
	mouse_obs->motion.list = &followers->motion;
	mouse_obs->wheel_normal.list = &followers->wheel_normal;
	mouse_obs->wheel_flip.list = &followers->wheel_flip;
	return (OK);
}
