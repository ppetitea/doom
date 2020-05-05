/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:07:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/16 20:58:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft/io.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) < 0)
		return ;
}
