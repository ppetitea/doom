/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 22:20:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/12 16:10:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_parser.h"
#include "log.h"
#include "ft/str.h"
#include "ft/io.h"

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
 
#include <unistd.h>
void	ft_putnstr(char *s, int n)
{
	int len;

	ft_putstr("→");
	len = ft_strlen(s);
	if (s)
		write(1, s, (n < len) ? n : len);
	ft_putstr("←\n");
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
	if (!str[i])
		return (i - 1);
	return (i + 1);
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
		if (!(new = init_new_token()))
			return (console(FATAL, __func__, __LINE__, "new token fail").err);
		// i += token_set_str(new, &data[i + 1]);
		// i += token_set_nbr(new, &data[i]);
		// i += token_set_less(new, "-");
		// i += token_set_dot(new, ".");
		// i += token_set_comma(new, ".");
		// i += token_set_colon(new, ".");
		// i += token_set_bracet_open(new, "[");
		// i += token_set_bracet_close(new, "]");
		// i += token_set_curly_braces_open(new, "{");
		// i += token_set_curly_braces_close(new, "}");
		if (isquote(data[i]))
		{
			token_set(new, TOKEN_STRING, strcdup_bef(&data[i + 1], isquote));
			node_add_child(&last->node, &new->node);
			i += stri(&data[i + 1], isquote) + 1;
		}
		else if (ft_isdigit(data[i]))
		{
			token_set(new, TOKEN_NUMBER, strcdup_bef(&data[i], isntdigit));
			node_add_child(&last->node, &new->node);
			i += stri(&data[i], isntdigit) - 1;
		}
		else if (data[i] == '-')
		{
			token_set(new, TOKEN_LESS, ft_strndup(&data[i], 1));
			node_add_child(&last->node, &new->node);
			i++;
		}
		else if (data[i] == '.')
		{
			token_set(new, TOKEN_DOT, ft_strndup(&data[i], 1));
			node_add_child(&last->node, &new->node);
			i++;
		}
		else if (data[i] == ',')
		{
			token_set(new, TOKEN_COMMA, ft_strndup(&data[i], 1));
			node_add_child(&last->node, &new->node);
			i++;
		}
		else if (data[i] == ':')
		{
			token_set(new, TOKEN_COLON, ft_strndup(&data[i], 1));
			node_add_child(&last->node, &new->node);
			i++;
		}
		else if (data[i] == '[')
		{
			token_set(new, TOKEN_BRACKET_OPEN, ft_strndup(&data[i], 1));
			node_add_child(&last->node, &new->node);
			last = new;
			i++;
		}
		else if (data[i] == ']')
		{
			token_set(new, TOKEN_BRACKET_CLOSE, ft_strndup(&data[i], 1));
			if (last->node.parent)
				last = (t_token*)last->node.parent;
			else
				return (tokens_del_and_quit(root, "Too many ] detected").err);
			node_add_child(&last->node, &new->node);
			i++;
		}
		else if (data[i] == '{')
		{
			token_set(new, TOKEN_CURLY_BRACES_OPEN, ft_strndup(&data[i], 1));
			node_add_child(&last->node, &new->node);
			last = new;
			i++;
		}
		else if (data[i] == '}')
		{
			token_set(new, TOKEN_CURLY_BRACES_CLOSE, ft_strndup(&data[i], 1));
			if (last->node.parent)
				last = (t_token*)last->node.parent;
			else
				return (tokens_del_and_quit(root, "Too many } detected").err);
			node_add_child(&last->node, &new->node);
			i++;
		}
		else
		{
			ft_putnstr(&data[i], 10);
			return (tokens_del_and_quit(root, "Unknow token detected").err);
		}
	}
	return (OK);
}