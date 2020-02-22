/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:45:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/28 18:18:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include "types.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_u8	*dst;
	t_u8	src;

	dst = (t_u8*)b;
	src = (t_u8)c;
	while (len--)
		*(dst++) = src;
	return (b);
}
