/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 22:20:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/10 23:59:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_parser.h"
#include "log.h"
#include "ft/str.h"

t_result	clean_data(char *data)
{
	int		curr;
	t_bool	in_string;
	t_bool	in_space;

	if (data == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer").err);
	curr = 0;
	in_string = FALSE;
	while (data && data[curr])
	{
		in_string = (data[curr] == '"') ? !in_string : in_string;
		in_space = (!in_string && ft_isspace(data[curr])) ? TRUE : FALSE;			
		if (in_space)
			ft_strcpy(&data[curr], &data[curr + 1]);
		else
			curr++;
	}
	return (OK);
}

t_token		*tokenize(char *data, t_node *curr)
{
	t_token		*new;
	int			i;

	if (!(new = init_new_token()))
		return (console(FATAL, __func__, __LINE__, "init new token fail").null);
	
	return (new);
}