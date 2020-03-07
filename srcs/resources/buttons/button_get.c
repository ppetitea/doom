// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   button_get.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/02/24 11:25:52 by ppetitea          #+#    #+#             */
// /*   Updated: 2020/03/05 10:12:26 by ppetitea         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "resources/button.h"
// #include "resources/game.h"
// #include "utils/parser.h"
// #include "utils/error.h"
// #include "ft/str.h"

// t_list_head	*get_resource_button_list()
// {
// 	t_game *game;

// 	if (game = game_singleton(NULL))
// 		return (&game->resources.buttons);
// 	return (NULL);
// }

// t_button	*get_button(char *name)
// {
// 	t_list_head	*buttons;
// 	t_list_head	*pos;
// 	t_button	*curr;

// 	if (name == NULL)
// 		return (throw_null("get_button", "NULL pointer provided"));
// 	if (!(buttons = get_resource_button_list()))
// 		return (throw_null("get_button", "buttons list not found"));
// 	pos = buttons;
// 	while ((pos = pos->next) != buttons)
// 	{
// 		curr = (t_button*)pos;
// 		if (!ft_strcmp(curr->name, name))
// 			return (curr);
// 	}
// 	return (throw_null("get_button", "button not found"));
// }
