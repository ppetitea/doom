/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:58:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/09 23:38:10 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "log/log.h"
#include "colors/color.h"
#include "ft/str.h"
#include "action/action.h"
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>

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
	if (!(self->radio = new_data_set("radioLists", LIST, (t_val)NULL)))
		return (console(FATAL, __func__, __LINE__, "new_data_set fail").err);
	// if (!(self->tags = set_new_arg(ARG_LIST, (t_argv)NULL)))
	// 	return (console(FATAL, __func__, __LINE__, "set_new_arg fail").err);
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
	self->text = NULL;
	self->text_surface = NULL;
	self->font = NULL;
	return (OK);
};

/*
** DELETE GUI
*/

t_result delete_mouse_obs(t_mouse_obs *self)
{
	t_list_head	*curr;
	t_list_head	*next;

	list_del_entry(&self->node);
	curr = &self->actions;
	next = curr->next;
	while ((curr = next) != &self->actions)
	{
		next = next->next;
		list_del_entry(curr);
		free(curr);
	}
	return (OK);
}

t_result delete_key_obs(t_key_obs *self)
{
	t_list_head	*curr;
	t_list_head	*next;

	list_del_entry(&self->node);
	curr = &self->actions;
	next = curr->next;
	while ((curr = next) != &self->actions)
	{
		next = next->next;
		list_del_entry(curr);
		free(curr);
	}
	return (OK);
}

