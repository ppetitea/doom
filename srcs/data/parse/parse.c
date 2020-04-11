/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:54:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/12 00:46:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_parser.h"
#include "data.h"
#include "log.h"
#include "ft/str.h"
#include "ft/io.h"

t_data	*parse_string()
{
	
}

t_data	*parse_integer()
{
	
}

t_data	*parse_float()
{
	
}


t_data	*parse_array()
{
	
}

t_data	*parse_object()
{
	
}

t_data	*parse_key(t_token *token, t_data *parent)
{
	t_data	*new;

	if (!(new = init_new_data()))
		return (console(FATAL, __func__, __LINE__, "newdata fail").null);
	if (!(new->key = ft_strdup(token->data)))
		return (console(FATAL, __func__, __LINE__, "strdup fail").null);
	node_add_child(&parent->node, &new->node);
	return (new);
}

/*
** ANALYSE TOKENS
*/

t_bool		token_is_end(t_token *token)
{
	if (token->type == TOKEN_COMMA)
		return (TRUE);
	if (token->type == TOKEN_UNDEFINED)
		return (TRUE);
	return (TRUE);
}

t_bool		token_is_integer(t_token *token)
{
	if (token->type == TOKEN_LESS)
		token = (t_token*)token->node.next;
	if (token->type != TOKEN_NUMBER)
		return (FALSE);
	token = (t_token*)token->node.next;
	if (token->type == TOKEN_DOT)
		return (FALSE);
	return (TRUE);
}

t_bool		token_is_float(t_token *token)
{
	if (token->type == TOKEN_LESS)
		token = (t_token*)token->node.next;
	if (token->type != TOKEN_NUMBER)
		return (FALSE);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_DOT)
		return (FALSE);
	return (TRUE);
}

t_bool		token_is_value(t_token *token)
{
	if (token_is_float(token) || token_is_integer(token))
		return (TRUE);
	if (token->type == TOKEN_STRING)
		return (TRUE);
	return (FALSE);
}

t_bool		token_is_curly_braces(t_token *token)
{
	if (token->type != TOKEN_CURLY_BRACES_OPEN)
		return (FALSE);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_CURLY_BRACES_CLOSE)
		return (FALSE);
	return (TRUE);
}

t_bool		token_is_brackets(t_token *token)
{
	if (token->type != TOKEN_BRACKET_OPEN)
		return (FALSE);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_BRACKET_CLOSE)
		return (FALSE);
	return (TRUE);
}

t_bool		token_is_key(t_token *token)
{
	if (token->type != TOKEN_STRING)
		return (FALSE);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_COLON)
		return (FALSE);
	token = (t_token*)token->node.next;
	if (!token_is_value(token))
		return (FALSE);
	token = (t_token*)token->node.next;
	if (token->type != TOKEN_COLON)
		return (FALSE);
	return (TRUE);
}

/*
** PARSE TOKENS
*/

t_result	parse(t_token *token, t_data *parent)
{
	t_data	*new;

	if (token->type == TOKEN_STRING && ((t_token*)token->node.next)->type == TOKEN_COLON)
	{
		new = parse_key(token, parent);
		token = (t_token*)token->node.next->next;
	}
	if (token->type == TOKEN_NUMBER)
	{
		if (!(new = init_new_data()))
			return (console(FATAL, __func__, __LINE__, "newdata fail").err);
		if (!(new->key = ft_strdup(token->data)))
			return (console(FATAL, __func__, __LINE__, "strdup fail").err);
		node_add_child(&parent->node, &new->node);
		token = (t_token*)token->node.next->next;
	}
	else if (token->type == TOKEN_CURLY_BRACES_OPEN)
	{
		new->type = LIST;
		if (!parse((t_token*)token, new))
			return (console(FATAL, __func__, __LINE__, "parse fail").err);
		token = (t_token*)token->node.next;
	}
	else if (token->type == TOKEN_CURLY_BRACES_CLOSE)
		return (OK);
	return (OK);
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