/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:15:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 00:09:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "libft.h"

t_bool	debug_mode(t_debug_flag flag)
{
	static t_bool debug = FALSE;

	if (flag == D_START)
		debug = TRUE;
	else if (flag == D_STOP)
		debug = FALSE;
	return (debug);
}

t_result	throw_debug_ok(char *context, char *message, size_t ret)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < ret)
		{
			ft_putchar('\n');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
	return (OK);
}

void	throw_debug(char *context, char *message, size_t ret)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < ret)
		{
			ft_putchar('\n');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
}
