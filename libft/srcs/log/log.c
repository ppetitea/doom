/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 17:30:14 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/16 19:15:26 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log/log.h"
#include <stdlib.h>
#include "ft/io.h"
#include "ft/str.h"

/*
** LOG RESPONSE
*/

t_res	response()
{
	t_res res;

	res.ok = OK;
	res.warn = WARNING;
	res.err = ERROR;
	res.null = NULL;
	return (res);
}

/*
** PRINT LOG
*/

void	print_log_level(t_log_level lvl, int fd)
{
	if (lvl == INFO)
		ft_putstr_fd("Info: ", fd);
	else if (lvl == WARN)
		ft_putstr_fd("Warning: ", fd);
	else if (lvl == FATAL)
		ft_putstr_fd("FATAL: ", fd);
}

void	log_print_fd(t_log *log, int fd)
{
	print_log_level(log->lvl, fd);
	ft_putstr_fd(log->fn, fd);
	ft_putstr_fd("() line ", fd);
	ft_putnbr_fd(log->line, fd);
	ft_putstr_fd("\n\t", fd);
	ft_putstr_fd(log->msg, fd);
	ft_putstr_fd("\n", fd);
}

t_res	console(t_log_level lvl, const char *fn, int line, char *msg)
{
	int fd;

	fd = 1;
	print_log_level(lvl, fd);
	ft_putstr_fd(fn, fd);
	ft_putstr_fd("() line ", fd);
	ft_putnbr_fd(line, fd);
	ft_putstr_fd("\t", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	return (response());
}

// /*
// ** INIT LOGS
// */

// t_log	*init_new_logs()
// {
// 	t_log *logs;

// 	if (!(logs = malloc(sizeof(t_log))))
// 		return (console(WARN, __func__, __LINE__, "malloc failed").null);
// 	if (!init_list(&logs->node))
// 	{
// 		free(logs);
// 		return (console(WARN, __func__, __LINE__, "init_list failed").null);
// 	}
// 	if (!(logs->fn = ft_strdup("root")))
// 	{
// 		free(logs->node.childs);
// 		free(logs);
// 		return (console(WARN, __func__, __LINE__, "ft_strdup failed").null);
// 	}
// 	logs->lvl = INFO;
// 	logs->msg = NULL;
// 	return (logs);
// }

// t_log	*logs(t_log *current)
// {
// 	static t_log *logs = NULL;

// 	if (logs == NULL && !(logs = init_new_logs()))
// 		return (console(WARN, __func__, __LINE__, "init_new_logs failed").null);
// 	else if (current != NULL)
// 		logs = current;
// 	return (logs);
// }

// /*
// ** GET LOGS
// */

// t_log	*get_curr_log()
// {
// 	return (logs(NULL));
// }

// t_log	*get_logs()
// {
// 	t_log	*curr;
// 	t_node	*parent;

// 	curr = get_curr_log();
// 	parent = &curr->node;
// 	while (parent->parent != NULL)
// 		parent = parent->parent;
// 	return ((t_log*)parent);
// }

// /*
// ** SET LOGS
// */

// void	set_curr_log(t_log *log)
// {
// 	logs(log);
// }

// /*
// ** OPEN / QUIT LOG
// */



// /*
// ** INIT LOG
// */

// t_log *init_log(t_log *self)
// {
// 	if (!init_list(&self->node))
// 		return (console(WARN, __func__, __LINE__, "init_list() failed").null);
// 	self->fn = NULL;
// 	self->line = 0;
// 	self->lvl = INFO;
// 	self->msg = NULL;
// 	return (self);
// }

// t_log *init_new_log()
// {
// 	t_log *self;

// 	if (!(self = malloc(sizeof(t_log))))
// 		return (console(WARN, __func__, __LINE__, "malloc() failed").null);
// 	if (!init_log(self))
// 	{
// 		free(self);
// 		return (console(WARN, __func__, __LINE__, "init_log() failed").null);
// 	}
// 	return (self);
// }

// /*
// ** ADD LOG
// */

// // void	log_add(t_log *log)
// // {
// // 	t_log	*logs;

// // 	logs = get_curr_log();
	
// // }

// // void	open_log(const char *fn)
// // {
// // 	t_log *logs;
// // 	t_log *new;

// // 	if (find_log(fn))
// // 	if (!(new = init_new_log()))
// // 		console(WARN, __func__, __LINE__, "init_new_log() failed");
// // 	else
// // 		log_add(new);
// // }

// t_res	console_log(t_log_level lvl, const char *fn, int line, char *msg)
// {
// 	t_log *log;

// 	if (!(log = init_new_log()))
// 	{
// 		console(WARN, __func__, __LINE__, "init_new_log() failed");
// 		return (console(lvl, fn, line, msg));
// 	}
// 	log->lvl = lvl;
// 	log->fn = (char*)fn;
// 	log->line = line;
// 	log->msg = msg;
// 	// log_add(log);
// 	log_print_fd(log, 1);
// 	return (response());
// }