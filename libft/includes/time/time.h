/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:47:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/17 13:16:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>

typedef struct timeval t_time;

/*
** Delta
*/
float	*get_delta_ptr(void);
void	set_delta(const float delta);
float	get_delta(void);
float	delta(const float value);

/*
** Time
*/
double	get_wall_time(void);

#endif