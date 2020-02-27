/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:33:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 16:15:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/parser.h"
#include "utils/error.h"
#include <stdlib.h>

t_obj	*new_obj()
{
	t_obj	*ret;

	if (!(ret = (t_obj*)malloc(sizeof(t_obj))))
		return (throw_null("new_obj", "malloc failed"));
	init_list_head(&ret->node);
	return (ret);
}

t_obj	*create_obj(char *key, t_dnon_value_type type)
{
	t_obj	*ret;

	if (!(ret = new_obj()))
		return (throw_null("create_obj", "obj creation failed"));
	ret->key = key;
	ret->type = type;
	if (type == LIST)
	{
		if (!(ret->value = (t_list_head*)malloc(sizeof(t_list_head))))
			return (throw_null("create_obj", "malloc failed")); 
		init_list_head((t_list_head*)ret->value);
	}
	return (ret);
}

t_obj	*create_obj_with_data(char *data)
{
	t_obj	*object;

	if (data == NULL)
		return (throw_null("create_obj_with_data", "data is null"));
	if ((object = new_obj()) == NULL)
		return (throw_null("create_obj_with_data", "obj creation failed"));
	if ((object->key = get_object_key(data)) == NULL)
		return (throw_null("create_obj_with_data", "failed to find key"));
	if ((object->type = get_object_value_type(data)) == UNKNOW)
		return (throw_null("create_obj_with_data", "failed to find type"));
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