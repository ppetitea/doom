/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 02:33:41 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include <sys/time.h>
# include "events/observer.h"
# include "graphic/texture.h"
# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"

typedef enum	e_animation_status
{
	INFINITE,
	IN_PROGRESS,
	EPHEMERAL,
	STOP,
	FINAL,
	NONE
}				t_animation_status;

typedef struct			s_animation
{
	t_list_head			node;
	t_animation_status	state;
	struct timeval		last;
	t_texture			*curr;
	t_list_head			textures;
	t_vec2i				anchor;
	t_list_head			*render_list;
	t_bool				is_render;
	t_mouse_collide		collide;
}						t_animation;
t_result				init_animation(t_animation *self);

typedef struct			s_oriented_animations
{
	t_animation			f;
	t_animation			fr;
	t_animation			fl;
	t_animation			r;
	t_animation			l;
	t_animation			b;
	t_animation			br;
	t_animation			bl;
}						t_oriented_animations;
t_result				init_oriented_animations(t_oriented_animations *self);

#endif
