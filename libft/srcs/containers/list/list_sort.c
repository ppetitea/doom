/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 20:54:46 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/22 20:55:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

void	bubble_sort_linked_list(t_list_head *list,
			t_bool(*rule)(t_list_head*, t_list_head*))
{
	t_list_head	*pos;
	t_list_head	*next;
	size_t	len;
	size_t	i;

	len = list_lenght(list);
	i = 0;
	while (i < len)
	{
		pos = list;
		next = pos->next;
		while ((pos = next)->next != list)
		{
			next = next->next;
			if (rule(pos, next))
			{
				list_del_entry(pos);
				list_add(pos, next, next->next);
				next = pos;
			}
		}
		i++;
	}
}