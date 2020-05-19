/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:43:29 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/19 22:40:48 by ppetitea         ###   ########.fr       */
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
# include "action/action.h"
# include "SDL_ttf.h"
# include "SDL_surface.h"
# include "data/data.h"

/*
** EVENT
*/
typedef enum	e_mouse_button
{
	MOUSE_LEFT,
	MOUSE_RIGHT,
	MOUSE_WHEEL,
}				t_mouse_button;

typedef enum	e_mouse_e_type
{
	MOUSE_UP,
	MOUSE_DOWN,
	MOUSE_MOTION,
	MOUSE_WHEEL_NORMAL,
	MOUSE_WHEEL_FLIP,
}				t_mouse_e_type;

typedef struct	s_mouse_event
{
	t_list_head		node;
	t_mouse_button	button;
	t_mouse_e_type	type;
}				t_mouse_event;

typedef struct	s_mouse
{
	t_list_head	events;
	t_bool		*hold_down;
	t_vec2f		velocity;
	float		wheel;
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_keys
{
	t_list_head		up;
	t_list_head		down;
	t_list_head		*hold_ref;
}				t_keys;

/*
** L'event est passe a tout l'arbre de composants des feuilles a la racine
** comparer avec les event enregistre dans chaque component
*/
typedef struct	s_event
{
	t_list_head		node;
	//time
	t_mouse			mouse;
	t_keys			keys;
}				t_event;

typedef struct	s_event
{
	t_list_head		node;
	//time
	t_mouse			mouse;
	t_keys			keys;
}				t_event;

typedef struct	s_listener
{
	t_list_head		node;
	char			*name;
	t_list_head		*list;
	t_bool			is_listen;
	void			*gui;
	t_list_head		conditions;
	t_mouse			mouse;
	t_keys			keys;
	t_list_head		actions;
}				t_listener;

t_bool		condition(t_listener *listener, t_event *event);

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
t_result	obs_hover_start_sub(t_mouse_obs *obs);
t_result	obs_hover_end_sub(t_mouse_obs *obs);
t_result	obs_left_up_sub(t_mouse_obs *obs);
t_result	obs_left_down_sub(t_mouse_obs *obs);
t_result	obs_right_up_sub(t_mouse_obs *obs);
t_result	obs_right_down_sub(t_mouse_obs *obs);
t_result	obs_drag_sub(t_mouse_obs *obs);
t_result	obs_drop_sub(t_mouse_obs *obs);
t_result	obs_motion_sub(t_mouse_obs *obs);
t_result	obs_wheel_normal_sub(t_mouse_obs *obs);
t_result	obs_wheel_flip_sub(t_mouse_obs *obs);
t_result	mouse_obs_unsubscribe(t_mouse_obs *obs);
t_result	obs_hover_start_unsub(t_mouse_obs *obs);
t_result	obs_hover_end_unsub(t_mouse_obs *obs);
t_result	obs_left_up_unsub(t_mouse_obs *obs);
t_result	obs_left_down_unsub(t_mouse_obs *obs);
t_result	obs_right_up_unsub(t_mouse_obs *obs);
t_result	obs_right_down_unsub(t_mouse_obs *obs);
t_result	obs_drag_unsub(t_mouse_obs *obs);
t_result	obs_drop_unsub(t_mouse_obs *obs);
t_result	obs_motion_unsub(t_mouse_obs *obs);
t_result	obs_wheel_normal_unsub(t_mouse_obs *obs);
t_result	obs_wheel_flip_unsub(t_mouse_obs *obs);

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
	t_data		*radio;
	// t_arg		*tags;
	int			z_index;
	t_bool		up_to_date;
	t_bool		display;
	t_pos2i		pos;
	t_vec2i		size;
	t_layer		layer;
	t_image		*background;
	t_bgra		bg_color;
	t_filter	filter;
	t_list_head	listeners;
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
	char		*text;
	SDL_Surface	*text_surface;
	TTF_Font	*font;
	t_bgra		color;
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

t_result	set_gui_font(t_gui *self, char *font, int size);

t_result	set_gui_text(t_gui *self, char *text, t_bgra color);

t_result	set_gui_to_display(t_node *node);

void		set_gui_to_update(t_node *node);

t_result	lighten_gui_layer(t_gui *gui);

t_result	darken_gui_layer(t_gui *gui);

t_result	filter_reset_gui_layer(t_gui *gui);

t_result	toogle_colorize_gui(t_gui *gui);

t_result	checkout_gui(t_gui *gui);

t_result	check_gui(t_gui *gui);

t_result	check_gui_radio_list(t_gui *gui, t_data	*radio_list);

t_result	check_gui_radio_list_by_name(t_gui *gui, char *radioList);

t_result	check_gui_radio_lists(t_gui *gui);

t_result	translate_gui(t_gui *gui, t_vec2i translation);

t_result	translate_gui_childs(t_gui *parent, t_vec2i translation);

t_result	scroll_down_gui_childs(t_gui *parent);

t_result	scroll_up_gui_childs(t_gui *parent);

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

t_result	drag_gui(t_gui *gui);

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
	SDL_Keycode key;
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

t_result	build_radio_default_events(t_gui *radio);

t_gui		*build_gui_button(char *name, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);

t_gui	*build_gui_checkbox(char *name, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);


t_gui	*build_gui_radio(char *name, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);

t_gui		*build_gui_image(char *name, t_vec2i size, t_pos2i pos, char *img_src);

t_result	build_gui_input_default_events(t_gui *gui);

t_gui	*build_gui_input(char *name, t_pos2i pos, t_vec2i size,
			t_gui_interface *interface);

t_result	build_gui_scrollview_default_events(t_gui *gui);

t_gui	*build_gui_scrollview(char *name, t_pos2i pos, t_vec2i size,
			t_gui_interface *interface);

t_result build_gui_checkbox_childs(t_gui *parent, t_data *list,
	t_gui_interface *interface);

t_gui *build_gui_checkbox_list(t_data *list, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);

t_result build_gui_radio_childs(t_gui *parent, t_data *radio_list,
	t_gui_interface *interface);

t_gui *build_gui_radio_list(t_data *list, t_pos2i pos, t_vec2i size,
	t_gui_interface *interface);

#endif