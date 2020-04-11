/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 22:20:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/11 13:50:17 by ppetitea         ###   ########.fr       */
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

int			ft_next_char(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

char		*ft_strcdup_bef(char *str, char c)
{
	return (ft_strndup(str, ft_next_char(str, c) - 1));
}

char		*ft_strcdup(char *str, char c)
{
	return (ft_strndup(str, ft_next_char(str, c)));
}

t_result	tokenize(char *data, t_node *list)
{
	t_token		*new;
	t_bool		in_string;
	int			i;

	i = 0;
	while (data && data[i])
	{
		in_string = (data[i] == '"') ? !in_string : in_string;

		if (!(new = init_new_token()))
			return (console(FATAL, __func__, __LINE__, "new token fail").err);


		i++;
	}
	return (OK);
}