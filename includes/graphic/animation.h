/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:39:15 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 19:39:04 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "interface/screen.h"
# include "events/mouse.h"
# include "events/keyboard.h"
# include "graphic/texture.h"
# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"
# include "utils/time.h"

/*
** init
*/
typedef enum	e_animation_status
{
	ANIM_INFINITE,
	ANIM_IN_PROGRESS,
	ANIM_EPHEMERAL,
	ANIM_STOP,
	ANIM_FINAL,
}				t_animation_status;

typedef struct	s_animation_box
{
	t_box		*parent_box;
	t_pos2i		anchor;
	t_pos2i		offset;
	t_box		render_box;
}				t_animation_box;
t_result		init_animation_box(t_animation_box *self);
t_result		init_mouse_observers(t_mouse_observers *self,
					t_animation_box *box);

typedef struct	s_animation
{
	t_list_head				node;
	int						z_index;
	t_animation_status		state;
	t_time					last;
	t_animation_box			box;
	t_mouse_observers		mouse_obs;
	t_texture				*curr;
	t_list_head				*textures;
	t_result				(*update)(struct s_animation*);
	t_result				(*render)(t_screen*, struct s_animation*, t_time);
	t_list_head				*list;
	t_result				(*subscribe)(struct s_animation*);
	t_result				(*unsubscribe)(struct s_animation*);
	t_bool					subscribed;
}				t_animation;
t_result		init_animation(t_animation *self);
t_result		init_new_animation(t_animation *self);

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
** update
*/
t_result		update_animation_render_box(t_animation *anim);

/*
** mouse observer
*/
t_result		animation_hover_start(t_animation *anim);
t_result		animation_hover_end(t_animation *anim);
t_result		animation_drag_start(t_animation *anim);
t_result		animation_drag_end(t_animation *anim);
t_result		animation_wheel_start(t_animation *anim);
t_result		animation_wheel_end(t_animation *anim);

/*
** transform
*/
t_result		elevate_animation_anchor(t_animation *anim);
t_result		lower_animation_anchor(t_animation *anim);
t_result		set_mouse_as_anchor(t_animation *anim);
t_result		transform_anim_on_mouse(t_animation	*anim);
t_result		increase_scale_animation(t_animation *anim);
t_result		decrease_scale_animation(t_animation *anim);

/*
** animate
*/
t_result		reset_animation(t_animation *anim);
t_result		texture_next(t_animation *anim);

/*
** render
*/
t_result		render_animation(t_screen *screen, t_animation *anim,
					struct timeval time);

#endif
