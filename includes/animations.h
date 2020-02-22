/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 14:12:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATIONS_H
# define ANIMATIONS_H

# include <sys/time.h>
# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"

typedef struct			s_texture
{
	t_list_head	node;
	t_vec2i		offset;
	t_vec2i		size;
	t_u32		*pixels;
	t_u32		delay_ms;
}						t_texture;
t_result				init_texture(t_texture *self);
t_texture				*init_new_texture();

typedef struct			s_observer
{
	t_list_head			node;
	t_vec2i				*offset;
	t_vec2i				*size;
	t_list_head			*suscribe_list;
	t_bool				activable;
	t_bool				active;
}						t_observer;
t_result				init_observer(t_observer *self);

typedef struct			s_collide
{
	t_vec2i				offset;
	t_vec2i				size;
	t_observer			hover;
	t_observer			select;
	t_observer			drag;
}						t_collide;
t_result				init_collide(t_collide *self);

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
	t_animation_status	state;
	struct timeval		last;
	t_texture			*curr;
	t_list_head			textures;
	t_vec2i				anchor;
	t_collide			collide;
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
