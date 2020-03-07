/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:39:01 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/05 10:56:37 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"
#include "utils/error.h"

t_result	transform_anim_on_mouse(t_animation	*anim)
{
	t_mouse	*mouse;
	t_vec2i	anchor;

	if (!(mouse = get_mouse_state()))
		return (throw_error("set_mouse_as_anchor", "Mouse not found"));
	anchor = ft_vec2i(0, 0);
	if (anim->box.parent_box)
		anchor = anim->box.parent_box->offset;
	anim->box.anchor = vec2i_sub(mouse->pos, anchor);
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}

t_result	set_mouse_as_anchor(t_animation *anim)
{
	t_mouse	*mouse;
	t_vec2i	anchor;

	if (!(mouse = get_mouse_state()))
		return (throw_error("set_mouse_as_anchor", "Mouse not found"));
	anchor = ft_vec2i(0, 0);
	if (anim->box.parent_box)
		anchor = anim->box.parent_box->offset;
	anim->box.offset = vec2i_sub(anim->box.render_box.offset, mouse->pos);
	anim->box.anchor = vec2i_sub(mouse->pos, anchor);
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}

t_result	elevate_animation_anchor(t_animation *anim)
{
	anim->box.anchor.y++;
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}

t_result	lower_animation_anchor(t_animation *anim)
{
	anim->box.anchor.y--;
	anim->box.render_box.offset = vec2i_add(anim->box.anchor, anim->box.offset);
	return (OK);
}


 #include <stdio.h>
// int			compute_pgcd(int a, int b)
// {
// 	int big;
// 	int small;
// 	int rest;

// 	big = (a > b) ? a : b;
// 	small = (big == a) ? b : a;
// 	while ((rest = big % small) != 0)
// 	{
// 		big = small;
// 		small = rest;
// 	}
// 	return (big);
// }

int			compute_ppcd(int a, int b)
{
	int big;
	int small;
	int ppcd;

	big = (a > b) ? a : b;
	small = (big == a) ? b : a;
	ppcd = 2;
	while (ppcd < small && small % ppcd != 0 && big % ppcd != 0)
		ppcd++;
	return ((ppcd == small) ? 1 : ppcd);
}

t_result	increase_scale_animation(t_animation *anim)
{
	anim->box.render_box.size.x *= 2;
	anim->box.render_box.size.y *= 2;
	return (OK);
}

t_result	decrease_scale_animation(t_animation *anim)
{
	t_vec2i	size;
	int		ppcd;

	size = anim->box.render_box.size;
	ppcd = compute_ppcd(size.x, size.y);
	if (size.x > ppcd && size.y > ppcd)
	{
		anim->box.render_box.size.x /= 2;
		anim->box.render_box.size.y /= 2;
		if (size.x % 2)
			anim->box.render_box.size.x += 1;
		if (size.y % 2)
			anim->box.render_box.size.y += 1;
	}
	return (OK);
}
