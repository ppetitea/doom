/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DATA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:35:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/09 14:57:23 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "node.h"
# include "log.h"

typedef enum    e_data_type
{
	UNDEFINED = -1,
	CHAR,
	INT,
	FLOAT,
	STRING,
	LIST
}               t_data_type;

typedef union   u_val
{
	char        c;
	int         i;
	float		f;
	char        *s;
}               t_val;

typedef struct  s_data
{
	t_node      	node;
	char        	*key;
	t_data_type		type;
	t_val 			value;
}               t_data;

/*
** DATA FOREACH
*/

t_result	data_foreach_prev(t_data *self, t_result (*fn)(t_data*));

t_result	data_foreach_next(t_data *self, t_result (*fn)(t_data*));

/*
** PRINT DATA
*/

t_result	print_data(t_data *self);

t_result	print_datas(t_data *self);

/*
** INIT DATA
*/
t_result	init_data(t_data *self);

t_data		*init_new_data();

/*
** DELETE DATA
*/

t_result	data_del(t_data *self);

t_result	datas_del(t_data *self);

t_result	datas_childs_del(t_data *self);

t_res		datas_del_and_quit(t_data *self);

/*
** SETUP DATA
*/

t_result data_set(t_data *self, char *key, t_data_type type, t_val val);

t_data	*new_data_set(char *key, t_data_type type, t_val val);

/* 
	TEST DATA
*/

t_result	test_data_creation();


#endif