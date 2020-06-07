/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:43:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/05 18:54:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/inputs/keyboard.h"
#include "log/log.h"
#include <stdlib.h>


t_result del_key(t_key *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->code = -1;
	self->destroy = NULL;
	list_del_entry(&self->node);
	return (OK);
};

t_result del_new_key(t_key *self)
{
	if (!del_key(self))
		return (console(FATAL, __func__, __LINE__, "del_key fail").err);
	free(self);
	return (OK);
}

t_result del_key_list(t_list_head *key_list)
{
	t_key		*key;
	t_list_head	*curr;
	t_list_head	*next;

	curr = key_list;
	next = curr->next;
	while ((curr = next) != key_list)
	{
		next = next->next;
		key = (t_key*)curr;
		key->destroy(key);
	}
	return (OK);
}

t_result del_key_list_by_code(t_list_head *list, SDL_Keycode code)
{
	t_key		*key;
	t_list_head	*curr;
	t_list_head	*next;

	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next->next;
		key = (t_key*)curr;
		if (key->code == code)
		{
			key->destroy(key);
			return (OK);
		}
	}
	return (OK);
};

t_result add_new_key(t_list_head *list, SDL_Keycode code)
{
	t_key	*self;

	if (!list)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (!(self = set_new_key(code)))
		return (console(FATAL, __func__, __LINE__, "set_new_key fail").err);
	list_add_entry(list, &self->node);
	return (OK);
};

t_result init_key(t_key *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->code = -1;
	return (OK);
};

t_key *init_new_key()
{
	t_key *self;

	if (!(self = malloc(sizeof(t_key))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_key(self);
	self->destroy = del_new_key;
	return (self);
}

t_result	set_key(t_key *self, SDL_Keycode code)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").null);
	self->code = code;
	return (self);
}

t_key *set_new_key(SDL_Keycode code)
{
	t_key *self;

	if (!(self = malloc(sizeof(t_key))))
		return (console(FATAL, __func__, __LINE__, "set_list fail").null);
	set_key(self, code);
	return (self);
}

t_result del_keys(t_keys *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	del_key_list(&self->curr);
	del_key_list(&self->last);
	self->events.destroy(&self->events);
	return (OK);
}

t_result del_new_keys(t_keys *self)
{
	if (!del_keys(self))
		return (console(FATAL, __func__, __LINE__, "del_keys fail").err);
	free(self);
	return (OK);
}

t_result init_keys(t_keys *self)
{
	if (!init_list_head(&self->curr))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->last))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_observable(&self->events))
		return (console(FATAL, __func__, __LINE__, "init_observable fail").err);
	self->destroy = del_keys;
	return (OK);
};

t_keys *init_new_keys()
{
	t_keys *self;

	if (!(self = malloc(sizeof(t_keys))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_keys(self);
	self->destroy = del_new_keys;
	return (self);
}
