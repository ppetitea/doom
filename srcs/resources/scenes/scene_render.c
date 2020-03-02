/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:23:17 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/02 17:21:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "interface/screen.h"
#include "utils/error.h"
#include "utils/time.h"

t_result	render_scene(t_scene *scene)
{
	t_list_head		*pos;
	t_animation		*anim;
	t_screen		*screen;
	t_time			time;

	if (scene == NULL)
		return (throw_error("render_scene", "NULL pointer provided"));
	if (!(screen = get_screen()))
		return (throw_error("render_scene", "Screen not found"));
	pos = &scene->gui.render_list;
	gettimeofday(&time, NULL);
	while ((pos = pos->next) != &scene->gui.render_list)
	{
		anim = (t_animation*)pos;
		if (anim->curr)
			anim->render(screen, anim, time);
	}
	return (OK);
}