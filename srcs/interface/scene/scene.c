/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:46:51 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/08 14:48:13 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/interface.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_scene(t_scene *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->tree.destroy(&self->tree);
	self->destroy = NULL;
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_scene(t_scene *self)
{
	if (!del_scene(self))
		return (console(FATAL, __func__, __LINE__, "del_scene fail").err);
	free(self);
	return (OK);
}

t_result del_scene_list(t_list_head *list)
{
	t_list_head	*curr;
	t_list_head	*next;
	t_scene		*scene;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next-> next;
		scene = (t_scene*)curr;
		scene->destroy(scene);
	}
	return (OK);
}

t_result init_scene(t_scene *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	if (!init_component(&self->tree))
		return (console(FATAL, __func__, __LINE__, "init_component fail").err);
	self->destroy = del_scene;
	return (OK);
};

t_scene *init_new_scene()
{
	t_scene *self;

	if (!(self = malloc(sizeof(t_scene))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_scene(self);
	self->destroy = del_new_scene;
	return (self);
}

// t_result set_scene(t_scene *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_scene *set_new_scene()
// {
// 	t_scene *self;

// 	if (!(self = init_new_scene()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_scene fail").null);
// 	if (!(set_scene(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_scene fail").null);
// 	return (self);
// }
