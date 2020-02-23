/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 01:39:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/23 01:49:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "containers/list.h"
# include "utils/parser.h"

typedef enum	e_resource_type
{
	R_GAME,
	R_SCENE,
	R_MAP,
	R_PLAYER,
	R_MOB,
	R_OBJECT,
	R_BUTTON,
}				t_resource_type;

typedef struct	s_action_node
{
	t_list_head		node;
	t_resource_type	resource_type;
	void			*resource;
	t_dnon_object	*args;
	t_result		(*action)(void*, t_resource_type, t_dnon_object*);
}				t_action_node;

#endif