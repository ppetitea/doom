/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_overwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:25:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 19:13:28 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/button.h"
#include "utils/parser.h"
#include "utils/error.h"

t_button	*overwrite_button(t_button *self, t_obj *button_obj,
				t_mouse_observable *mouse)
{
	t_button	*self;

	if (self == NULL || button_obj == NULL)
		return (throw_null("overwrite_button", "NULL pointer provided"));
	if (!overwrite_animation(&self->animation,
		get_child_list(button_obj, "animation"), mouse))
		return (throw_null("overwrite_button", "Fail to overwrite_animation"));
	return (self);
}
