/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 23:23:33 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/07 14:58:53 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "types.h"

/*
**	Gestion des erreurs
**
**	Quitte la fonction en retournant la valeur adaptee ERROR | NULL | void
**	print un message d'erreur de type :
**	"nom_de_la_fonction()", "description de l'erreur"
**
*/

// typedef enum			e_error_type
// {
// 	WARNING,
// 	FATAL
// }						t_error_type;

typedef enum			e_debug_flag
{
	D_START,
	D_NONE,
	D_STOP,
}						t_debug_flag;

t_bool		debug_mode(t_debug_flag flag);
t_result	throw_debug_ok(char *location, char *message, size_t ret);
void		throw_debug(char *location, char *message, size_t ret);
t_result	throw_error(char *location, char *message);
void		*throw_null(char *location, char *message);
void		throw_void(char *location, char *message);
void		throw_warning(char *location, char *message, size_t tabs);
t_result	throw_warning_error(char *location, char *message, size_t tabs);
t_result	throw_warning_ok(char *location, char *message, size_t tabs);
t_bool		throw_warning_false(char *location, char *message, size_t tabs);
void		*throw_warning_null(char *location, char *message, size_t tabs);

#endif