t_result delete_time_obs(t_time_obs *self)
{
	t_list_head	*curr;
	t_list_head	*next;

	list_del_entry(&self->node);
	curr = &self->actions;
	next = curr->next;
	while ((curr = next) != &self->actions)
	{
		next = next->next;
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
	if (gui->radio)
		datas_del(gui->radio);
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

// t_bool	compare_gui_tags()

// t_gui *gui_find_by_tag(t_gui *self, t_result (*fn)(t_gui *))
// {
// 	t_gui *find;
// 	t_node *curr;
// 	t_node *next;

// 	if (self == NULL)
// 		return (ERROR);
// 	curr = self->node.childs;
// 	next = curr->next;
// 	if (self->node.childs)
// 	{
// 		while ((curr = next) != self->node.childs)
// 		{
// 			next = next->next;
// 			if (!ft_strcmp(((t_gui*)curr)->id, id))
// 				return ((t_gui*)curr);
// 			if ((find = gui_find((t_gui *)curr, id)))
// 				return (find);
// 		}
// 	}
// 	return (NULL);
// }

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

t_result	set_gui_font(t_gui *self, char *font, int size)
{
	if (self == NULL || font == NULL)
		return (console(WARN, __func__, __LINE__, "null pointer").warn);
	if (self->font != NULL)
		free(self->font);
	if (!(self->font = TTF_OpenFont(font, size)))
		return (console(FATAL, __func__, __LINE__, "OpenFont fail").err);
	return (OK);
}

t_result	set_gui_text(t_gui *self, char *text, t_bgra color)
{
	SDL_Color	c;

	c.r = color.bgra.r;
	c.g = color.bgra.g;
	c.b = color.bgra.b;
	c.a = color.bgra.a;
	if (self == NULL || self->font == NULL || text == NULL)
		return (console(WARN, __func__, __LINE__, "null pointer").warn);
	if (self->text != NULL)
		free(self->text);
	if (!(self->text = ft_strdup(text)))
		return (console(FATAL, __func__, __LINE__, "malloc fail").err);
	if (self->text[0] == '\0')
		self->text_surface = NULL;
	else if (!(self->text_surface = 
		TTF_RenderText_Blended(self->font, self->text, c)))
		return (console(WARN, __func__, __LINE__, "RenderTextSolid fail").warn);
	self->color = color;
	return (OK);
}

t_result	set_gui_to_display(t_node *node)
{
	((t_gui*)node)->display = TRUE;
	return (OK);
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

// t_result	checkout_gui_list(t_gui *gui, t_node *list)
// {
// 	t_node			*curr;
// 	t_arg			*arg;
// 	t_gui			*root;
// 	t_gui			*find;

// 	root = (t_gui*)node_get_root(&gui->node);
// 	curr = list;
// 	while ((curr = curr->next) != list)
// 	{
// 		arg = (t_arg*)curr;
// 		if ((find = gui_find(root, arg->value.s)))
// 			checkout_gui(find);
// 	}
// 	return (OK);
// }

t_result	check_gui_radio_list(t_gui *gui, t_data	*radio_list)
{
	t_node	*curr;
	t_data	*data;
	t_gui	*root;
	t_gui	*find;

	root = (t_gui*)node_get_root(&gui->node);
	curr = radio_list->node.childs;
	while ((curr = curr->next) != radio_list->node.childs)
	{
		data = (t_data*)curr;
		if (data->type == STRING && (find = gui_find(root, data->value.s)))
			checkout_gui(find);
	}
	check_gui(gui);
	return (OK);
}

t_result	check_gui_radio_list_by_name(t_gui *gui, char *radioList)
{
	t_data	*list;

	if (!(list = data_find_by_key(gui->radio, radioList)))
		return (console(WARNING, __func__, __LINE__, "key not found").warn);
	check_gui_radio_list(gui, list);
	return (OK);
}

t_result	check_gui_radio_lists(t_gui *gui)
{
	t_node	*curr;
	t_data	*radio_list;

	if (gui == NULL)
		return (console(WARNING, __func__, __LINE__, "null pointer").err);
	curr = gui->radio->node.childs;
	while ((curr = curr->next) != gui->radio->node.childs)
	{
		radio_list = (t_data*)curr;
		check_gui_radio_list(gui, radio_list);
	}
	return (OK);
}

t_result	translate_gui(t_gui *gui, t_vec2i translation)
{
	gui->pos.x += translation.x;
	gui->pos.y += translation.y;
	return (OK);
}
t_result	translate_gui_childs(t_gui *parent, t_vec2i translation)
{
	t_gui	*child;
	t_node	*curr;

	curr = parent->node.childs;
	while ((curr = curr->next) != parent->node.childs)
	{
		child = (t_gui*)curr;
		translate_gui(child, translation);
	}
	return (OK);
}
t_result	scroll_down_gui_childs(t_gui *parent)
{
	t_gui	*last_child;
	t_vec2i translation;
	int		childs_amount;
	int		delta;

	if (!(childs_amount = node_childs_amount(&parent->node)))
		return (OK);
	last_child = (t_gui*)parent->node.childs->prev;
	delta = last_child->pos.y + last_child->size.y - parent->size.y;
	if (delta > 0)
	{
		translation = ft_vec2i(0, (delta > 10) ? -10 : -delta);
		translate_gui_childs(parent, translation);
		nodes_foreach_ascend(&parent->node, set_gui_to_update);
	}
	return (OK);
}
t_result	scroll_up_gui_childs(t_gui *parent)
{
	t_gui	*first_child;
	t_vec2i translation;
	int		childs_amount;
	int		delta;

	if (!(childs_amount = node_childs_amount(&parent->node)))
		return (OK);
	first_child = (t_gui*)parent->node.childs->next;
	delta = first_child->pos.y;
	if (delta < 0)
	{
		translation = ft_vec2i(0, (delta < -10) ? 10 : -delta);
		translate_gui_childs(parent, translation);
		nodes_foreach_ascend(&parent->node, set_gui_to_update);
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
t_u32 getpixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	t_u8	*p;
	
	bpp = surface->format->BytesPerPixel;
	p = (t_u8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(t_u16*)p);
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
	}
	else if (bpp == 4)
		return (*(t_u32*)p);
	else
		return (0);
}

void render_text_on_layer(t_layer *layer, SDL_Surface *text)
{
	t_pos2i		off;
	t_pos2i		end;
	t_pos2i		i;
	t_u32		*px;

	if (layer == NULL || text == NULL)
		return ;
	off.y = (int)((layer->height - text->h) * 0.5);
	off.x = (int)((layer->width - text->w) * 0.5);
	end.y = text->h < layer->height ? off.y + text->h : layer->height;
	end.x = text->w < layer->width ? off.x + text->w : layer->width;
	i.x = (off.x < 0) ? -off.x : 0;
	while (off.x + i.x < end.x)
	{
		i.y = (off.y < 0) ? -off.y : 0;
		while (off.y + i.y < end.y)
		{
			px = &layer->pixels[off.x + i.x + (off.y + i.y) * layer->width];
			(*px) = blend_add((t_rgba)getpixel(text, i.x, i.y), (t_rgba)*px);
			i.y++;
		}
		i.x++;
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
		color.bgra.b = ((c = color.bgra.b + 255 * percent) < 255) ? c : 255;
		color.bgra.g = ((c = color.bgra.g + 255 * percent) < 255) ? c : 255;
		color.bgra.r = ((c = color.bgra.r + 255 * percent) < 255) ? c : 255;
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
		color.bgra.b = ((c = color.bgra.b - 255 * percent) > 0) ? c : 0;
		color.bgra.g = ((c = color.bgra.g - 255 * percent) > 0) ? c : 0;
		color.bgra.r = ((c = color.bgra.r - 255 * percent) > 0) ? c : 0;
		layer->pixels[i] = color.px;
	}
}

void	filter_layer(t_layer *layer, t_filter filter)
{
	if (filter == FILTER_LIGHT)
		filter_light_layer(layer, 0.2f);
	else if (filter == FILTER_DARK)
		filter_dark_layer(layer, 0.1f);
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
		render_text_on_layer(&gui->layer, gui->text_surface);
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

t_result	drag_gui(t_gui *gui)
{
	t_pos2i	mouse;
	t_pos2i	pos;

	SDL_GetMouseState(&mouse.x, &mouse.y);
	pos = get_absolute_position(gui);
	gui->pos.x += mouse.x - pos.x;
	gui->pos.y += mouse.y - pos.y;
	return (OK);
}
