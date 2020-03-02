/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 17:47:15 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "graphic/animation.h"

/*
** init
*/
typedef struct		s_canvas
{
	t_list_head			node;
	char				*name;
	t_animation			*background;
	t_mouse_observers	mouse_obs;
}					t_canvas;
t_canvas			*init_new_canvas();

/*
**	getter
*/
t_list_head			*get_resource_canvas_list();
t_canvas			*get_canvas(char *name);

#endif
