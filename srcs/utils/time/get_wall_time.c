/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:48:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/02/08 19:15:42 by lbenard          ###   ########.fr       */
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
