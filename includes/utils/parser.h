/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:00:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 16:20:05 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"
# include "sizes/usize.h"

typedef	enum	e_dnon_value_type
{
	LIST,
	STRING,
	NUMBER, 
	UNKNOW
}				t_dnon_value_type;

typedef struct	s_obj
{
	t_list_head					node;
	char						*key;
	t_dnon_value_type			type;
	void						*value;
}				t_obj;

/*
**	parsing
*/
t_obj			*parse_dnon_file(char *path);
t_result		to_object(char *data, t_obj *parent);

/*
**	read file
*/
char			*get_file_datas(char *path);

/*
**	check data
*/
t_result		check_data_format(char *data);
t_result		check_curly_braces(char *data);
t_result		check_open_curly_brace_left_side(char *data, size_t index);
t_result		check_open_curly_brace_right_side(char *data, size_t index);
t_result		check_close_curly_brace_left_side(char *data, size_t index);
t_result		check_close_curly_brace_right_side(char *data, size_t index);
t_bool			is_index_match_to_object_key(char *data, size_t index);

/*
**	split data
*/
char			**split_by_entry(char *data);
char			**new_string_array(size_t size);
void			free_string_array(char **datas);

/*
**	get data
*/
char			*get_key_offset(char *data);
char			*get_object_key(char *data);
char			*get_value_offset(char *data);
void			*get_object_value(char *data, t_dnon_value_type type);
int				get_object_value_type(char *data);
t_result		init_usize_with_obj(t_usize *self, t_obj *size_obj);
t_result		init_vec2i_with_obj(t_vec2i *self, t_obj *vec2i_obj);
t_result		init_vec2f_with_obj(t_vec2f *self, t_obj *vec2f_obj);
t_bool			strcmp_obj(char *key, char *value, t_obj *obj);
t_vec2i			get_vec2i(t_obj *vec2i_obj, int default_x,
					int default_y);
t_vec2f			get_vec2f(t_obj *vec2f_obj, float default_x,
					float default_y);

/*
**	object creation
*/
t_obj	*new_obj();
t_obj	*create_obj(char *key, t_dnon_value_type type);
t_obj	*create_obj_with_data(char *data);

/*
**	object free
*/
t_iterator_callback		free_object(t_obj *obj);

/*
**	getters
*/
int				get_int_child(t_obj *tree,
					char *key,
					int by_default);
float			get_float_child(t_obj *tree,
					char *key,
					float by_default);
char			*get_string_child(t_obj *tree,
					char *key,
					char *by_default);
t_obj	*get_child_list(t_obj *tree, char *key);
t_obj	*get_child_object_by_key(t_obj *tree, char *key);

/*
** setters
*/
t_result		set_int_value_by_key(t_obj *obj, char *key, int set);

/*
**	debug
*/
t_iterator_callback		debug_object(t_obj *obj);
void					debug_split(char **datas);

#endif