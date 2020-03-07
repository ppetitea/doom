// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   button_dup.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/02/24 11:25:52 by ppetitea          #+#    #+#             */
// /*   Updated: 2020/02/27 18:47:23 by ppetitea         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "resources/button.h"
// #include "utils/error.h"
// #include "ft/str.h"

// t_button	*duplicate_button(char *name)
// {
// 	t_button	*src;
// 	t_button	*new;

// 	if (name == NULL)
// 		return (throw_null("duplicate_button", "NULL pointer provided"));
// 	if (!(new = init_new_button()))
// 		return (throw_null("duplicate_button", "init_new_button failed"));
// 	if (!(src = get_button(name)))
// 		return (throw_null("duplicate_button", "get_button failed"));
// 	if (!(new->name = ft_strdup(src->name)))
// 		return (throw_null("duplicate_button", "ft_strdup failed"));
// 	if (!copy_animation(&new->animation, &src->animation))
// 		return (throw_null("duplicate_button", "copy_animation failed"));
// 	return (new);
// }
