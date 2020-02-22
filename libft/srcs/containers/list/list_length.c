/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 08:40:00 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/29 03:16:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

size_t	list_lenght(t_list_head *head)
{
	t_list_head	*pos;
	size_t	len;

	len = 0;
	pos = head;
	while ((pos = pos->next) != head)
		len++;
	return (len);
}
