/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 02:40:52 by ppetitea          #+#    #+#             */
/*   Updated: 2020/05/02 17:39:35 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "types.h"

/*
**	Gestion des format d'encodage des pixels
**
**	les fichiers bitmap encode les couleurs en [Blue Green Red] en 24bpp
**	je crois que la SDL encode en [Blue Green Red Alpha] en uint32
**
**	Utilisation des unions: (voir plus bas)
**
**	Les unions sont des struct speciales ou chaque variable pointe en memoire 
**	l'adresse de la structure. Ce qui permet d'acceder a la memoire en fonction 
**	de la taille de la variable utilisee.
**
*/

typedef struct		s_rgba_uchar
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_rgba_uchar;

typedef union		u_rgba
{
	t_rgba_uchar	rgba;
	t_u32			px;
}					t_rgba;

typedef struct		s_bgra_uchar
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_bgra_uchar;

typedef union		u_bgra
{
	t_bgra_uchar	bgra;
	t_u32			px;
}					t_bgra;

t_u32	blend_add(t_rgba current, t_rgba old);
t_u32	blend_add_average(t_rgba current, t_rgba old);

t_bgra ft_bgra(char r, char g, char b, char a);
t_rgba ft_rgba(char r, char g, char b, char a);

#endif