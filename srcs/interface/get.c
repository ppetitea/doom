/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:48:47 by ppetitea          #+#    #+#             */
/*   Updated: 2020/06/08 14:49:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/interface.h"
#include "log/log.h"
#include <stdlib.h>

t_interface *static_interface(t_interface *init)
{
	static t_interface *interface = NULL;

	if (!interface)
		interface = init;
	return (interface);
}

t_interface *get_interface()
{
	return (static_interface(NULL));
}

t_keys *get_keys()
{
	t_interface	*interface;

	if ((interface = static_interface(NULL)))
		return (&interface->keys);
	return (console(WARNING, __func__, __LINE__, "interface is null").null);
}

t_mouse *get_mouse()
{
	t_interface	*interface;

	if ((interface = static_interface(NULL)))
		return (&interface->mouse);
	return (console(WARNING, __func__, __LINE__, "interface is null").null);
}

t_scene *get_current_scene()
{
	t_interface	*interface;

	if ((interface = static_interface(NULL)))
		return (&interface->curr);
	return (console(WARNING, __func__, __LINE__, "interface is null").null);
}
