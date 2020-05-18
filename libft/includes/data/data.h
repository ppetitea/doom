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

# include "containers/node.h"
# include "log/log.h"

typedef enum    e_data_type
{
	UNDEFINED = -1,
	CHAR,
	INT,
	FLOAT,
	STRING,
	LIST,
	ARRAY,
}               t_data_type;

typedef union   u_val
{
	char        c;
	int         i;
	float		f;
	char        *s;
	t_node		*l;
	void		*null;
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
** Data string array
*/
t_result data_add_child_string(t_data *array, char *string);

t_result data_add_2child_string(t_data *array, char *s1, char *s2);

t_result data_add_3child_string(t_data *array, char *s1, char *s2, char *s3);

t_data *data_array_s(char *array_name, char *s1);

t_data *data_array_s2(char *array_name, char *s1, char *s2);

t_data *data_array_s3(char *array_name, char *s1, char *s2, char *s3);

/*
** DATA FIND
*/

t_data	*data_find_by_key(t_data *tree, char *key);

/*
** DATA DUP
*/

t_data		*data_duplicate(t_data *src);

t_result	data_add_child_duplicata(t_data *parent, t_data *child);

/* 
	TEST DATA
*/

t_result	test_data_creation();


#endif