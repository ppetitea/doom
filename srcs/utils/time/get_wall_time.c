/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:48:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/03/08 21:31:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/time.h>
#include "utils/time.h"

double	get_wall_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0.0);
	return ((double)time.tv_sec + (double)time.tv_usec * 0.000001);
}
