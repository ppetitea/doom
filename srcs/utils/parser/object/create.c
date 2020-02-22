/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:33:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/24 00:50:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/parser.h"
#include "utils/error.h"
#include <stdlib.h>

t_dnon_object	*new_dnon_object()
{
	t_dnon_object	*ret;

	if (!(ret = (t_dnon_object*)malloc(sizeof(t_dnon_object))))
		return (throw_null("new_dnon_object", "malloc failed"));
	init_list_head(&ret->node);
	return (ret);
}

t_dnon_object	*create_dnon_object(char *key, t_dnon_value_type type)
{
	t_dnon_object	*ret;

	if (!(ret = new_dnon_object()))
		return (throw_null("create_dnon_object", "obj creation failed"));
	ret->key = key;
	ret->type = type;
	if (type == LIST)
	{
		if (!(ret->value = (t_list_head*)malloc(sizeof(t_list_head))))
			return (throw_null("create_dnon_object", "malloc failed")); 
		init_list_head((t_list_head*)ret->value);
	}
	return (ret);
}

t_dnon_object	*create_dnon_object_with_data(char *data)
{
	t_dnon_object	*object;

	if (data == NULL)
		return (throw_null("create_dnon_object_with_data", "data is null"));
	if ((object = new_dnon_object()) == NULL)
		return (throw_null("create_dnon_object_with_data", "obj creation failed"));
	if ((object->key = get_object_key(data)) == NULL)
		return (throw_null("create_dnon_object_with_data", "failed to find key"));
	if ((object->type = get_object_value_type(data)) == UNKNOW)
		return (throw_null("create_dnon_object_with_data", "failed to find type"));
	if (object->type == LIST)
	{
		if (!(object->value = (t_list_head*)malloc(sizeof(t_list_head))))
			return (throw_null("object_with_data", "malloc failed"));
		init_list_head((t_list_head*)object->value);
	}
	else
		object->value = get_object_value(data, object->type);
	return (object);
}