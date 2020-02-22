/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_with_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:02:10 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 05:28:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/parser.h"
#include "utils/error.h"
#include "libft.h"

t_result	init_usize_with_obj(t_usize *self, t_dnon_object *size_obj)
{
	if (self == NULL)
		return (throw_error("init_usize_with_obj", "NULL pointer provided"));
	self->x = (size_t)get_int_value_by_key(size_obj, "x", 1);
	self->y = (size_t)get_int_value_by_key(size_obj, "y", 1);
	if (self->x == 0)
		self->x = 1;
	if (self->y == 0)
		self->y = 1;
	// if (size_obj == NULL)
	// 	return (throw_warning_ok("init_usize_with_obj", "no size", 4));
	return (OK);
}

t_result	init_vec2i_with_obj(t_vec2i *self, t_dnon_object *vec2i_obj)
{
	if (self == NULL)
		return (throw_error("init_vec2i_with_obj", "NULL pointer provided"));
	self->x = get_int_value_by_key(vec2i_obj, "x", 0);
	self->y = get_int_value_by_key(vec2i_obj, "y", 0);
	// if (vec2i_obj == NULL)
		// return (throw_warning_ok("init_vec2i_with_obj", "no size", 4));
	return (OK);
}

t_result	init_vec2f_with_obj(t_vec2f *self, t_dnon_object *vec2f_obj)
{
	if (self == NULL)
		return (throw_error("init_vec2f_with_obj", "NULL pointer provided"));
	self->x = get_float_value_by_key(vec2f_obj, "x", 1.0f);
	self->y = get_float_value_by_key(vec2f_obj, "y", 1.0f);
	// if (vec2f_obj == NULL)
	// 	return (throw_warning_ok("init_vec2f_with_obj", "no size", 4));
	return (OK);
}
