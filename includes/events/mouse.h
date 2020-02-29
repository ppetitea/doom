/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:11:32 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 17:19:46 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "maths/vec2i.h"
# include "types.h"

/*
**	Lorsque le pointeur est en mode select
**	L'animation qui collisione active les actions de selections

**	Lorsque le pointeur est en mode draw
**	L'animation qui collisione active les actions de draw sur l'animation
**	en question

**	Lorsque le pointeur est en mode CAMERA
**	Le pointeur est invisible et lock au centre de l'ecran
**	De plus les mouvements de la souris controlent la camera
*/
typedef enum	e_pointer_mode
{
	POINTER_SELECT,
	POINTER_DRAW,
	POINTER_CAMERA
}				t_pointer_mode;

typedef struct	s_mouse
{
	t_pointer_mode		mode;
	t_pos2i				pos;
	t_bool				down;
	t_bool				drag;
}				t_mouse;

#endif