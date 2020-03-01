/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:19:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/01 12:10:30 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "graphic/texture.h"
#include "events/action.h"
#include "utils/error.h"
#include "build.h"
#include "ft/str.h"

t_result	add_test_scene_gui(t_scene_gui *gui, t_scene_events *events)
{
	if (gui == NULL || events == NULL)
		return (throw_error("add_scene_gui", "NULL pointer provided"));
	add_play_button(&gui->buttons, &gui->render_list, &events->mouse.followers);
	return (OK);
}

t_scene		*add_test_scene(t_list_head *scenes)
{
	t_scene	*scene;

	if (!(scene = init_new_scene()))
		return (throw_null("create_new_scene", "init_new_scene failed"));
	if (!(scene->name = ft_strdup("test_scene")))
		return (throw_null("create_new_scene", "ft_strdup failed"));
	add_test_scene_gui(&scene->gui, &scene->events);
	// scene->map_config.color.display = TRUE;
	list_add_entry(&scene->node, scenes);
	return (scene);
}
