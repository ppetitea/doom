/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:28:34 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/15 09:34:31 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface/gui.h"
#include "containers/list.h"
#include "log/log.h"
#include <SDL_events.h>
#include "action/action.h"
 
t_result init_listener(t_listener *self)
{
	init_list_head(&self->node);
	self->name = NULL;
	self->list = NULL;
	self->is_listen = NULL;
	self->gui = NULL;
	init_list_head(&self->conditions);
	// init_mouse(&self->mouse)
	// init_keys(&self->keys)
	init_list_head(&self->actions);
	return (OK);
};


t_result	mouse_obs_subscribe(t_mouse_obs *obs)
{
	if (obs == NULL || obs->list == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (obs->subscribed == FALSE)
		list_add_entry(&obs->node, obs->list);
	obs->subscribed = TRUE;
	return (OK);
}
t_result	obs_hover_start_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_hover_end_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_left_up_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_left_down_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_right_up_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_right_down_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_drag_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_drop_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_motion_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_wheel_normal_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}
t_result	obs_wheel_flip_sub(t_mouse_obs *obs)
{
	return (mouse_obs_subscribe(obs));
}

t_result	mouse_obs_unsubscribe(t_mouse_obs *obs)
{
	if (obs == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	list_del_entry(&obs->node);
	obs->subscribed = FALSE;
	return (OK);
}
t_result	obs_hover_start_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_hover_end_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_left_up_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_left_down_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_right_up_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_right_down_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_drag_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_drop_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_motion_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_wheel_normal_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}
t_result	obs_wheel_flip_unsub(t_mouse_obs *obs)
{
	return (mouse_obs_unsubscribe(obs));
}

