/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_test_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:59:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/28 13:14:38 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/scene.h"
#include "resources/button.h"
#include "graphic/texture.h"
#include "events/action.h"
#include "utils/error.h"

/*
**	Create scene by describe each component and fill each structs
*/

#include <stdio.h>
t_result	debug_test(char *message)
{
	if (message == NULL)
		return (throw_error("debug_test", "message is NULL"));
	printf("%s\n", message);
	return (OK);
}

t_result	add_background_button(t_list_head *buttons, t_list_head *render_list,
				t_mouse_followers *followers)
{
	t_button	*button;
	t_animation	*anim;

	if (!(button = init_new_button()))
		return (throw_error("add_background_button", "init_new_button failed"));
	if (!(button->name = ft_strdup("test_background")))
		return (throw_error("add_background_button", "ft_strdup failed"));
	anim->curr = add_new_texture(&anim->list, "background_blood",
		ft_vec2i(1080, 720), FILTER_NONE);
	anim->list = render_list;
	anim->subscribe(anim);
	add_animation_collide_lists(anim, followers);
	add_new_action(&anim->collide.select.start_actions, debug_test,
		(t_arg)button->name, TYPE_POINTER);
	list_add_entry(&button->node, buttons);
	return (OK);
}

t_result	create_test_scene()
{
	t_scene	*scene;

	if (!(scene = init_new_scene()))
		return (throw_error("create_new_scene", "init_new_scene failed"));
	if (!(scene->name = ft_strdup("test_scene")))
		return (throw_error("create_new_scene", "ft_strdup failed"));
	scene->map_config.color.display = TRUE;
	
	return (OK);
}

t_result	create_test_scene()
{
	
	return (OK);
}


