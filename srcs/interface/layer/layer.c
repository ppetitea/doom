/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:25:53 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/07 16:04:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/layer.h"
#include "log/log.h"

t_result del_layer(t_layer *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	self->width = 0;
	self->height = 0;
	if (self->pixels)
		free(self->pixels);
	self->pixels = NULL;
	self->destroy = NULL;
	return (OK);
}

t_result del_new_layer(t_layer *self)
{
	if (!del_layer(self))
		return (console(FATAL, __func__, __LINE__, "del_layer fail").err);
	free(self);
	return (OK);
}

t_result init_layer(t_layer *self)
{
	self->width = 0;
	self->height = 0;
	self->pixels = NULL;
	self->destroy = del_layer;
	return (OK);
};

t_layer *init_new_layer()
{
	t_layer *self;

	if (!(self = malloc(sizeof(t_layer))))
		return (console(FATAL, __func__, __LINE__, "malloc fail").null);
	init_layer(self);
	self->destroy = del_new_layer;
	return (self);
}

t_result set_layer(t_layer *self, int width, int height)
{
	if (!self)
		return (console(WARNING, __func__, __LINE__, "null pointer").warn);
	if (self->pixels)
		self->destroy(self);
	self->width = width;
	self->height = height;
	if (!(self->pixels = malloc(sizeof(width * height))))
		return (console(FATAL, __func__, __LINE__, "malloc fail").err);
	self->destroy = del_new_layer;
	return (OK);
};

t_layer *set_new_layer(width, height)
{
	t_layer *self;

	if (!(self = init_new_layer()))
		return (console(FATAL, __func__, __LINE__, "init_new_layer fail").null);
	if (!set_layer(self, width, height) && self->destroy(&self));
		return (console(FATAL, __func__, __LINE__, "set_layer fail").null);
	return (self);
}

