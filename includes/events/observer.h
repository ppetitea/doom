/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:56:55 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/22 23:11:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSERVER_H
# define OBSERVER_H

# include "containers/list.h"
# include "maths/vec2f.h"
# include "maths/vec2i.h"

typedef struct			s_collide_observer
{
	t_list_head			node;
	t_vec2i				*offset;
	t_vec2i				*size;
	t_list_head			*suscribe_list;
	t_bool				activable;
	t_bool				active;
}						t_collide_observer;
t_result				init_collide_observer(t_collide_observer *self);

typedef struct			s_collide
{
	t_vec2i				offset;
	t_vec2i				size;
	t_collide_observer	hover;
	t_collide_observer	select;
	t_collide_observer	drag;
}						t_collide;
t_result				init_collide(t_collide *self);


#endif