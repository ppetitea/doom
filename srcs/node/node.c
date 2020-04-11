#include "node.h"
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
		return (ERR);
	self->prev = self;
	self->next = self;
	self->parent = NULL;
	self->childs = NULL;
	return (OK);
}

t_result	init_list(t_node *self)
{
	if (self == NULL)
		return (ERR);
	init_node(self);
	if (!(self->childs = malloc(sizeof(t_node))))
		return (ERR);
	init_node(self->childs);
	return (OK);
}

t_node	*init_new_node()
{
	t_node *self;

	if (!(self = malloc(sizeof(t_node))))
		return (NULL);
	if (init_node(self))
		return (self);
	free(self);
	return (NULL);
}

t_node 	*init_new_list()
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

void	nodes_foreach(t_node *node, void (*fn)(t_node *node))
{
	t_node *child;
	t_node *next;

	if (node->childs != NULL)
	{
		child = node->childs;
		next = child->next;
		while ((child = next) != node->childs)
		{
			next = next->next;
			nodes_foreach(child, fn);
		}
	}
	fn(node);
}

void	nodes_foreach_ascend(t_node *node, void (*fn)(t_node *node))
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
	ADD NODE
*/
void	node_add_prev(t_node *head, t_node *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

void	node_add_next(t_node *head, t_node *new)
{
	if (head == NULL || new == NULL)
		return ;
	new->next = head->next;
	new->next->prev = new;
	new->prev = head;
	head->next = new;
}

void	node_add_index(t_node *head, t_node *new, int index)
{
	int	i;

	if (head == NULL || new == NULL)
		return ;
	i = 0;
	while (i < index)
		i++;
	node_add_prev(head, new);
}

void	node_add_child(t_node *head, t_node *new)
{
	if (head == NULL || head->childs == NULL || new == NULL)
		return ;
	node_add_prev(head->childs, new);
	new->parent = head;
}

/* 
	DELETE NODE
*/

void	node_del(t_node *node)
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (node->childs)
	{
		free(node->childs);
		node->childs = NULL;
	}
	free(node);
}

void	nodes_del(t_node *node)
{
	nodes_foreach(node, node_del);
}

/*
** COUNT NODES
*/

int		node_parents_amount(t_node *node)
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
	TEST NODE
*/

t_test_node	*init_new_test_node()
{
	t_test_node *self;

	if (!(self = malloc(sizeof(t_test_node))))
		return (NULL);
	init_list(&self->node);
	self->key = NULL;
	return (self);
}

void	debug_test_node(t_node *node)
{
	t_test_node *test;

	test = (t_test_node*)node;
	printf("%s\n", test->key);
}

void	test_node_creation()
{
	t_test_node *list;
	t_test_node *node;
	t_test_node *sub_node;

	printf("Test nodes\n");
	list = init_new_test_node();
	list->key = strdup("root");
	for (int i = 0; i < 10; i++) {
		if ((node = init_new_test_node())) {
			node->key = ft_itoa(i);
			node_add_child(&list->node, &node->node);
		} else {
			printf("ERROR\n");
		}
		for (int j = 0; j < 10; j++) {
			if ((sub_node = init_new_test_node())) {
				sub_node->key = ft_itoa(i * 10 + j);
				node_add_child(&node->node, &sub_node->node);
			} else {
				printf("ERROR\n");
			}
		}
	}
	nodes_del(list->node.childs->prev);
	// nodes_foreach_ascend(list->node.prev->childs->prev->childs->prev, nodes_del);
	nodes_foreach(&list->node, debug_test_node);
}