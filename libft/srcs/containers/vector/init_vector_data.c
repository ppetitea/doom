/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:05:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/11 16:14:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/vector.h"
#include "ft/mem.h"

t_result	init_vector_data(t_vector *vector, const void *data, size_t size)
{
	if (!data)
		return (ERR);
	if (!(vector->data = malloc(size)))
	{
		vector->capacity = 0;
		vector->size = 0;
		return (ERR);
	}
	vector->capacity = size;
	vector->size = size;
	ft_memcpy(vector->data, data, size);
	return (OK);
}
