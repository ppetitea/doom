/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 17:09:51 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/05 17:20:55 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "node.h"
# include "types.h"

typedef enum	e_log_level
{
	FATAL,
	WARN,
	INFO,
}				t_log_level;

typedef struct	s_res
{
	int			ok;
	int			err;
	int			warn;
	void		*null;
}				t_res;

typedef struct	s_log
{
	t_node		node;
	t_log_level	lvl;
	char		*fn;
	int			line;
	char		*msg;
	//time
}				t_log;

t_res	response();
t_res	console(t_log_level lvl, const char *fn, int line, char *msg);


#endif