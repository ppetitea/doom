/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/03 13:46:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/parser.h"
#include "utils/error.h"

int		get_int_value_by_key(t_dnon_object *tree, char *key, int by_default)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree == NULL || key == NULL)
	{
		// throw_warning("get_float_value", "NULL pointer provided");
		return (by_default);
	}
	if (tree->type != LIST)
		return (by_default);
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == NUMBER)
			return ((int)(*(float*)child->value));
	}
	return (by_default);
}

t_result	set_int_value_by_key(t_dnon_object *obj, char *key, int set)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (obj == NULL || key == NULL)
		return (throw_error("set_int_value_by_key", "NULL pointer"));
	if (obj->type != LIST)
		return (throw_error("set_int_value_by_key", "obj isn't LIST"));
	pos = (t_list_head*)obj->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)obj->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == NUMBER)
		{
			(*(float*)child->value) = (float)set;
				return (OK);
		}
	}
	return (OK);
}