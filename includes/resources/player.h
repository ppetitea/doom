/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/09 16:07:10 by ppetitea         ###   ########.fr       */
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
t_result			init_destructible(t_destructible *destruct);

typedef	struct		s_camera
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
}					t_camera;
t_result			init_camera(t_camera *self);

typedef enum	e_weapon_type
{
	HAND,
	MELEE,
	GUN,
}				t_weapon_type;

typedef struct		s_weapon
{
	t_list_head			node;
	t_weapon_type		type;
	char				*name;
	size_t				ammo;
	size_t				magazine_size;
	size_t				magazine;
	ssize_t				damages;
	t_animation			fire;
	t_animation			reload;
}					t_weapon;
t_weapon			*init_new_weapon();

typedef struct		s_player
{
	t_list_head		node;
	t_list_head		weapons;
	t_weapon		*curr_weapon;
	t_animation		map_icon;
	t_destructible	state;
	t_camera		cam;
}					t_player;
t_result			init_player(t_player *player);

#endif
