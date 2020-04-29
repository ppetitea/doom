/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:58:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/30 00:54:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "log/log.h"
#include "colors/color.h"
#include "ft/str.h"
#include "action/action.h"
#include <stdlib.h>

/*
** INIT GUI
*/

t_result init_mouse_obs(t_mouse_obs *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->actions))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->gui = NULL;
	self->list = NULL;
	self->subscribed = FALSE;
	return (OK);
}

t_result init_key_obs(t_key_obs *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->actions))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->gui = NULL;
	self->list = NULL;
	self->subscribed = FALSE;
	self->key = -1;
	return (OK);
}

t_result init_time_obs(t_time_obs *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->actions))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->gui = NULL;
	self->list = NULL;
	self->subscribed = FALSE;
	self->seconds = -1;
	return (OK);
}

t_result init_gui_mouse_obs(t_gui *self)
{
	if (!init_mouse_obs(&self->hover_start))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->hover_end))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->left_up))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->left_down))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->right_up))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->right_down))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->drag))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->drop))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->motion))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->wheel_normal))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	if (!init_mouse_obs(&self->wheel_flip))
		return (console(FATAL, __func__, __LINE__, "init_mouse_obs fail").err);
	return (OK);
}

void init_layer(t_layer *self)
{
	self->height = 0;
	self->width = 0;
	self->pixels = NULL;
}

t_result init_gui(t_gui *self)
{
	if (!init_list(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_node fail").err);
	self->id = NULL;
	self->z_index = 0;
	self->display = FALSE;
	self->up_to_date = FALSE;
	self->pos.x = 0;
	self->pos.y = 0;
	self->size.x = 0;
	self->size.y = 0;
	init_layer(&self->layer);
	self->background = NULL;
	self->bg_color.px = 0x000000;
	self->filter = FILTER_NONE;
	if (!init_gui_mouse_obs(self))
		return (console(FATAL, __func__, __LINE__, "init fail").err);
	if (!init_key_obs(&self->key_up))
		return (console(FATAL, __func__, __LINE__, "init fail").err);
	if (!init_key_obs(&self->key_down))
		return (console(FATAL, __func__, __LINE__, "init fail").err);
	if (!init_time_obs(&self->time_obs))
		return (console(FATAL, __func__, __LINE__, "init fail").err);
	return (OK);
};

/*
** DELETE GUI
*/

t_result delete_mouse_obs(t_mouse_obs *self)
{
	t_list_head	*curr;

	curr = &self->actions;
	while ((curr = curr->next) != &self->actions)
	{
		list_del_entry(curr);
		free(curr);
	}
	return (OK);
}

t_result delete_key_obs(t_key_obs *self)
{
	t_list_head	*curr;

	curr = &self->actions;
	while ((curr = curr->next) != &self->actions)
	{
		list_del_entry(curr);
		free(curr);
	}
	return (OK);
}

t_result delete_time_obs(t_time_obs *self)
{
	t_list_head	*curr;

	curr = &self->actions;
	while ((curr = curr->next) != &self->actions)
	{
		list_del_entry(curr);
		free(curr);
	}
	return (OK);
}

t_result delete_gui_mouse_obs(t_gui *self)
{
	if (!delete_mouse_obs(&self->hover_start))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->hover_end))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->left_up))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->left_down))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->right_up))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->right_down))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->drag))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->drop))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->motion))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->wheel_normal))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	if (!delete_mouse_obs(&self->wheel_flip))
		return (console(FATAL, __func__, __LINE__, "del_mouse_obs fail").err);
	return (OK);
}

t_result	del_gui(t_node *node)
{
	t_gui *gui;

	gui = (t_gui*)node;
	if (gui->id)
		free(gui->id);
	if (gui->layer.pixels)
		free(gui->layer.pixels);
	delete_gui_mouse_obs(gui);
	delete_key_obs(&gui->key_up);
	delete_key_obs(&gui->key_down);
	delete_time_obs(&gui->time_obs);
	node_del(&gui->node);
	return (OK);
}

/*
** INIT NEW GUI
*/

