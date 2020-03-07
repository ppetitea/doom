/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 13:18:59 by ppetitea         ###   ########.fr       */
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
	t_animation			anim;
}					t_canvas;
t_canvas			*init_new_canvas();

/*
** render
*/
t_result			render_canvas(t_screen *screen, t_animation *anim,
						t_time time);

/*
** update
*/
t_result			set_animation_as_current_color_map(t_animation *anim);
t_result			set_animation_as_current_height_map(t_animation *anim);
t_result			render_map3d_on_canvas(t_animation *anim);

/*
** getter
*/
t_list_head			*get_resource_canvas_list();
t_canvas			*get_canvas(char *name);

#endif
