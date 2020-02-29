/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:17:46 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 12:20:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/button.h"
#include "utils/parser.h"
#include "utils/error.h"
#include <stdlib.h>

t_button	*init_new_button()
{
	t_button	*self;

	if (!(self = malloc(sizeof(t_button))))
		return (throw_null("init_new_button", "malloc failed"));
	init_list_head(&self->node);
	self->name = NULL;
	init_animation(&self->animation);
	return (self);
}
