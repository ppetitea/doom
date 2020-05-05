/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:44:37 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/25 22:56:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image/image.h"
#include "ft/str.h"
#include "log/log.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

t_result init_image(t_image *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self->width = 0;
	self->height = 0;
	self->name = NULL;
	self->pixels = NULL;
	return (OK);
};

t_image *init_new_image()
{
	t_image *self;

	if (!(self = malloc(sizeof(t_image))))
		return (NULL);
	if (!init_image(self))
	{
		free(self);
		return (console(FATAL, __func__, __LINE__, "init_image fail").null);
	}
	return (self);
}

t_result	del_image(t_image *self)
{
	if (self)
	{
		if (self->name)
			free(self->name);
		if (self->pixels)
			free(self->pixels);
		free(self);
	}
	return (OK);
}

t_image	*image_parse(char *path, char *name)
{
	int		fd;
	t_u16	magic;
	t_image *bmp;

	if ((fd = open(path, O_RDONLY, 0)) < 0)
		return (console(FATAL, __func__, __LINE__, "open fail").null);
	if (!(bmp = init_new_image()))
		return (console(FATAL, __func__, __LINE__, "new_image fail").null);
	if (read(fd, &magic, sizeof(t_u16)) < 0 && del_image(bmp))
		return (console(FATAL, __func__, __LINE__, "read fail").null);
	if (magic != 0x4d42 && del_image(bmp))
		return (console(FATAL, __func__, __LINE__, "unknow file format").null);
	if (!bmp_parse(fd, bmp) && del_image(bmp))
		return (console(FATAL, __func__, __LINE__, "bmp_parse fail").null);
	if (!(bmp->name = ft_strdup(name)) && del_image(bmp))
		return (console(FATAL, __func__, __LINE__, "strdup fail").null);
	return (bmp);
}

t_image *image_find(t_list_head *list, char *name)
{
	t_list_head	*curr;
	t_list_head	*next;

	if (list == NULL)
		return (ERROR);
	curr = list;
	next = curr->next;
	while ((curr = next) != list)
	{
		next = next->next;
		if (!ft_strcmp(((t_image*)curr)->name, name))
			return ((t_image*)curr);
	}
	return (NULL);
}