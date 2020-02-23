/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 03:12:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOB_H
# define MOB_H

# include "graphic/animation.h"
# include "resources/player.h"

typedef struct		s_movable
{
	t_list_head			node;
	float				velocity;
	t_pos2f				pos;
	t_vec2f				dir;
	t_pos2f				*target;
}					t_movable;

typedef struct		s_mob
{
	t_list_head				node;
	t_animation				map_icon;
	t_destructible			state;
	t_animation				attack;
	t_movable				move;
	t_oriented_animations	o_anim;
}					t_mob;

#endif
