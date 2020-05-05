/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 11:00:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/05 21:07:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "maths/maths.h"
#include "types.h"

/*
	INIT NODE
*/

t_result init_node(t_node *self)
{
	if (self == NULL)
		return (ERROR);
	self->prev = self;
	self->next = self;
	self->parent = NULL;
	self->childs = NULL;
	return (OK);
}

t_result init_list(t_node *self)
{
	if (self == NULL)
		return (ERROR);
	init_node(self);
	if (!(self->childs = malloc(sizeof(t_node))))
		return (ERROR);
	init_node(self->childs);
	return (OK);
}

t_node *init_new_node()
{
	t_node *self;

	if (!(self = malloc(sizeof(t_node))))
		return (NULL);
	if (init_node(self))
		return (self);
	free(self);
	return (NULL);
}

t_node *init_new_list()
{
	t_node *self;

	if (!(self = malloc(sizeof(t_node))))
		return (NULL);
	if (!init_list(self))
	{
		free(self);
		return (NULL);
	}
	return (self);
}

/* 
	ITER NODE
*/

t_result node_foreach_prev(t_node *self, t_result (*fn)(t_node *))
{
	t_node *curr;
	t_node *prev;

	if (self == NULL)
		return (ERROR);
	curr = self->childs;
	prev = curr->prev;
	if (self->childs)
	{
		while ((curr = prev) != self->childs)
		{
			prev = prev->prev;
			node_foreach_prev((t_node *)curr, fn);
			fn((t_node *)curr);
		}
	}
	return (OK);
}

t_result node_foreach_next(t_node *self, t_result (*fn)(t_node *))
{
	t_node *curr;
	t_node *next;

	if (self == NULL)
		return (ERROR);
	curr = self->childs;
	next = curr->next;
	if (self->childs)
	{
		while ((curr = next) != self->childs)
		{
			next = next->next;
			fn((t_node *)curr);
			node_foreach_next((t_node *)curr, fn);
		}
	}
	return (OK);
}

void nodes_foreach_ascend(t_node *node, void (*fn)(t_node *node))
{
	t_node *curr;
	t_node *parent;

	curr = node;
	parent = curr->parent;
	fn(curr);
	while ((curr = parent) != NULL)
	{
		parent = parent->parent;
		fn(curr);
	}
}

/*
** FIND NODE
*/

t_node *node_find(t_node *self, t_bool (*fn)(t_node *))
{
	t_node *find;
	t_node *curr;
	t_node *next;

	if (self == NULL)
		return (ERROR);
	curr = self->childs;
	next = curr->next;
	if (self->childs)
	{
		while ((curr = next) != self->childs)
		{
			next = next->next;
			if (fn((t_node *)curr))
				return (curr);
			if ((find = node_find((t_node *)curr, fn)))
				return (find);
		}
	}
	return (NULL);
}

/*
** NODE GET
*/

t_node	*node_get_child(t_node *node, int index)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = node->childs;
	while ((curr = curr->next) != node->childs)
	{
		if (i == index)
			return (curr);
		i++;
	}
	return (NULL);
}

t_node	*node_get_root(t_node *node)
{
	t_node *curr;
	t_node *parent;

	curr = node;
	parent = curr->parent;
	while (parent != NULL)
	{
		curr = parent;
		parent = parent->parent;
	}
	return (curr);
}

/* 
	ADD NODE
*/
void node_add_prev(t_node *head, t_node *new)
{
	if (head == NULL || new == NULL)
		return;
	new->next = head;
	new->prev = head->prev;
	new->prev->next = new;
	head->prev = new;
}

void node_add_next(t_node *head, t_node *new)
{
	if (head == NULL || new == NULL)
		return;
	new->next = head->next;
	new->next->prev = new;
	new->prev = head;
	head->next = new;
}

void node_add_index(t_node *head, t_node *new, int index)
{
	int i;

	if (head == NULL || new == NULL)
		return;
	i = 0;
	while (i < index)
		i++;
	node_add_prev(head, new);
}

void node_add_child(t_node *head, t_node *new)
{
	if (head == NULL || head->childs == NULL || new == NULL)
		return;
	node_add_prev(head->childs, new);
	new->parent = head;
}

/* 
	DELETE NODE
*/

t_result node_del(t_node *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (node->childs)
	{
		free(node->childs);
		node->childs = NULL;
	}
	free(node);
	return (OK);
}

void nodes_del(t_node *node)
{
	node_foreach_prev(node, node_del);
}

/*
** COUNT NODES
*/

int node_childs_amount(t_node *node)
{
	t_node *curr;
	int i;

	i = 0;
	curr = node->childs;
	while ((curr = curr->next) != node->childs)
		i++;
	return (i);
}

int node_parents_amount(t_node *node)
{
	t_node *curr;
	t_node *parent;
	int amount;

	amount = 0;
	curr = node;
	parent = curr->parent;
	while ((curr = parent) != NULL)
	{
		parent = parent->parent;
		amount++;
	}
	return (amount);
}

/*
** SORT NODES
*/

void	swap_nodes(t_node *a, t_node *b)
{
	t_node tmp;

	b->next->prev = a;
	b->prev->next = a;
	a->next->prev = b;
	a->prev->next = b;
	tmp.prev = a->prev;
	tmp.next = a->next;
	a->prev = b->prev;
	a->next = b->next;
	b->prev = tmp.prev;
	b->next = tmp.next;
}

void	bubble_sort_node_childs(t_node *parent,
			t_bool(*rule)(t_node*, t_node*))
{
	t_node	*pos;
	t_node	*next;
	size_t	len;
	size_t	i;

	len = node_childs_amount(parent);
	i = 0;
	while (i < len)
	{
		pos = parent->childs;
		next = pos->next;
		while ((pos = next)->next != parent->childs)
		{
			next = next->next;
			if (rule(pos, next))
				swap_nodes(pos, next);
		}
		i++;
	}
}

/* 
	TEST NODE
*/

t_test_node *init_new_test_node()
{
	t_test_node *self;

	if (!(self = malloc(sizeof(t_test_node))))
		return (NULL);
	init_list(&self->node);
	self->key = NULL;
	return (self);
}

t_result debug_test_node(t_node *node)
{
	t_test_node *test;

	test = (t_test_node *)node;
	printf("%s\n", test->key);
	return (OK);
}

void test_node_creation()
{
	t_test_node *list;
	t_test_node *node;
	t_test_node *sub_node;

	printf("Test nodes\n");
	list = init_new_test_node();
	list->key = strdup("root");
	for (int i = 0; i < 10; i++)
	{
		if ((node = init_new_test_node()))
		{
			node->key = ft_itoa(i);
			node_add_child(&list->node, &node->node);
		}
		else
		{
			printf("ERROR\n");
		}
		for (int j = 0; j < 10; j++)
		{
			if ((sub_node = init_new_test_node()))
			{
				sub_node->key = ft_itoa(i * 10 + j);
				node_add_child(&node->node, &sub_node->node);
			}
			else
			{
				printf("ERROR\n");
			}
		}
	}
	nodes_del(list->node.childs->prev);
	// nodes_foreach_ascend(list->node.prev->childs->prev->childs->prev, nodes_del);
	node_foreach_next(&list->node, debug_test_node);
}