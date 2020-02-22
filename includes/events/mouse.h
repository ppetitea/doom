/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:11:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 18:45:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "maths/vec2i.h"
# include "types.h"

typedef struct			s_mouse
{
	t_vec2i				pos;
	t_bool				down;
	t_bool				drag;
}						t_mouse;

#endif