/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:48:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/04/17 13:16:25 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/time.h>
#include "time/time.h"

double	get_wall_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0.0);
	return ((double)time.tv_sec + (double)time.tv_usec * 0.000001);
}
