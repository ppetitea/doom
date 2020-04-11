/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:39:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/11 16:14:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

t_result	init_list_head(t_list_head *list)
{
	if (!list)
		return (ERR);
	list->next = list;
	list->prev = list;
	return (OK);
}
