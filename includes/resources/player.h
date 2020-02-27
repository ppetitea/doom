/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/26 16:51:09 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "graphic/animation.h"

typedef struct		s_destructible
{
	t_list_head		node;
	int				life_max;
	int				life_curr;
	int				life_pourcent;
	int				armor;
	int				stability;
	t_vec2f			move_impact;
	t_list_head		actions_hurt;
	t_animation		hurt;
	t_list_head		actions_heal;
	t_animation		heal;
	t_list_head		actions_die;
	t_animation		die;
}					t_destructible;

typedef struct		s_movable
{
	t_list_head			node;
	float				velocity;
	t_pos2f				pos;
	t_vec2f				dir;
	t_pos2f				*target;
}					t_movable;

typedef	struct	s_camera
{
	float			fov;
	float			fov_half;
	float			plan_width;
	float			plan_half;
	t_vec2f			pos;
	t_vec2f			dir;
	t_vec2f			to_plan;
	t_vec2f			plan;
	float			dist_to_plan;
	float			height;
	float			rotation_delta;
	float			translation_delta;
	float			velocity;
	int				horizon_height;
	int				horizon_dist;
}				t_camera;

typedef struct		s_player
{
	t_list_head		node;
	t_list_head		weapons;
	t_animation		map_icon;
	t_animation		*curr;
	t_destructible	state;
	t_camera		cam;
}					t_player;

#endif
