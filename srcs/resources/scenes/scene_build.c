/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:12:54 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 11:54:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "utils/error.h"

#include "resources/button.h"

t_result	build_scene_buttons(t_list_head *buttons, t_scene_events *events,
				t_obj *buttons_obj)
{
	t_list_head	*pos;
	t_obj		*button_obj;
	t_button	*button;
	
	if (buttons == NULL || events == NULL || buttons_obj == NULL)
		return (throw_error("build_scene_buttons", "NULL pointer provided"));
	pos = (t_list_head*)&buttons_obj->value;
	while ((pos = pos->next) != (t_list_head*)&buttons_obj->value)
	{
		button_obj = (t_obj*)pos;
		if ((button = duplicate_button(button_obj->key)))
		{
			overwrite_button(button, button_obj, events);
			list_add_entry(&button->node, buttons);
		}
	}
	return (OK);
}

t_result	build_scene_gui(t_scene_gui *gui, t_scene_events *events,
				t_obj *scene_obj)
{
	t_obj	*buttons_obj;

	if (gui == NULL || events == NULL || scene_obj == NULL)
		return (throw_error("build_scene_gui", "NULL pointer provided"));
	if (!build_animation(&gui->background,
		get_child_list(scene_obj, "background")))
		return (throw_error("build_scene_gui", "build_background failed"));
	buttons_obj = get_child_list(scene_obj, "buttons");
	
	/*
	1 -> build les senes depuis un fichier descriptif
			-> Je ne peux pas utiliser de pointeur de fonctions generique
			->	bah si, simplement je dois faire davantage que juste assosicer
				la bonne fonction il faut test aussi le sarguments
	2 -> build les senes en dur dans le code
			-> Je peux utiliser des pointeurs de fonctions generiques
	*/


	/*
	1 -> build les buttons directement dans la scene
	2 -> build les buttons puis les overwrite dans la scene
		si je reutilise le meme button dans 2 scenes:
			-> double de memoire en RAM
			-> double de fonctions a initialiser
			-> Je peux enregistrer n'importe quel button
				en tant que resource pour une action
	*/

	return (OK);
}

t_result	build_new_scene(t_list_head *scenes, t_obj *scene_obj)
{
	t_scene	*scene;
	
	if (scenes == NULL || scene_obj == NULL)
		return (throw_error("build_new_scene", "NULL pointer provided"));
	if (!(scene = init_new_scene()))
		return (throw_error("build_new_scene", "init_new_scene failed"));
	if (!(scene->name = get_string_child(scene_obj, "name", NULL)))
		return (throw_error("build_new_scene", "get_string_child failed"));


	return (OK);
}