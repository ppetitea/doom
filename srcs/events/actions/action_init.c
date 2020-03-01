/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:21:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 12:09:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "events/action.h"
#include "utils/error.h"

t_action_node	*init_new_action()
{
	t_action_node	*self;

	if (!(self = malloc(sizeof(t_action_node))))
		return (throw_null("init_new_action", "malloc failed"));
	init_list_head(&self->node);
	self->fn = NULL;
	init_list_head(&self->args);
	return (self);
}