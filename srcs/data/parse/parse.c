/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:54:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/12 02:59:17 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_parser.h"
#include "data.h"
#include "log.h"
#include "ft/str.h"
#include "ft/io.h"
#include "maths/maths.h"

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
	token = (t_token*)token->node.next;
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
	token = (t_token*)token->node.next;
	return (token_is_value_next(token));
}

t_token		*token_is_value(t_token *token)
{
	if ((token = token_is_string(token)))
		return (token);
	if ((token = token_is_integer(token)))
		return (token);
	if ((token = token_is_float(token)))
		return (token);
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
	if ((token = token_is_brackets(token)))
		return (token);
	if ((token = token_is_curly_braces(token)))
		return (token);
	return (NULL);
}

t_token		*token_is_key_next(t_token *token)
{
	if ((token = token_is_value(token)))
		return (token);
	if ((token = token_is_container(token)))
		return (token);
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

t_bool	token_is_array_values(t_token *head)
{
	t_token *curr;
	
	curr = (t_token*)head->node.next;
	while (curr != head)
	{
		if (!(curr = token_is_value(curr)))
			return (FALSE);
	}
	return (TRUE);
}

/*
** PARSE TOKENS
*/

t_data	*parse_string()
{
	
}

t_data	*parse_integer()
{
	
}

t_data	*parse_float()
{
	
}

t_result	parse_value(t_data *data, t_token *token)
{
	
}

t_data	*parse_array()
{
	
}

t_data	*parse_object()
{
	
}

t_result	parse_container(t_token *token, t_data *data,
				t_result (*recursive_data_parsing)(t_token*, t_data*))
{
	if (token_is_brackets(token))
		data->type = ARRAY;
	else if (token_is_curly_braces(token))
		data->type = LIST;
	token = (t_token*)token->node.childs->next;
	recursive_data_parsing(token, data);
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
		if (token_is_value(token) && !(parse_value(new, token)))
			return (console(FATAL, __func__, __LINE__, "parse_value fail").err);
		else if (!(parse_container(token, new, recursive_data_parsing)))
			return (console(FATAL, __func__, __LINE__, "parse_list fail").err);
		token = next_token;
		index++;
	}
	return (OK);
}

t_data		*parse(t_token *root_token)
{
	t_data	*root;
	t_token	*token;

	if (!(root = init_new_data()))
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

// t_result	parse(t_token *token_parent, t_data *parent)
// {
// 	t_data	*new;
// 	t_node	*curr;
// 	t_token	*token;

// 	if (token_parent == NULL)
// 		return (console(FATAL, __func__, __LINE__, "NULL pointer").err);
// 	curr = token_parent->node.childs;
// 	while ((curr = curr->next) != token_parent->node.childs)
// 	{
// 		token = (t_token*)curr;
// 		if (token->type == TOKEN_STRING && ((t_token*)token->node.next)->type == TOKEN_COLON)
// 		{
// 			new = parse_key(token, parent);
// 			token = (t_token*)token->node.next->next;
// 		}
// 		if (token->type == TOKEN_NUMBER)
// 		{
// 			if (!(new = init_new_data()))
// 				return (console(FATAL, __func__, __LINE__, "newdata fail").err);
// 			if (!(new->key = ft_strdup(token->data)))
// 				return (console(FATAL, __func__, __LINE__, "strdup fail").err);
// 			node_add_child(&parent->node, &new->node);
// 			token = (t_token*)token->node.next->next;
// 		}
// 		else if (token->type == TOKEN_CURLY_BRACES_OPEN)
// 		{
// 			new->type = LIST;
// 			if (!parse((t_token*)token, new))
// 				return (console(FATAL, __func__, __LINE__, "parse fail").err);
// 			token = (t_token*)token->node.next;
// 		}
// 		else if (token->type == TOKEN_CURLY_BRACES_CLOSE)
// 			return (OK);
// 	}
// 	return (OK);
// }