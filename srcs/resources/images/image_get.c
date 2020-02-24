/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:01:18 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 12:04:29 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/game.h"
#include "resources/images.h"
#include "utils/error.h"
#include "ft/str.h"

t_bitmap	*get_image(char *name)
{
	t_game			*game;
	t_image_node	*image_node;
	t_list_head		*pos;

	if (name == NULL)
		return (throw_null("get_image", "NULL pointer provided"));
	if (!(game = game_singleton(NULL)))
		return (throw_null("get_image", "game is NULL"));
	pos = &game->resources.images;
	while ((pos = pos->next) != &game->resources.images)
	{
		image_node = (t_image_node*)pos;
		if (!ft_strcmp(image_node->name, name))
			return (image_node->image);
	}
	return (throw_null("Not found: get_image", name));
}
