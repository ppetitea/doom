/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:35:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/30 00:50:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg/arg.h"
#include "log/log.h"
#include <stdlib.h>
#include "ft/io.h"
#include "ft/str.h"

#include <stdio.h> //				NORME ERROR

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
