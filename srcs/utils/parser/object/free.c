/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:33:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 16:15:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/parser.h"
#include <stdlib.h>

static void		free_object_recursively(t_obj *obj)
{
	if (obj->key != NULL)
		free(obj->key);
	if (obj->type != LIST && obj->value != NULL)
		free(obj->value);
	else
	{
		list_foreach((t_list_head*)obj->value, 0, free_object);
		free(obj->value);
	}
}

t_iterator_callback		free_object(t_obj *obj)
{
	free_object_recursively(obj);
	free(obj);
	return (CONTINUE);
}