/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 00:40:03 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 01:30:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "utils/parser.h"
int		get_object_value_type(char *data)
{
	size_t	i;

	i = 0;
	while (data[i] && data[i] != ':')
		i++;
	i++;
	if (data[i] == '"')
		return (STRING);
	else if (data[i] && (ft_isdigit(data[i]) || ( data[i] == '-' && ft_isdigit(data[i + 1]))))
		return (NUMBER);
	else if (data[i] == '{')
		return (LIST);
	else
		return (UNKNOW);
}