t_gui *init_new_gui()
{
	t_gui *self;

	if (!(self = malloc(sizeof(t_gui))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	if (!init_gui(self) && del_gui(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_gui fail").null);
	return (self);
}

/*
** FIND GUI
*/

t_gui *gui_find(t_gui *self, char *id)
{
	t_gui *find;
	t_node *curr;
	t_node *next;

	if (self == NULL)
		return (ERROR);
	curr = self->node.childs;
	next = curr->next;
	if (self->node.childs)
	{
		while ((curr = next) != self->node.childs)
		{
			next = next->next;
			if (!ft_strcmp(((t_gui*)curr)->id, id))
				return ((t_gui*)curr);
			if ((find = gui_find((t_gui *)curr, id)))
				return (find);
		}
	}
	return (NULL);
}

/*
** SET GUI
*/

t_gui		*set_new_gui(char *id, int width, int height)
{
	t_gui	*self;

	if (!(self = init_new_gui()))
		return (console(FATAL, __func__, __LINE__, "init_new_gui fail").null);
	if (!(self->id = ft_strdup(id)) && del_gui(&self->node))
		return (console(FATAL, __func__, __LINE__, "malloc fail").null);
	self->layer.width = width;
	self->layer.height = height;
	self->size.x = width;
	self->size.y = height;
	if (!(self->layer.pixels = malloc(sizeof(t_u32) * width * height)))
	{
		del_gui(&self->node);
		return (console(WARN, __func__, __LINE__, "malloc fail").null);
	}
	return (self);
}

void	set_gui_to_update(t_node *node)
{
	((t_gui*)node)->up_to_date = FALSE;
}

t_result	lighten_gui_layer(t_gui *gui)
{
	gui->filter = FILTER_LIGHT;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	darken_gui_layer(t_gui *gui)
{
	gui->filter = FILTER_DARK;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	filter_check_gui_layer(t_gui *gui)
{
	gui->filter = FILTER_DARK;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	filter_reset_gui_layer(t_gui *gui)
{
	gui->filter = FILTER_NONE;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	toogle_colorize_gui(t_gui *gui)
{
	t_bgra	green;
	t_bgra	gray;

	green = ft_bgra(82, 216, 105, 255);
	gray = ft_bgra(159, 159, 159, 255);
	gui->bg_color = (gui->bg_color.px == gray.px) ? green : gray;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	checkout_gui(t_gui *gui)
{
	t_bgra	gray;

	gray = ft_bgra(159, 159, 159, 255);
	gui->bg_color = gray;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	check_gui(t_gui *gui)
{
	t_bgra	green;

	green = ft_bgra(82, 216, 105, 255);
	gui->bg_color = green;
	nodes_foreach_ascend(&gui->node, set_gui_to_update);
	return (OK);
}

t_result	checkout_gui_list(t_gui *gui, t_node *list)
{
	t_node			*curr;
	t_arg			*arg;
	t_gui			*root;
	t_gui			*find;

	root = (t_gui*)node_get_root(&gui->node);
	curr = list;
	while ((curr = curr->next) != list)
	{
		arg = (t_arg*)curr;
		if ((find = gui_find(root, arg->value.s)))
			checkout_gui(find);
	}
	return (OK);
}

/*
** RENDER GUI
*/

void colorize_layer(t_layer *layer, t_bgra color)
{
	int i;

	i = -1;
	while (++i < layer->height * layer->width)
		layer->pixels[i] = color.px;
}

void render_background_on_layer(t_layer *layer, t_image *bg)
{
	int x;
	int y;
	float x_ratio;
	float y_ratio;

	if (bg == NULL)
		return;
	x_ratio = (float)bg->width / (float)layer->width;
	y_ratio = (float)bg->height / (float)layer->height;
	y = -1;
	while (++y < layer->height)
	{
		x = -1;
		while (++x < layer->width)
		{
			layer->pixels[x + y * layer->width] =
				bg->pixels[(int)(x * x_ratio) + (int)(y * y_ratio) * bg->width];
		}
	}
}

void render_child_layer_on_parent_layer(t_layer *dest, t_gui *child)
{
	t_rgba curr;
	t_u32 *px;
	t_vec2i i;
	t_pos2i end;
	t_pos2f scale;

	scale.x = (float)child->layer.width / (float)child->size.x;
	scale.y = (float)child->layer.height / (float)child->size.y;
	end.x = child->pos.x + child->size.x;
	end.x = end.x < dest->width ? end.x : dest->width;
	end.y = child->pos.y + child->size.y;
	end.y = end.y < dest->height ? end.y : dest->height;
	i.y = child->pos.y < 0 ? -child->pos.y : 0;
	while (child->pos.y + i.y < end.y)
	{
		i.x = child->pos.x < 0 ? -child->pos.x : 0;
		while (child->pos.x + i.x < end.x)
		{
			curr.px = child->layer.pixels[(int)(i.x * scale.x +
				(int)(i.y * scale.y) * child->layer.width)];
			px = &dest->pixels[child->pos.x + i.x + (i.y + child->pos.y) * dest->width];
			*px = blend_add(curr, (t_rgba)*px);
			++i.x;
		}
		++i.y;
	}
}

void	filter_light_layer(t_layer *layer, float percent)
{
	t_bgra			color;
	int				c;
	int				i;
	
	i = -1;
	while (++i < layer->width * layer->height)
	{
		color.px = layer->pixels[i];
		color.bgra.r = ((c = color.bgra.r + 255 * percent) < 255) ? c : 255;
		color.bgra.g = ((c = color.bgra.g + 255 * percent) < 255) ? c : 255;
		color.bgra.b = ((c = color.bgra.b + 255 * percent) < 255) ? c : 255;
		layer->pixels[i] = color.px;
	}
}

void	filter_dark_layer(t_layer *layer, float percent)
{
	t_bgra			color;
	int				c;
	int				i;

	i = -1;
	while (++i < layer->width * layer->height)
	{
		color.px = layer->pixels[i];
		color.bgra.r = ((c = color.bgra.r - 255 * percent) > 0) ? c : 0;
		color.bgra.g = ((c = color.bgra.g - 255 * percent) > 0) ? c : 0;
		color.bgra.b = ((c = color.bgra.b - 255 * percent) > 0) ? c : 0;
		layer->pixels[i] = color.px;
	}
}

void	filter_layer(t_layer *layer, t_filter filter)
{
	if (filter == FILTER_LIGHT)
		filter_light_layer(layer, 0.5f);
	else if (filter == FILTER_DARK)
		filter_dark_layer(layer, 0.5f);
}

t_result render_gui_node(t_node *node)
{
	t_gui	*gui;
	t_node	*curr;
	t_gui	*child;

	gui = (t_gui *)node;
	if (gui->display && !gui->up_to_date)
	{
		colorize_layer(&gui->layer, gui->bg_color);
		render_background_on_layer(&gui->layer, gui->background);
		curr = node->childs;
		while ((curr = curr->prev) != node->childs)
		{
			child = (t_gui*)curr;
			render_child_layer_on_parent_layer(&gui->layer, child);
		}
		filter_layer(&gui->layer, gui->filter);
		gui->up_to_date = TRUE;
	}
	return (OK);
}

void render_gui(t_gui *gui)
{
	node_foreach_prev(&gui->node, render_gui_node);
	render_gui_node(&gui->node);
}

/*
** SORT GUI
*/

t_bool	z_index_rule(t_node *a, t_node *b)
{
	return (((t_gui*)a)->z_index > ((t_gui*)b)->z_index ? TRUE : FALSE);
}

/*
** GUI POSITION
*/

t_pos2i get_absolute_position(t_gui *gui)
{
	t_node *curr;
	t_node *parent;
	t_pos2i pos;
	
	pos = gui->pos;
	curr = &gui->node;
	parent = curr->parent;
	while ((curr = parent) != NULL)
	{
		parent = parent->parent;
		pos.x += ((t_gui*)curr)->pos.x;
		pos.y += ((t_gui*)curr)->pos.y;
	}
	return (pos);
}
