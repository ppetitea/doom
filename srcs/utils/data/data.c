/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:35:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/06 00:38:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "log.h"
#include <stdlib.h>
#include "ft/io.h"
#include "ft/str.h"

#include <stdio.h> //				NORME ERROR
/*
** DATA FOREACH
*/

t_result	data_foreach_prev(t_data *self, t_result (*fn)(t_data*))
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
			data_foreach_prev((t_data*)curr, fn);
			fn((t_data*)curr);
		}
	}
	return (OK);
}

t_result	data_foreach_next(t_data *self, t_result (*fn)(t_data*))
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
			fn((t_data*)curr);
			data_foreach_next((t_data*)curr, fn);
		}
	}
	return (OK);
}

/*
** PRINT DATA
*/

t_result	print_data(t_data *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	ft_putstr(self->key);
	ft_putstr(": ");
	if (self->type == CHAR)
		ft_putstr(&self->value.c);
	else if (self->type == INT)
		ft_putnbr(self->value.i);
	else if (self->type == FLOAT)
		printf("%.2f", self->value.f); //				NORME ERROR
	else if (self->type == STRING)
		ft_putstr(self->value.s);
	ft_putstr("\n");
	return (OK);
}

t_result	print_datas(t_data *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	print_data(self);
	data_foreach_next(self, print_data);
	return (OK);
}

/*
** INIT DATA
*/
t_result	init_data(t_data *self)
{
	if (!init_list(&self->node))
		return (console(WARN, __func__, __LINE__, "init_list failed").warn);
	self->key = NULL;
	self->value.s = NULL;
	self->type = UNDEFINED;
	return (OK);
}

t_data		*init_new_data()
{
	t_data *self;

	if (!(self = malloc(sizeof(t_data))))
		return (console(FATAL, __func__, __LINE__, "malloc failed").null);
	init_data(self);
	return (self);
}

/*
** DELETE DATA
*/

t_result	data_del(t_data *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	if (self->key)
		free(self->key);
	if (self->type == STRING && self->value.s)
		free(self->value.s);
	node_del(&self->node);
	return (OK);
}

t_result	datas_childs_del(t_data *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	data_foreach_prev(self, data_del);
	return (OK);
}

t_result	datas_del(t_data *self)
{
	if (self == NULL)
		return (console(WARNING, __func__, __LINE__, "NULL pointer").warn);
	data_foreach_prev(self, data_del);
	data_del(self);
	return (OK);
}

t_res		datas_del_and_quit(t_data *self)
{
	if (self == NULL)
		return (console(FATAL, __func__, __LINE__, "NULL pointer"));
	datas_del(self);
	return (response());
}

/*
** DATA SETUP
*/

t_result data_set(t_data *self, char *key, t_data_type type, t_val val)
{
	if (self == NULL || key == NULL || (type == STRING && val.s == NULL))
		return (console(FATAL, __func__, __LINE__, "NULL pointer").err);
	if (!(self->key = ft_strdup(key)))
		return (console(FATAL, __func__, __LINE__, "strdup fail").err);
	if (type != CHAR && type != INT && type != FLOAT && type != STRING)
		return (console(FATAL, __func__, __LINE__, "unknow type").err);
	self->type = type;
	if (type == STRING)
	{
		if (!(self->value.s = ft_strdup(val.s)))
			return (console(FATAL, __func__, __LINE__, "strdup fail").err);
	}
	else
		self->value = val;
	return (OK);
}

t_data	*new_data_set(char *key, t_data_type type, t_val val)
{
	t_data *self;

	if (key == NULL || (type == STRING && val.s == NULL))
		return (console(FATAL, __func__, __LINE__, "NULL pointer").null);
	if (!(self = init_new_data()))
		return (console(FATAL, __func__, __LINE__, "new data fail").null);
	if (!data_set(self, key, type, val))
	{
		datas_del(self);
		return (console(FATAL, __func__, __LINE__, "set data fail").null);
	}
	return (self);
}

/* 
	TEST DATA
*/
#include "maths/maths.h"

t_result	test_data_creation()
{
	t_data *list;
	t_data *data;
	t_data *data_child;

	printf("Test datas\n");
	if (!(list = new_data_set("root", STRING, (t_val)"bidibou parent <3")))
		return (console(FATAL, __func__, __LINE__, "set data fail").err);
	for (int i = 0; i < 10; i++) {
		if (!(data = new_data_set(ft_itoa(i), STRING, (t_val)"bidibou <3")))
			console(FATAL, __func__, __LINE__, "set new data fail");
		else	
			node_add_child(&list->node, &data->node);
		for (int j = 0; j < 10; j++) {
			if (!(data_child = new_data_set(ft_itoa(i * 10 + j),
				STRING, (t_val)"bidibou child <3")))
				console(FATAL, __func__, __LINE__, "set new data fail");
			else
				node_add_child(&data->node, &data_child->node);
		}
	}
	datas_childs_del((t_data*)(list->node.childs->next));
	print_datas(list);
	return (OK);
}