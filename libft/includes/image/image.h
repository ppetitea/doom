/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 19:39:10 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/25 23:05:20 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "containers/list.h"
# include "image/image.h"
# include "types.h"

typedef struct	s_image
{
	t_list_head	node;
	char		*name;
	int			width;
	int			height;
	t_u32		*pixels;
}				t_image;

/*
** INIT IMAGE
*/

t_result	init_image(t_image *self);

t_image		*init_new_image();

/*
** DELETE IMAGE
*/

t_result	del_image(t_image *self);

/*
** PARSE IMAGE
*/

t_image		*image_parse(char *path, char *name);

/*
** FIND IMAGE
*/

t_image		*image_find(t_list_head *list, char *name);


/*
** BITMAP
*/
t_result	bmp_fill(int fd, t_image *bmp, t_u16 bpp);

t_result	bmp_parse(int fd, t_image *bmp);


#endif
