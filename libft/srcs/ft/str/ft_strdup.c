/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:20:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/20 04:36:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	if (!(dst = (char*)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	dst[s1_len] = '\0';
	i = 0;
	while (i < s1_len)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}
