/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:53:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 18:41:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"
#include "utils/parser.h"

t_result	copy_animation(t_animation *dest, t_animation *src)
{
	if (dest == NULL || src == NULL)
		return (throw_error("copy_animation", "NULL pointer provided"));
	dest->state = src->state;
	dest->suscribe = src->suscribe;
	dest->unsuscribe = src->unsuscribe;
	copy_texture_list(&dest->list, &src->list);
	return (OK);
}
