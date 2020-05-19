/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:35:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/19 22:40:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg/arg.h"
#include "log/log.h"
#include <stdlib.h>
#include "ft/io.h"
#include "ft/str.h"
#include "data/data.h"
#include <stdio.h> //				NORME ERROR

/*
** arguments'list
*/

/*
** test argument properties
*/
t_bool		is_arg_list_type_valid(t_arg_type type)
{
	if (type != ARG_INT && type != ARG_FLOAT && type != ARG_CHAR &&
		type != ARG_STRING && type != ARG_POINTER && type != ARG_REF)
		return (FALSE);
	return (TRUE);
}

t_bool		is_arg_match(t_arg_list *node, t_arg_type type, t_argv value)
{
	if (node == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").false);
	if (!is_arg_list_type_valid(type))
		return (console(FATAL, __func__, __LINE__, "wrong arg type").false);
	if (node->type != type)
		return (FALSE);
	else if (type == ARG_INT && node->value.i == value.i)
		return (TRUE);
	else if (type == ARG_FLOAT && node->value.f == value.f)
		return (TRUE);
	else if (type == ARG_CHAR && node->value.c == value.c)
		return (TRUE);
	else if (type == ARG_STRING && !ft_strcmp(node->value.s, value.s))
		return (TRUE);
	else if (type == ARG_POINTER && node->value.p == value.p)
		return (TRUE);
	else if (type == ARG_REF && node->value.ref == value.ref)
		return (TRUE);
	return (FALSE);
}

t_result init_arg_list(t_arg_list *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->type = ARG_POINTER;
	self->value.p = NULL;
	return (OK);
};

t_arg_list *init_new_arg_list()
{
	t_arg_list *self;

	if (!(self = malloc(sizeof(t_arg_list))))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").null);
	init_arg_list(self);
	return (self);
}

t_result del_arg_list(t_arg_list *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (self->type == ARG_STRING && self->value.s)
		free(self->value.s);
	else if (self->type == ARG_POINTER && self->value.p)
		free(self->value.p);
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_arg_list(t_arg_list *self)
{
	if (!del_arg_list(self))
		return (console(FATAL, __func__, __LINE__, "del_arg_list fail").err);
	free(self);
	return (OK);
}

t_result set_arg_list(t_arg_list *self, t_arg_type type, t_argv value)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (type != ARG_INT && type != ARG_FLOAT && type != ARG_CHAR &&
		type != ARG_STRING && type != ARG_POINTER && type != ARG_REF)
		return (console(FATAL, __func__, __LINE__, "wrong arg type").err);
	self->type = type;
	self->value = value;
	return (OK);
}

t_arg_list *set_new_arg_list(t_arg_type type, t_argv value)
{
	t_arg_list *self;

	if (!(self = init_new_arg_list()))
		return (console(FATAL, __func__, __LINE__, "init_arg_list fail").null);
	if (!set_arg_list(self, type, value) && del_arg_list)
		return (console(FATAL, __func__, __LINE__, "set_arg_list fail").null);
	return (self);
}

t_arg_list *list_add_new_arg_list(t_list_head *list, t_arg_type type,
	t_argv value)
{
	t_arg_list *self;

	if (!list)
		return (console(FATAL, __func__, __LINE__, "null pointer").null);
	if (!is_arg_list_type_valid(type))
		return (console(FATAL, __func__, __LINE__, "wrong type").null);
	if (!(self = set_new_arg_list(type, value)))
		return (console(FATAL, __func__, __LINE__, "set_arg_list fail").null);
	list_add_entry(&self->node, list);
	return (self);
}

t_arg_list	*arg_list_find(t_list_head *list, t_arg_type type, t_argv value)
{
	t_arg_list	*arg_item;
	t_list_head *curr;

	curr = list;
	while ((curr = curr->next) != list)
	{
		arg_item = (t_arg_list*)curr;
		if (is_arg_match(arg_item, type, value))
			return (arg_item);
	}
	return (NULL);
}

/*
** ARG FOREACH
*/
t_result	arg_foreach_prev(t_arg *self, t_result (*fn)(t_arg*))
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
			arg_foreach_prev((t_arg*)curr, fn);
			fn((t_arg*)curr);
		}
	}
	return (OK);
}

t_result	arg_foreach_next(t_arg *self, t_result (*fn)(t_arg*))
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
			fn((t_arg*)curr);
			arg_foreach_next((t_arg*)curr, fn);
		}
	}
	return (OK);
}

