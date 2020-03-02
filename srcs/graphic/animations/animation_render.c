/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:17:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 17:46:54 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"

static t_texture	*handle_animation_end(t_animation *anim)
{
	t_texture	*ret;

	ret = (t_texture*)anim->textures.next;
	if (anim->state == ANIM_INFINITE)
		return ((t_texture*)anim->textures.next);
	if (anim->state == ANIM_IN_PROGRESS)
		ret = ((t_texture*)anim->textures.next);
	else if (anim->state == ANIM_FINAL)
		ret = ((t_texture*)anim->curr);
	else
		throw_void("handle_animation_end", "wrong animation type detected");
	anim->state = ANIM_STOP;
	return (ret);
}

t_result	animate(t_animation *anim, struct timeval time)
{
	t_u32		delta_ms;

	delta_ms = (time.tv_sec - anim->last.tv_sec) * 1000;
	delta_ms += (time.tv_usec - anim->last.tv_usec) / 1.0e3;
	// printf("delta_ms %d\n", delta_ms);
	if (delta_ms > anim->curr->delay_ms)
	{
		anim->last = time;
		if (anim->curr->node.next == &anim->textures)
			anim->curr = handle_animation_end(anim);
		else
			anim->curr = (t_texture*)anim->curr->node.next;
	}
	return (OK);
}

t_result	render_animation(t_screen *screen, t_animation *anim,
				struct timeval time)
{
	t_render_box	box;

	if (anim->state != ANIM_STOP)
		animate(anim, time);
	box.offset = anim->box.render_box.offset;
	box.size = anim->box.render_box.size;
	box.start.x = (box.offset.x < 0) ? -box.offset.x : 0;
	box.start.y = (box.offset.y < 0) ? -box.offset.y : 0;
	box.end = vec2i_add(box.offset, box.size);
	if (box.end.x >= (int)screen->size.x)
		box.end.x = (int)screen->size.x;
	if (box.end.y >= (int)screen->size.y)
		box.end.y = (int)screen->size.y;
	box.scale.x = (float)anim->curr->size.x / (float)box.size.x;
	box.scale.y = (float)anim->curr->size.y / (float)box.size.y;
	render_texture(screen, anim->curr, box);
	return (OK);
}
