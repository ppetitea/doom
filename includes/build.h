/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:19:39 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/29 15:25:33 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

# include "resources/game.h"

t_game	*build();

/*
** test scene
*/
t_scene		*add_test_scene(t_list_head *scenes);
t_result	add_play_button(t_list_head *buttons, t_list_head *render_list,
				t_mouse_followers *followers);

/*
** other scene
*/

#endif