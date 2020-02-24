/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:57:02 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/24 11:28:18 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "graphic/animation.h"

/*
** init
*/
typedef struct		s_button
{
	t_list_head		node;
	char			*name;
	t_animation		animation;
}					t_button;
t_button			*init_new_button();

/*
** build
*/
t_result	build_new_buttons(t_list_head *buttons, char *path);

#endif
