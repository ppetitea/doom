/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:17:46 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 12:50:19 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/canvas.h"
#include "utils/parser.h"
#include "utils/error.h"
#include <stdlib.h>

t_canvas	*init_new_canvas()
{
	t_canvas	*self;

	if (!(self = malloc(sizeof(t_canvas))))
		return (throw_null("init_new_canvas", "malloc failed"));
	init_list_head(&self->node);
	self->name = NULL;
	init_animation(&self->anim);
	return (self);
}