/*
** PRINT ARG
*/

t_result	print_arg(t_arg *self)
{
	int		parent_amount;
	int		i;

	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	parent_amount = node_parents_amount(&self->node);
	i = -1;
	while (++i < parent_amount)
		ft_putstr("   ");
	if (self->type == ARG_CHAR)
		ft_putstr(&self->value.c);
	else if (self->type == ARG_INT)
		ft_putnbr(self->value.i);
	else if (self->type == ARG_FLOAT)
		ft_putnbr((int)self->value.f);
	else if (self->type == ARG_STRING)
		ft_putstr(self->value.s);
	else
		ft_putstr("list or ref");
	ft_putstr("\n");
	return (OK);
}

t_result	print_args(t_arg *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	print_arg(self);
	arg_foreach_next(self, print_arg);
	return (OK);
}

/*
** INIT ARG
*/
t_result	init_arg(t_arg *self)
{
	if (!init_list(&self->node))
		return (console(WARN, __func__, __LINE__, "init_list failed").warn);
	self->value.p = NULL;
	self->type = ARG_POINTER;
	return (OK);
}

t_arg		*init_new_arg()
{
	t_arg *self;

	if (!(self = malloc(sizeof(t_arg))))
		return (console(FATAL, __func__, __LINE__, "malloc failed").null);
	init_arg(self);
	return (self);
}

/*
** DELETE ARG
*/

t_result	arg_del(t_arg *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	if (self->type == ARG_STRING && self->value.s)
		free(self->value.s);
	else if (self->type == ARG_POINTER && self->value.p)
		free(self->value.p);
	return (OK);
}

t_result	del_new_arg(t_arg *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	arg_del(self);
	node_del(&self->node);
	return (OK);
}

t_result	args_childs_del(t_arg *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	arg_foreach_prev(self, arg_del);
	return (OK);
}

t_result	args_del(t_arg *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	arg_foreach_prev(self, arg_del);
	arg_del(self);
	return (OK);
}

t_res		args_del_and_quit(t_arg *self)
{
	if (self == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer"));
	args_del(self);
	return (response());
}

/*
** ARG SETUP
*/

t_result set_arg(t_arg *self, t_arg_type type, t_argv val)
{
	if (self == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer").err);
	if (type < ARG_INT || ARG_LIST < type)
		return (console(FATAL, __func__, __LINE__, "unknow type").err);
	self->type = type;
	if (type == ARG_STRING && !(self->value.s = ft_strdup(val.s)))
		return (console(FATAL, __func__, __LINE__, "strdup fail").err);
	else if (type == ARG_LIST)
		self->value.list = self->node.childs;
	else
		self->value = val;
	return (OK);
}

t_arg	*set_new_arg(t_arg_type type, t_argv val)
{
	t_arg *self;

	if (!(self = init_new_arg()))
		return (console(FATAL, __func__, __LINE__, "new arg fail").null);
	if (!set_arg(self, type, val) && args_del(self))
		return (console(FATAL, __func__, __LINE__, "set arg fail").null);
	return (self);
}

t_arg	*data_to_arg(t_data *data)
{
	if (data->type == CHAR)
			return (set_new_arg(ARG_CHAR, (t_argv)data->value.c));
	if (data->type == INT)
			return (set_new_arg(ARG_INT, (t_argv)data->value.i));
	if (data->type == FLOAT)
			return (set_new_arg(ARG_FLOAT, (t_argv)data->value.f));
	if (data->type == STRING)
			return (set_new_arg(ARG_STRING, (t_argv)data->value.s));
	if (data->type == LIST)
			return (set_new_arg(ARG_LIST, (t_argv)NULL));
	return (console(FATAL, __func__, __LINE__, "unknow data type").null);
}

t_arg	*data_list_to_arg_list(t_data *parent)
{
	t_node	*curr;
	t_arg	*arg;
	t_arg	*child;
	t_data	*data;

	if (!(arg = set_new_arg(ARG_LIST, (t_argv)NULL)))
		return (console(FATAL, __func__, __LINE__, "set_new_arg fail").null);
	curr = parent->node.childs;
	while ((curr = curr->next) != parent->node.childs)
	{
		data = (t_data*)curr;
		if (data->type == LIST && (child = data_list_to_arg_list(data)))
			node_add_child(&arg->node, &child->node);
		else if ((child = data_to_arg(data)))
			node_add_child(&arg->node, &child->node);
	}
	return (arg);
}
