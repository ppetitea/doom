/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:43:29 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/29 00:36:36 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "containers/node.h"
# include "containers/list.h"
# include "image/image.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"
# include "SDL_keycode.h"
# include "colors/color.h"

/*
** EVENTS ACTIONS
*/

typedef	union	u_arg
{
	int			integer;
	float		floating;
	char		character;
	void		*pointer;
}				t_arg;

typedef struct	s_arg_node
{
	t_list_head		node;
	t_arg			arg;
}				t_arg_node;
t_result		init_new_arg(t_arg arg);

typedef struct	s_action_node
{
	t_list_head		node;
	char			*key;
	t_result		(*fn)();
	t_bool			active;
	t_list_head		args;
}				t_action_node;
t_action_node	*init_new_action();

/*
**	add
*/
t_action_node	*add_new_basic_action(t_list_head *actions, char *key,
					t_result (*fn)());
t_action_node	*add_new_action(t_list_head *actions, t_result (*fn)(),
					char *key, t_arg arg);
t_arg_node		*add_new_arg(t_list_head *args, t_arg arg);
t_result		add_action_arg(t_action_node *action, t_arg arg);

/*
** trigger
*/
void			trigger_actions(t_list_head *actions);

/*
** EVENTS OBSERVERS
*/

typedef struct		s_mouse_obs
{
	t_list_head		node;
	void			*gui;
	t_list_head		*list;
	t_bool			subscribed;
	t_list_head		actions;
}					t_mouse_obs;

typedef struct		s_key_obs
{
	t_list_head		node;
	void			*gui;
	SDL_Keycode		key;
	t_list_head		*list;
	t_bool			subscribed;
	t_list_head		actions;
}					t_key_obs;

typedef struct		s_time_obs
{
	t_list_head		node;
	void			*gui;
	double			seconds;
	t_list_head		*list;
	t_bool			subscribed;
	t_list_head		actions;
}					t_time_obs;

t_result	mouse_obs_subscribe(t_mouse_obs *obs);
t_result	mouse_obs_unsubscribe(t_mouse_obs *obs);

t_result	key_obs_subscribe(t_key_obs *obs);
t_result	key_obs_unsubscribe(t_key_obs *obs);

t_result	time_obs_subscribe(t_time_obs *obs);
t_result	time_obs_unsubscribe(t_time_obs *obs);

/*
** LAYER
*/

typedef enum		e_filter
{
	FILTER_CIRCULAR_SHADOW,
	FILTER_CIRCULAR_BLEND,
	FILTER_LIGHT,
	FILTER_DARK,
	FILTER_BLEND,
	FILTER_NONE,
}					t_filter;

typedef struct	s_layer
{
	int			width;
	int			height;
	t_u32		*pixels;
}				t_layer;

/*
** GUI
*/

typedef struct	s_gui
{
	t_node		node;
	char		*id;
	int			z_index;
	t_bool		up_to_date;
	t_bool		display;
	t_pos2i		pos;
	t_vec2i		size;
	t_layer		layer;
	t_image		*background;
	t_bgra		bg_color;
	t_filter	filter;
	t_mouse_obs	hover_start;
	t_mouse_obs	hover_end;
	t_mouse_obs	left_up;
	t_mouse_obs	left_down;
	t_mouse_obs	right_up;
	t_mouse_obs	right_down;
	t_mouse_obs	drag;
	t_mouse_obs	drop;
	t_mouse_obs	motion;
	t_mouse_obs	wheel_normal;
	t_mouse_obs	wheel_flip;
	t_key_obs	key_up;
	t_key_obs	key_down;
	t_time_obs	time_obs;
}				t_gui;

/*
** INIT GUI
*/

t_result init_mouse_obs(t_mouse_obs *self);

t_result init_key_obs(t_key_obs *self);

t_result init_time_obs(t_time_obs *self);

t_result init_gui_mouse_obs(t_gui *self);

void init_layer(t_layer *self);

t_result init_gui(t_gui *self);

/*
** DELETE GUI
*/

t_result delete_mouse_obs(t_mouse_obs *self);

t_result delete_key_obs(t_key_obs *self);

t_result delete_time_obs(t_time_obs *self);

t_result delete_gui_mouse_obs(t_gui *self);

t_result	del_gui(t_node *node);

/*
** INIT NEW GUI
*/

t_gui *init_new_gui();

/*
** FIND GUI
*/

t_gui *gui_find(t_gui *self, char *id);

/*
** SET GUI
*/

t_gui		*set_new_gui(char *id, int width, int height);

t_result	lighten_gui_layer(t_gui *gui);

t_result	darken_gui_layer(t_gui *gui);

t_result	filter_reset_gui_layer(t_gui *gui);

t_result	toogle_colorize_gui(t_gui *gui);

t_result	checkout_gui(t_gui *gui);

t_result	check_gui(t_gui *gui);

t_result	checkout_gui_list(t_gui *gui, t_list_head *string_list);

/*
** RENDER GUI
*/

void colorize_layer(t_layer *layer, t_bgra color);

void render_background_on_layer(t_layer *layer, t_image *bg);

void render_child_layer_on_parent_layer(t_layer *dest, t_gui *child);

void render_gui(t_gui *gui);

/*
** SORT GUI
*/

t_bool	z_index_rule(t_node *a, t_node *b);

/*
** GUI POSITION
*/

t_pos2i get_absolute_position(t_gui *gui);

/*
** GUI INTERFACE
*/

typedef struct	s_gui_interface
{
	t_node		scenes;
	t_gui		*curr_scene;
	t_list_head	images;
	t_list_head	songs;
	t_pos2i		mouse_pos;
	t_bool		mouse_isdown;
	t_bool		mouse_ishover;
	t_bool		mouse_isdrag;
	t_list_head mouse_hover_start;
	t_list_head mouse_hover_end;
	t_list_head mouse_left_up;
	t_list_head mouse_left_down;
	t_list_head mouse_right_up;
	t_list_head mouse_right_down;
	t_list_head mouse_drag;
	t_list_head mouse_drop;
	t_list_head mouse_motion;
	t_list_head mouse_wheel_normal;
	t_list_head mouse_wheel_flip;
	t_list_head key_up;
	t_list_head key_down;
	t_list_head time;
	t_bool		is_running;
}				t_gui_interface;


t_result	init_gui_interface(t_gui_interface *self);

# include <SDL_events.h>


t_result	handle_gui_events(t_gui_interface *interface, SDL_Event *event);

/*
** GUI SCENE
*/

t_result	build_gui_observers(t_gui_interface *interface, t_gui *gui);

t_gui		*build_gui_scene(char *name, t_vec2i screen_size);

t_result	build_button_default_events(t_gui *button);

t_result	build_checkbox_default_events(t_gui *checkbox);

t_result	build_radio_default_events(t_gui *radio, t_list_head *radio_list);

t_gui		*build_gui_button(char *name, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);

t_gui	*build_gui_checkbox(char *name, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);


t_gui	*build_gui_radio(char *name, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);

t_gui		*build_gui_image(char *name, t_vec2i size, t_pos2i pos, char *img_src);


#endif