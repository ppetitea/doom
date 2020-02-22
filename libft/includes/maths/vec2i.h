/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:16:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/26 17:10:20 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2I_H
# define VEC2I_H

/*
** Two-dimensional int vector
*/
typedef struct	s_vec2i
{
	int	x;
	int	y;
}				t_vec2i;

#define t_pos2i t_vec2i

/*
** Constructors
*/
t_vec2i			ft_vec2i(int x, int y);
#define 		ft_pos2i ft_vec2i

t_vec2i			vec2i_add(t_vec2i a, t_vec2i b);

#endif
