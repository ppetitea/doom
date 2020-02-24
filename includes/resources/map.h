/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 15:40:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "resources/player.h"

typedef struct	s_map_render
{
	
}				t_map_render;

typedef struct	s_map
{
	t_list_head		node;
	char			*name;
	t_player		player;
	t_list_head		mobs;
	t_list_head		objects;
	t_animation		sky;
	t_animation		color;
	t_animation		height;
}				t_map;
t_map			*init_new_map();

#endif