t_result	key_obs_subscribe(t_key_obs *obs)
{
	if (obs == NULL || obs->list == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (obs->subscribed == FALSE)
		list_add_entry(&obs->node, obs->list);
	obs->subscribed = TRUE;
	return (OK);
}
t_result	key_obs_unsubscribe(t_key_obs *obs)
{
	if (obs == NULL || obs->list == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	list_del_entry(&obs->node);
	obs->subscribed = FALSE;
	return (OK);
}

t_result	time_obs_subscribe(t_time_obs *obs)
{
	if (obs == NULL || obs->list == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	if (obs->subscribed == FALSE)
		list_add_entry(&obs->node, obs->list);
	obs->subscribed = TRUE;
	return (OK);
}
t_result	time_obs_unsubscribe(t_time_obs *obs)
{
	if (obs == NULL || obs->list == NULL)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	list_del_entry(&obs->node);
	obs->subscribed = FALSE;
	return (OK);
}

static t_bool	is_mouse_obs_with_box(t_gui *gui, t_pos2i mouse)
{
	t_vec2i	start;
	t_vec2i	end;

	start = get_absolute_position(gui);
	end.x = start.x + gui->size.x;
	end.y = start.y + gui->size.y;
	if (start.x <= mouse.x && mouse.x < end.x &&
		start.y <= mouse.y && mouse.y < end.y)
		return (TRUE);
	return (FALSE);
}

t_bool	trigger_mouse_observers(t_list_head *observers)
{
	t_mouse_obs	*obs;
	t_list_head	*pos;
	t_list_head	*next;

	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		obs = (t_mouse_obs*)pos;
		trigger_actions(&obs->actions);
	}
	return (FALSE);
}

t_bool	trigger_mouse_obs_on(t_list_head *observers, t_vec2i mouse)
{
	t_mouse_obs	*obs;
	t_gui		*gui;
	t_list_head	*pos;
	t_list_head	*next;

	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		obs = (t_mouse_obs*)pos;
		gui = (t_gui*)obs->gui;
		if (is_mouse_obs_with_box(gui, mouse))
		{
			trigger_actions(&obs->actions);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	trigger_mouse_obs_off(t_list_head *observers, t_vec2i mouse)
{
	t_mouse_obs	*obs;
	t_gui		*gui;
	t_list_head	*pos;
	t_list_head	*next;

	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		obs = (t_mouse_obs*)pos;
		gui = (t_gui*)obs->gui;
		if (!is_mouse_obs_with_box(gui, mouse))
		{
			trigger_actions(&obs->actions);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	handle_mouse_motion(t_gui_interface *interface,
			SDL_MouseMotionEvent event)
{
	t_pos2i mouse;
	
	mouse = (interface->mouse_pos = ft_vec2i(event.x, event.y));
	trigger_mouse_observers(&interface->mouse_motion);
	if (interface->mouse_isdrag)
		return ;
	else if (interface->mouse_isdown)
	{
		interface->mouse_isdrag = TRUE;
		trigger_mouse_observers(&interface->mouse_motion);
	}
	else
	{
		trigger_mouse_obs_off(&interface->mouse_hover_end, mouse);
		trigger_mouse_obs_on(&interface->mouse_hover_start, mouse);
	}
}

void	handle_mouse_down(t_gui_interface *interface, SDL_MouseButtonEvent event)
{
	interface->mouse_pos = ft_vec2i(event.x, event.y);
	interface->mouse_isdown = TRUE;
	if (event.button == SDL_BUTTON_LEFT)
		trigger_mouse_observers(&interface->mouse_left_down);
	else if (event.button == SDL_BUTTON_RIGHT)
		trigger_mouse_observers(&interface->mouse_right_down);
}

void	handle_mouse_up(t_gui_interface *interface, SDL_MouseButtonEvent event)
{
	interface->mouse_pos = ft_vec2i(event.x, event.y);
	if (interface->mouse_isdrag)
		trigger_mouse_observers(&interface->mouse_drop);
	else if (event.button == SDL_BUTTON_LEFT)
		trigger_mouse_observers(&interface->mouse_left_up);
	else if (event.button == SDL_BUTTON_RIGHT)
		trigger_mouse_observers(&interface->mouse_right_up);
	interface->mouse_isdown = FALSE;
	interface->mouse_isdrag = FALSE;
}

void	handle_mouse_wheel(t_gui_interface *interface,
			SDL_MouseWheelEvent event)
{
	if (event.y > 0)
		trigger_mouse_observers(&interface->mouse_wheel_normal);
	else if (event.y < 0)
		trigger_mouse_observers(&interface->mouse_wheel_flip);
}

t_bool	trigger_key_observers(t_list_head *observers,
			SDL_Keycode key)
{
	t_key_obs	*obs;
	t_list_head	*pos;
	t_list_head	*next;
	t_bool		ret;

	ret = FALSE;
	pos = observers;
	next = pos->next;
	while ((pos = next) != observers)
	{
		next = next->next;
		obs = (t_key_obs*)pos;
		if (obs->key == key || obs->key == -1)
		{
			trigger_actions(&obs->actions);
			ret = TRUE;
		}
	}
	return (ret);
}

void	handle_keyboard_down(t_gui_interface *interface,
	SDL_KeyboardEvent event)
{
	interface->key = event.keysym.sym;
	trigger_key_observers(&interface->key_down, interface->key);
	(void)event;
}

void	handle_keyboard_up(t_gui_interface *interface,
	SDL_KeyboardEvent event)
{
	
	interface->key = event.keysym.sym;
	trigger_key_observers(&interface->key_up, interface->key);
	(void)event;
}

t_result	handle_gui_events(t_gui_interface *interface, SDL_Event *event)
{
	if (event->type == SDL_QUIT || event->key.keysym.sym == SDLK_ESCAPE)
		interface->is_running = FALSE;
	else if (event->type == SDL_MOUSEMOTION)
		handle_mouse_motion(interface, event->motion);
	else if (event->type == SDL_MOUSEBUTTONDOWN)
		handle_mouse_down(interface, event->button);
	else if (event->type == SDL_MOUSEBUTTONUP)
		handle_mouse_up(interface, event->button);
	else if (event->type == SDL_MOUSEWHEEL)
		handle_mouse_wheel(interface, event->wheel);
	else if (event->type == SDL_KEYDOWN)
		handle_keyboard_down(interface, event->key);
	else if (event->type == SDL_KEYUP)
		handle_keyboard_up(interface, event->key);
	return (OK);
}