/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:51:06 by ppetitea          #+#    #+#             */
/*   Updated: 2020/03/09 18:19:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources/player.h"
#include "utils/error.h"

t_weapon	*init_new_weapon()
{
	t_weapon *self;

	if (!(self = malloc(sizeof(t_weapon))))
		return (throw_null("init_weapon", "malloc failed"));
	init_list_head(&self->node);
	self->type = HAND;
	self->name = NULL;
	self->ammo = 100;
	self->magazine_size = 10;
	self->magazine = self->magazine_size;
	self->damages = 21;
	init_animation(&self->fire);
	init_animation(&self->reload);
	return (self);
}

t_result	init_destructible(t_destructible *destruct)
{
	if (destruct == NULL)
		return (throw_error("init_destructible", "NULL pointer provided"));
	init_list_head(&destruct->node);
	destruct->life_max = 100;
	destruct->life_curr = destruct->life_max;
	destruct->life_pourcent = 100;
	destruct->armor = 42;
	destruct->stability = 10;
	destruct->move_impact = ft_vec2f(0.1, 0.1);
	init_list_head(&destruct->actions_hurt);
	init_animation(&destruct->hurt);
	init_list_head(&destruct->actions_heal);
	init_animation(&destruct->heal);
	init_list_head(&destruct->actions_die);
	init_animation(&destruct->die);
	return (OK);
}

t_result	init_camera(t_camera *self)
{
	if (self == NULL)
		return (throw_error("init_camera", "NULL pointer provided"));
	self->fov = 90.0f / 180.0f * M_PI;
	self->fov_half = self->fov / 2.0f;
	self->plan_width = 640.0f;
	self->plan_half = self->plan_width / 2.0f;
	self->pos = ft_vec2f(0, 0);
	self->dir = ft_vec2f(0, 1);
	self->dist_to_plan = self->plan_half / (float)tan(self->fov / 2.0f);
	self->plan = ft_vec2f(-self->dir.y, self->dir.x);
	self->to_plan = vec2f_scalar(self->dir, self->dist_to_plan);
	self->height = self->plan_width / 4.0f;
	self->rotation_delta = 5.0f;
	self->translation_delta = 5.0f;
	self->velocity = 1.0f;
	self->horizon_height = 120;
	self->horizon_dist = 1000;
	return (OK);
}

t_result	init_player(t_player *player)
{
	if (player == NULL)
		return (throw_error("init_player", "NULL pointer provided"));
	init_list_head(&player->node);
	init_list_head(&player->weapons);
	player->curr_weapon = NULL;
	player->curr = NULL;
	init_animation(&player->map_icon);
	init_destructible(&player->state);
	init_camera(&player->cam);
	return (OK);
}
