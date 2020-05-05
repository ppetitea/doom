/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 11:00:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/29 23:37:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_result	node_foreach_prev(t_node *self, t_result (*fn)(t_node*));

t_result	node_foreach_next(t_node *self, t_result (*fn)(t_node*));

void	nodes_foreach_ascend(t_node *node, void (*fn)(t_node *node));

/*
** FIND NODE
*/

t_node	*node_find(t_node *self, t_bool (*fn)(t_node *));

/*
** NODE GET
*/

t_node	*node_get_child(t_node *node, int index);

t_node	*node_get_root(t_node *node);

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

t_result	node_del(t_node *node);

void	nodes_del(t_node *node);

/*
** COUNT NODE
*/

int		node_childs_amount(t_node *node);

int		node_parents_amount(t_node *node);

/*
** SORT NODES
*/

void	swap_nodes(t_node *a, t_node *b);

void	bubble_sort_node_childs(t_node *parent,
			t_bool(*rule)(t_node*, t_node*));
			
/* 
	TEST NODE
*/

typedef struct s_test_node
{
	t_node	node;
	char	*key;
}			t_test_node;

t_test_node	*init_new_test_node();
t_result	debug_test_node(t_node *node);
void	test_node_creation();

#endif