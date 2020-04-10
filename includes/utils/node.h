#ifndef NODE_H
# define NODE_H

#include "types.h"

typedef struct  s_node
{
    struct s_node	*parent;
    struct s_node	*prev;
    struct s_node	*next;
    struct s_node	*childs;
}               t_node;

/*
	INIT NODE
*/
t_result init_node(t_node *self);

t_result init_list(t_node *self);

t_node	*init_new_node();

t_node 	*init_new_list();

/* 
	ITER NODE
*/

void	nodes_foreach(t_node *node, void (*fn)(t_node *node));

void	nodes_foreach_ascend(t_node *node, void (*fn)(t_node *node));

/* 
	ADD NODE
*/
void	node_add_prev(t_node *head, t_node *new);

void	node_add_next(t_node *head, t_node *new);

void	node_add_index(t_node *head, t_node *new, int index);

void	node_add_child(t_node *head, t_node *new);

/* 
	DELETE NODE
*/

void	node_del(t_node *node);

void	nodes_del(t_node *node);

/* 
	TEST NODE
*/

typedef struct s_test_node
{
	t_node	node;
	char	*key;
}			t_test_node;

t_test_node	*init_new_test_node();
void	debug_test_node(t_node *node);
void	test_node_creation();

#endif