/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:05:19 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 02:07:59 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"
#include "maths/maths.h"

t_list_head		*list_get(t_list_head *list, int offset)
{
	t_list_head	*pos;
	int	sign;
	int	i;

	sign = (offset >= 0) ? 1 : -1;
	pos = list;
	i = 0;
	while (ft_abs(i) < ft_abs(offset) && (pos = pos->next) != list)
		i += sign;
	if (i == 0 || pos == list)
		return (NULL);
	return (pos);
}
