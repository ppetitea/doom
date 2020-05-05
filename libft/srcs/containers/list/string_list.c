/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:18:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/28 23:34:22 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"
#include "ft/str.h"
#include "log/log.h"
#include <stdlib.h>

t_result init_string_node(t_string_node *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->type = STRING_LIST;
	self->s = NULL;
	return (OK);
};

t_string_node *init_new_string_node()
{
	t_string_node *self;

	if (!(self = malloc(sizeof(t_string_node))))
		return (console(FATAL, __func__, __LINE__, "malloc fail").null);
	init_string_node(self);
	return (self);
}

t_result del_string_node(t_string_node *self)
{
	if (!self)
		return (console(WARN, __func__, __LINE__, "null pointer").warn);
	list_del_entry(&self->node);
	if (self->s)
		free(self->s);
	free(self);
	return (OK);
}

t_string_node *set_new_string_node(char *string)
{
	t_string_node *self;

	if (!(self = init_new_string_node()))
		return (console(FATAL, __func__, __LINE__, "new_string fail").null);
	if (!(self->s = ft_strdup(string)) && del_string_node(self))
		return (console(FATAL, __func__, __LINE__, "strdup fail").null);
	return (self);
}
