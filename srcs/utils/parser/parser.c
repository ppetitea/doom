/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:57:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 16:19:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils/error.h"
#include "utils/parser.h"
#include <stdio.h>

t_obj	*parse_dnon_file(char *path)
{
	char			*data;
	t_obj	*obj;
	
	if (!(data = get_file_datas(path)))
		return (throw_null("parse_map_file", "failed to get datas"));
	if (!check_curly_braces(data))
		return (throw_null("parse_map_file", "error around curly braces"));
	obj = create_obj(ft_strdup("root"), LIST);
	to_object(data, obj);
	// obj = get_child_object_by_key(obj, "player");
	// if (obj)
	// {
	// debug_object(obj);
	// 	// printf("%s\n", get_string_child(obj, "1", "default"));
	// 	printf("%d\n", get_int_child(obj, "direction", 42));
	// }
	// else
	// 	printf("doesn't find child with this key\n");
	// free_object(obj);
	return (obj);
}