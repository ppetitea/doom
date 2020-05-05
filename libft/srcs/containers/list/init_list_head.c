/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:39:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/29 00:30:21 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"
#include <stdlib.h>

t_result	init_list_head(t_list_head *list)
{
	if (!list)
		return (ERROR);
	list->next = list;
	list->prev = list;
	return (OK);
}

t_list_head	*init_new_list_head()
{
	t_list_head *list;

	if (!(list = malloc(sizeof(t_list_head))))
		return (NULL);
	init_list_head(list);
	return (list);
}
