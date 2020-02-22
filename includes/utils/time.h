/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 01:47:49 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/08 19:14:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

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