/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:19:28 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/08 21:39:18 by ppetitea         ###   ########.fr       */
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
	add_color_map_canvas(&gui->canvas, &gui->render_list,
		&events->mouse.followers);
	add_world3d_canvas(&gui->canvas, &gui->render_list,
		&events->mouse.followers);
	return (OK);
}

#include <stdio.h>

t_result	quit_game()
{
	t_game *game;

	if ((game = game_singleton(NULL)))
		game->is_running = FALSE;
	return (OK);
}

t_result	add_test_scene_events(t_scene *scene)
{
	t_keyboard_observer	*quit;
	t_list_head			*list;

	quit = &scene->events.quit;
	list = &scene->events.keyboard.followers.down;
	set_keyboard_observer(quit, list, SDLK_ESCAPE, TRUE);
	add_new_basic_action(&quit->actions, quit_game);
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
	add_test_scene_events(scene);
	list_add_entry(&scene->node, scenes);
	return (scene);
}
