/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:54:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/12 16:23:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/data_parser.h"
#include "utils/data.h"
#include "utils/log.h"
#include "ft/str.h"
#include "ft/io.h"
#include "maths/maths.h"
#include <stdlib.h>

/*
** ANALYSE TOKENS
*/

t_token		*token_is_value_next(t_token *token)
{
	if (token->type == TOKEN_COMMA)
		return ((t_token*)token->node.next);
	if (token->type == TOKEN_HEAD)
		return (token);
	return (NULL);
}

t_token		*token_is_string(t_token *token)
{
	if (token->type != TOKEN_STRING)
		return (NULL);
	token = (t_token*)token->node.next;
	return (token_is_value_next(token));
}

t_token		*token_is_integer(t_token *token)
{
	if (token->type == TOKEN_LESS)
		token = (t_token*)token->node.next;
	if (token->type != TOKEN_NUMBER)
		return (NULL);
	token = (t_token*)token->node.next;
	if (token->type == TOKEN_DOT)
		return (NULL);
	return (token_is_value_next(token));
}

t_token		*token_is_float(t_token *token)
{
	if (token->type == TOKEN_LESS)
		token = (t_token*)token->node.next;
	if (token->type != TOKEN_NUMBER)
		return (NULL);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_DOT)
		return (NULL);
	token = (t_token*)token->node.next;
	if (token->type == TOKEN_NUMBER)
		token = (t_token*)token->node.next;
	return (token_is_value_next(token));
}

t_token		*token_is_value(t_token *token)
{
	t_token	*ret;

	if ((ret = token_is_string(token)))
		return (ret);
	if ((ret = token_is_integer(token)))
		return (ret);
	if ((ret = token_is_float(token)))
		return (ret);
	return (NULL);
}

t_token		*token_is_curly_braces(t_token *token)
{
	if (token->type != TOKEN_CURLY_BRACES_OPEN)
		return (NULL);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_CURLY_BRACES_CLOSE)
		return (NULL);
	token = (t_token*)token->node.next;
	return (token_is_value_next(token));
}

t_token		*token_is_brackets(t_token *token)
{
	if (token->type != TOKEN_BRACKET_OPEN)
		return (NULL);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_BRACKET_CLOSE)
		return (NULL);
	token = (t_token*)token->node.next;
	return (token_is_value_next(token));
}

t_token		*token_is_container(t_token *token)
{
	t_token	*ret;

	if ((ret = token_is_brackets(token)))
		return (ret);
	if ((ret = token_is_curly_braces(token)))
		return (ret);
	return (NULL);
}

t_token		*token_is_key_next(t_token *token)
{
	t_token	*ret;

	if ((ret = token_is_value(token)))
		return (ret);
	if ((ret = token_is_container(token)))
		return (ret);
	return (NULL);
}

t_token		*token_is_key(t_token *token)
{
	if (token->type != TOKEN_STRING)
		return (NULL);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_COLON)
		return (NULL);
	token = (t_token*)token->node.next;
	if ((token = token_is_key_next(token)))
		return (token);
	return (NULL);
}

/*
** PARSE TOKENS
*/

t_result	parse_string(t_token *token, t_data *data)
{
	if (!(data->value.s = ft_strdup(token->data)))
		return (console(FATAL, __func__, __LINE__, "strdup fail").err);
	data->type = STRING;
	return (OK);
}

t_result	parse_integer(t_token *token, t_data *data)
{
	if (!(data->value.i = ft_atoi(token->data)))
		return (console(FATAL, __func__, __LINE__, "atoi fail").err);
	data->type = INT;
	return (OK);
}

t_result	parse_float(t_token *token, t_data *data)
{
	char	*tmp;
	char	*f;
	
	if (!(f = ft_strjoin(token->data, ((t_token*)token->node.next)->data)))
		return (console(FATAL, __func__, __LINE__, "strjoin fail").err);
	tmp = f;
	token = (t_token*)token->node.next;
	if (!(f = ft_strjoin(f, ((t_token*)token->node.next)->data)))
	{
		free(tmp);
		return (console(FATAL, __func__, __LINE__, "strjoin fail").err);
	}
	free(tmp);
	if (!(data->value.f = ft_atof(f)))
	{
		free(f);
		return (console(FATAL, __func__, __LINE__, "atof fail").err);
	}
	free(f);
	data->type = FLOAT;
	return (OK);
}

