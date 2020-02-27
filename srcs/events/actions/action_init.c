/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:21:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 19:24:29 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/action.h"
#include "utils/error.h"

t_action_node *init_new_action()
{
	t_action_node	*self;

	if (!(self = malloc(sizeof(t_action_node))))
		return (throw_error("init_new_action", "malloc failed"));
	init_list_head(&self->node);
	
	return (self);
}