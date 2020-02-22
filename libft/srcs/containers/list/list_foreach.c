/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:47:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/17 13:06:03 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

t_bool	list_foreach(t_list_head *list, size_t offset, t_iterator_callback (*fn)())
{
	t_list_head	*pos;
	t_list_head	*next;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		if (fn((void*)((t_u8*)pos - offset)) == STOP_ITERATION)
			return (TRUE);
	}
	return (FALSE);
}
