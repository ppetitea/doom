/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usize.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:25:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/23 15:36:07 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USIZE_H
# define USIZE_H

# include <string.h>
#include "maths/vec2i.h"
#include "types.h"

/*
** 2D unsigned size
*/
typedef struct	s_usize
{
	size_t	x;
	size_t	y;
}				t_usize;

/*
** Constructors
*/
t_usize			ft_usize(size_t x, size_t y);

t_bool	is_range_contain(t_pos2i min, t_pos2i pos, t_pos2i max);
t_bool  is_size_contain(t_pos2i pos, t_usize size);


#endif
