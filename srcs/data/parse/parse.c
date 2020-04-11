/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:54:30 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/11 18:30:16 by ppetitea         ###   ########.fr       */
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

//					YOU ARE HERE !

t_result	parse(t_token *token, t_data *parent)
{
	t_node	*curr;
	t_data	*new;

	if (token == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer").err);
	curr = token->node.childs;
	while ((curr = curr->next) != token->node.childs)
	{
		if (token->type == TOKEN_CURLY_BRACES_OPEN)
		{
			if (!(new = init_new_data()))
				return (console(FATAL, __func__, __LINE__, "newdata fail").err);
			node_add_child(&parent->node, &new->node);
			parse((t_token*)curr, new);
		}
	}
	return (OK);
}