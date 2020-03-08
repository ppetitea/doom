/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:13:05 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/26 16:59:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "types.h"
# include "SDL_keycode.h"

typedef struct	s_keyboard
{
	t_bool		w;
	t_bool		a;
	t_bool		s;
	t_bool		d;
	SDL_Keycode	key;
}				t_keyboard;

#endif