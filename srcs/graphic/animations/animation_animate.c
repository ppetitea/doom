/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_animate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:40:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 16:44:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic/animation.h"

t_result	reset_animation(t_animation *anim)
{
	if (anim->textures.next != &anim->textures)
		anim->curr = (t_texture*)anim->textures.next;
	return (OK);
}

t_result	texture_next(t_animation *anim)
{
	if (anim->curr->node.next != &anim->textures)
		anim->curr = (t_texture*)anim->curr->node.next;
	else
		reset_animation(anim);
	return (OK);
}
