/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 22:20:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/11 14:59:34 by ppetitea         ###   ########.fr       */
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


int			isquote(char c)
{
	return (c == '"');
}

int			isntdigit(char c)
{
	return (!ft_isdigit(c));
}

int			stri(char *str, int (*fn)(char c))
{
	int i;

	i = 0;
	while (str && str[i] && !fn(str[i]))
		i++;
	return (i);
}

char		*strcdup_bef(char *str, int (*fn)(char c))
{
	return (ft_strndup(str, stri(str, fn) - 1));
}

char		*strcdup(char *str, int (*fn)(char c))
{
	return (ft_strndup(str, stri(str, fn)));
}

t_result	tokenize(char *data, t_token *root)
{
	t_token		*new;
	t_token		*last;
	int			i;

	i = 0;
	last = root;
	while (data && data[i])
	{
		if ((new = init_new_token()))
			return (console(FATAL, __func__, __LINE__, "new token fail").err);
		if (isquote(data[i]))
		{
			token_set(new, TOKEN_STRING, strcdup_bef(&data[i + 1], isquote));
			node_add_child(&last->node, &new->node);
			i += stri(&data[i + 1], isquote) + 1;
		}
		else if (ft_isdigit(data[i]))
		{
			token_set(new, TOKEN_NUMBER, strcdup_bef(&data[i + 1], isntdigit));
			node_add_child(&last->node, &new->node);
			i += stri(&data[i + 1], isntdigit);
		}
		else if (data[i] == '-')
		{
			token_set(new, TOKEN_LESS, ));
			node_add_child(&last->node, &new->node);
			i += stri(&data[i + 1], isntdigit);
		}



	}
	return (OK);
}