t_result	parse_value(t_token *token, t_data *data)
{
	if (token_is_string(token) && !parse_string(token, data))
		return (console(FATAL, __func__, __LINE__, "parse string fail").err);
	else if (token_is_integer(token) && !parse_integer(token, data))
		return (console(FATAL, __func__, __LINE__, "parse int fail").err);
	else if (token_is_float(token) && !parse_float(token, data))
		return (console(FATAL, __func__, __LINE__, "parse float fail").err);
	return (OK);
}

t_result	parse_container(t_token *token, t_data *data,
				t_result (*recursive_data_parsing)(t_token*, t_data*))
{
	if (token_is_brackets(token))
		data->type = ARRAY;
	else if (token_is_curly_braces(token))
		data->type = LIST;
	else
		return (console(FATAL, __func__, __LINE__, "unknow container").err);
	token = (t_token*)token->node.childs->next;
	recursive_data_parsing(token, data);
	return (OK);
}

t_result	parse_key_next(t_token *token, t_data *data,
				t_result (*recursive_data_parsing)(t_token*, t_data*))
{
	if (token_is_value(token))
	{
		if (!(parse_value(token, data)))
			return (console(FATAL, __func__, __LINE__, "parse_value fail").err);
	}
	else if (token_is_container(token))
	{
		if (!(parse_container(token, data, recursive_data_parsing)))
			return (console(FATAL, __func__, __LINE__, "parse_list fail").err);
	}
	else
		return (console(FATAL, __func__, __LINE__, "unknow key_next").err);
	return (OK);
}

t_data	*parse_key(t_token *token, t_data *parent, int index)
{
	t_data	*new;

	if (!(new = init_new_data()))
		return (console(FATAL, __func__, __LINE__, "newdata fail").null);
	if (parent->type == LIST && !(new->key = ft_strdup(token->data)))
		return (console(FATAL, __func__, __LINE__, "strdup fail").null);
	else if (parent->type == ARRAY && !(new->key = ft_itoa(index)))
		return (console(FATAL, __func__, __LINE__, "itoa fail").null);
	node_add_child(&parent->node, &new->node);
	return (new);
}

t_result	recursive_data_parsing(t_token *token, t_data *parent)
{
	t_data	*new;
	t_token	*next_token;
	int		index;

	index = 0;
	while (token->type != TOKEN_HEAD)
	{
		if (parent->type == ARRAY && !(next_token = token_is_key_next(token)))
			return (console(FATAL, __func__, __LINE__, "invalid array").err);
		else if (parent->type == LIST && !(next_token = token_is_key(token)))
			return (console(FATAL, __func__, __LINE__, "invalid key").err);
		if (!(new = parse_key(token, parent, index)))
			return (console(FATAL, __func__, __LINE__, "parse_key").err);
		if (parent->type == LIST)
			token = (t_token*)token->node.next->next;
		if (!parse_key_next(token, new, recursive_data_parsing))
			return (console(FATAL, __func__, __LINE__, "parse_next fail").err);
		token = next_token;
		index++;
	}
	return (OK);
}

t_data		*parse(t_token *root_token)
{
	t_data	*root;
	t_token	*token;

	if (!(root = new_data_set("root", UNDEFINED, (t_val)0)))
		return (console(FATAL, __func__, __LINE__, "new data fail").null);
	token = (t_token*)root_token->node.childs->next;
	if (token_is_curly_braces(token))
		root->type = LIST;
	else if (token_is_brackets(token))
		root->type = ARRAY;
	else
		return (console(FATAL, __func__, __LINE__, "must begin {} or []").null);
	token = (t_token*)token->node.childs->next;
	if (!recursive_data_parsing(token, root))
		return (console(FATAL, __func__, __LINE__, "data_parsing fail").null);
	return (root);
}
