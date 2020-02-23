/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 02:05:11 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "graphic/animation.h"

typedef struct		s_button
{
	t_list_head		node;
	t_animation		animation;
}					t_button;

#endif
