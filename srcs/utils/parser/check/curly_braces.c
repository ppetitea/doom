/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly_braces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:57:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/21 02:17:25 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "utils/error.h"
#include "utils/parser.h"
t_result	check_curly_braces(char *data)
{
	size_t	i;
	ssize_t	deep;

	deep = 0;
	i = 0;
	while (data[i] && deep >= 0)
	{
		if (data[i] == '{')
		{
			if (!check_open_curly_brace_left_side(data, i) ||
					!check_open_curly_brace_right_side(data, i))
				return (throw_error("check_curly_braces", "around open curly braces"));
			deep++;
		}
		if (data[i] == '}')
		{
			if (!check_close_curly_brace_left_side(data, i) ||
					!check_close_curly_brace_right_side(data, i))
				return (throw_error("check_curly_braces", "around close curly braces"));
			deep--;
		}
		i++;
	}
	return (deep != 0 ? ERROR : OK);
}