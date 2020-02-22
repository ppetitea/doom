/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:15:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/26 00:08:45 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/error.h"
#include "libft.h"

void	throw_warning(char *context, char *message, size_t tabs)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < tabs)
		{
			ft_putchar('\t');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
}

void	*throw_warning_null(char *context, char *message, size_t tabs)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < tabs)
		{
			ft_putchar('\t');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
	return (NULL);
}

t_result	throw_warning_error(char *context, char *message, size_t tabs)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < tabs)
		{
			ft_putchar('\t');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
	return (ERROR);
}

t_result	throw_warning_ok(char *context, char *message, size_t tabs)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < tabs)
		{
			ft_putchar('\t');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
	return (OK);
}

t_bool	throw_warning_false(char *context, char *message, size_t tabs)
{
	size_t	i;

	if (debug_mode(D_NONE))
	{
		i = 0;
		while (i < tabs)
		{
			ft_putchar('\t');
			i++;
		}
		ft_putstr(context);
		ft_putstr("\t");
		ft_putstr(message);
		ft_putchar('\n');
	}
	return (FALSE);
}
