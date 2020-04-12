/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:26:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/12 04:54:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/mem.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		dst_len;
	int		src_len;
	int		len;
	int		i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	len = (src_len < dst_len) ? src_len : dst_len;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
