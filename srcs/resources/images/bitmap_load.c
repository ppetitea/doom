/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:36:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/02/27 16:15:08 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "resources/images.h"
#include "utils/parser.h"
#include "utils/error.h"
#include "utils/color.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_image
{
	int				width;
	int				height;
	t_u32			*pixels;
}					t_image;

typedef union		u_type
{
	t_i8			i8;
	t_i16			i16;
	t_i32			i32;
	t_i64			i64;
	t_u8			u8;
	t_u16			u16;
	t_u32			u32;
	t_u64			u64;
}					t_type;

// static t_result		fill_pixels(FILE *file, t_u32 *pixels,
// 						t_image_header	*head)
// {
// 	int				bpp;
// 	t_rgba			color;
// 	int32_t			x;
// 	int32_t			y;

// 	bpp = head->bits_per_pixel / 8;
// 	if (file == NULL || pixels == NULL)
// 		return (throw_error("fill_pixels", "NULL pointer provided"));
// 	y = 0;
// 	while (y < head->height)
// 	{
// 		x = 0;
// 		while (x < head->width)
// 		{
// 			fread(&color, 1, bpp, file);
// 			pixels[x + (head->height - y - 1) * head->width] = color.px;
// 			color.rgba.a = (bpp == 3) ? 255 : color.rgba.a;
// 			x++;
// 		}
// 		fseek(file, (x * bpp) % 4, SEEK_CUR);
// 		y++;
// 	}
// 	return (OK);
// }

t_image	*load_img(char *path)
{
	int			fd;
	t_image		*img;
	t_u16		magic_id;

	if (path == NULL)
		return (throw_null("load_img", "NULL pointer provided"));
	if (!(img = (t_image*)malloc(sizeof(t_image))))
		return (throw_null("load_img", "img texture -> malloc failed"));
	if ((fd = open(path, O_RDONLY)) < 1)
		return (throw_null("load_img", "wrong path provided"));
	read(fd, 2, &magic_id);
	if (magic_id != 0x4d42)
		return (throw_null("load_img", "file provided is not a img"));
	// if (!(img->pixels = (t_u32*)malloc(sizeof(t_u32)
	// 	* img->head.width * img->head.height)))
	// 	return (throw_null("load_img", "pixels array -> malloc failed"));
	// if (!(fill_pixels(file, img->pixels, &img->head)))
	// 	return (throw_null("load_img", "img_to_pixel_array failed"));
	return (img);
}
