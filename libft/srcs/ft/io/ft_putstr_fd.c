/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:08:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/16 20:58:52 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft/io.h"
#include "ft/str.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (s) {
		if (write(fd, s, ft_strlen(s)) < 0)
			return ;
	}
}
