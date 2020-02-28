/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 18:22:27 by ppetitea         ###   ########.fr       */
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

/*
** collider
*/
typedef struct	s_animation_collide
{
	t_mouse_observer	hover;
	t_mouse_observer	select;
	t_mouse_observer	drag;
	t_mouse_observer	draw;
}				t_animation_collide;

/*
** init
*/
typedef enum	e_animation_status
{
	INFINITE,
	IN_PROGRESS,
	EPHEMERAL,
	STOP,
	FINAL,
	NONE
}				t_animation_status;

typedef struct	s_animation_box
{
	t_box		*parent_box;
	t_pos2i		anchor;
	t_pos2i		offset;
	t_box		render_box;
}				t_animation_box;
t_result		init_animation_box(t_animation_box *self);
t_result		init_animation_collide(t_animation_collide *self,
					t_animation_box *box);

typedef struct	s_animation
{
	t_list_head				node;
	int						z_index;
	t_animation_status		state;
	struct timeval			last;
	t_animation_box			box;
	t_animation_collide		collide;
	t_texture				*curr;
	t_list_head				textures;
	t_list_head				*list;
	t_result				(*subscribe)(struct s_animation*);
	t_result				(*unsubscribe)(struct s_animation*);
	t_bool					suscribed;
}				t_animation;
t_result		init_animation(t_animation *self);

/*
** render
*/
typedef struct		s_animation_renderer
{
	t_list_head		render_list;
	t_result		(*render)(t_list_head*);
}					t_animation_renderer;
t_result			init_animation_renderer(t_animation_renderer *self);

/*
** oriented
*/
typedef struct	s_oriented_animations
{
	t_animation			f;
	t_animation			fr;
	t_animation			fl;
	t_animation			r;
	t_animation			l;
	t_animation			b;
	t_animation			br;
	t_animation			bl;
}				t_oriented_animations;
t_result		init_oriented_animations(t_oriented_animations *self);

/*
** build
*/
t_result		build_animation(t_animation *self, t_obj *anim_obj);

/*
** copy
*/
t_result		copy_animation(t_animation *dest, t_animation *src);

/*
** overwrite
*/
t_result		overwrite_animation(t_animation *self, t_obj *anim_obj,
					t_mouse_observable *mouse);

/*
** subscription
*/
t_result		animation_subscribe(t_animation *self);
t_result		animation_unsubscribe(t_animation *self);

/*
** add
*/
t_result		add_animation_collide_lists(t_animation *anim,
					t_mouse_followers *followers);


#endif
