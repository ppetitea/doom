/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:31:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/12 01:08:51 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_parser.h"
#include "log.h"
#include "ft/io.h"
#include "ft/str.h"
#include "maths/maths.h"
#include <stdlib.h>

/*
** FOREACH TOKEN
*/

t_result	token_foreach_prev(t_token *self, t_result (*fn)(t_token*))
{
	t_node	*curr;
	t_node	*prev;

	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	curr = self->node.childs;
	prev = curr->prev;
	if (self->node.childs)
	{
		while ((curr = prev) != self->node.childs)
		{
			prev = prev->prev;
			token_foreach_prev((t_token*)curr, fn);
			fn((t_token*)curr);
		}
	}
	return (OK);
}

t_result	token_foreach_next(t_token *self, t_result (*fn)(t_token*))
{
	t_node	*curr;
	t_node	*next;

	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	curr = self->node.childs;
	next = curr->next;
	if (self->node.childs) {
		while ((curr = next) != self->node.childs)
		{
			next = next->next;
			fn((t_token*)curr);
			token_foreach_next((t_token*)curr, fn);
		}
	}
	return (OK);
}

/*
** PRINT TOKEN
*/

void		print_token_type(t_token_type type)
{
	if (type == TOKEN_UNDEFINED)
		ft_putstr("Token: undefined ");
	else if (type == TOKEN_STRING)
		ft_putstr("Token: String ");
	else if (type == TOKEN_NUMBER)
		ft_putstr("Token: Number ");
	else if (type == TOKEN_LESS)
		ft_putstr("Token: Less ");
	else if (type == TOKEN_DOT)
		ft_putstr("Token: Dot ");
	else if (type == TOKEN_COMMA)
		ft_putstr("Token: Comma ");
	else if (type == TOKEN_COLON)
		ft_putstr("Token: Colon ");
	else if (type == TOKEN_BRACKET_OPEN)
		ft_putstr("Token: Bracket Open ");
	else if (type == TOKEN_BRACKET_CLOSE)
		ft_putstr("Token: Bracket Close ");
	else if (type == TOKEN_CURLY_BRACES_OPEN)
		ft_putstr("Token: Curly Braces Open ");
	else if (type == TOKEN_CURLY_BRACES_CLOSE)
		ft_putstr("Token: Curly Braces Close ");
}

t_result	print_token(t_token *self)
{
	int parents;
	int	i;

	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	parents = node_parents_amount(&self->node);
	i = -1;
	while (++i < parents)
		ft_putstr("   ");
	print_token_type(self->type);
	ft_putstr("line-");
	ft_putnbr(self->line);
	ft_putstr(" col-");
	ft_putnbr(self->column);
	ft_putstr(" length: ");
	ft_putnbr(self->length);
	ft_putstr("\n");
	i = -1;
	while (++i < parents)
		ft_putstr("   ");
	ft_putstr(self->data);
	ft_putstr("\n");
	return (OK);
}

t_result	print_tokens(t_token *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	print_token(self);
	token_foreach_next(self, print_token);
	return (OK);
}

/*
** INIT TOKEN
*/

t_token *init_new_token_head()
{
	t_token *head;

	if ((head = (t_token*)malloc(sizeof(t_token))) == NULL)
		return (console(FATAL, __func__, __LINE__, "malloc failed").null);
	if (!init_node(&head->node))
		return (console(FATAL, __func__, __LINE__, "init_node fail").null);
	head->line = 0;
	head->column = 0;
	head->data = NULL;
	head->length = 0;
	head->type = TOKEN_HEAD;
	return (OK);
};

t_result init_token(t_token *self)
{
	t_token		*head;

	if (!init_node(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	if (!(head = init_new_token_head()))
		return (console(FATAL, __func__, __LINE__, "new_token_head fail").err);
	self->node.childs = &head->node;
	self->line = 0;
	self->column = 0;
	self->data = NULL;
	self->length = 0;
	self->type = TOKEN_UNDEFINED;
	return (OK);
};

t_token *init_new_token()
{
	t_token *self;

	if ((self = (t_token*)malloc(sizeof(t_token))) == NULL)
		return (console(FATAL, __func__, __LINE__, "malloc failed").null);
	if (!init_token(self))
		return (console(FATAL, __func__, __LINE__, "init_token failed").null);
	return (self);
}

/*
** DELETE TOKEN
*/

t_result	token_del(t_token *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	if (self->data)
		free(self->data);
	node_del(&self->node);
	return (OK);
}

t_result	tokens_childs_del(t_token *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	token_foreach_prev(self, token_del);
	return (OK);
}

t_result	tokens_del(t_token *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	token_foreach_prev(self, token_del);
	token_del(self);
	return (OK);
}

t_res		tokens_del_and_quit(t_token *self, char *msg)
{
	if (self == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer"));
	ft_putstr(msg);
	ft_putchar('\n');
	tokens_del(self);
	return (response());
}

/*
** TOKEN SETUP
*/

t_result token_set(t_token *self, t_token_type type, char *data)
{
	if (self == NULL || data == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer").err);
	self->type = type;
	if (!(self->data = data))
		return (tokens_del_and_quit(self, "ft_strdup fail").err);
	self->length = ft_strlen(self->data);
	return (OK);
}

t_result token_set_pos(t_token *self, int line, int column)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	self->line = line;
	self->column = column;
	return (OK);
}

t_token	*new_token_set(t_token_type type, char *data, int line, int column)
{
	t_token *self;

	if (data == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer").null);
	if (!(self = init_new_token()))
		return (console(FATAL, __func__, __LINE__, "new token fail").null);
	if (!token_set(self, type, data) || !token_set_pos(self, line, column))
	{
		tokens_del(self);
		return (console(FATAL, __func__, __LINE__, "set token fail").null);
	}
	return (self);
}

/* 
	TEST TOKEN
*/
#include "maths/maths.h"
#include <stdio.h>				// NORME ERROR

t_result	test_token_creation()
{
	t_token *list;
	t_token *token;
	t_token *token_child;

	printf("Test tokens\n");
	if (!(list = new_token_set(TOKEN_STRING, "bidibou parent <3", 42, 21)))
		return (console(FATAL, __func__, __LINE__, "set token fail").err);
	for (int i = 0; i < 10; i++) {
		if (!(token = new_token_set(TOKEN_STRING, "bidibou parent <3", i, 0)))
			console(FATAL, __func__, __LINE__, "set new token fail");
		else	
			node_add_child(&list->node, &token->node);
		for (int j = 0; j < 10; j++) {
			if (!(token_child = new_token_set(TOKEN_STRING, "bidibou parent <3",
				i, i * 10 + j)))
				console(FATAL, __func__, __LINE__, "set new token fail");
			else
				node_add_child(&token->node, &token_child->node);
		}
	}
	// tokens_childs_del((t_token*)(list->node.childs->next));
	print_tokens(list);
	return (OK);
}