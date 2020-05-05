/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 23:23:41 by ppetitea          #+#    #+#             */
/*   Updated: 2020/04/18 22:54:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "image/image.h"
#include "colors/color.h"
#include "ft/str.h"
#include "log/log.h"
#include <stdlib.h>

t_result	bmp_fill(int fd, t_image *bmp, t_u16 bpp)
{
	t_rgba			color;
	int				x;
	int				y;

	bpp /= 8;
	y = 0;
	while (y < bmp->height)
	{
		x = 0;
		while (x < bmp->width)
		{
			if (read(fd, &color, bpp) < 0)
				console(FATAL, __func__, __LINE__, "read fail");
			bmp->pixels[x + (bmp->height - y - 1) * bmp->width] = color.px;
			color.rgba.a = (bpp == 3) ? 255 : color.rgba.a;
			x++;
		}
		lseek(fd, (x * bpp) % 4, SEEK_CUR);
		y++;
	}
	return (OK);
}

t_result	bmp_parse(int fd, t_image *bmp)
{
	t_u32	offset;
	t_u16	bits_per_pixel;

	lseek(fd, sizeof(t_u16) * 4, SEEK_CUR);
	if (read(fd, &offset, sizeof(t_u32)) < 0)
		return (console(FATAL, __func__, __LINE__, "read fail").err);
	lseek(fd, sizeof(t_u32), SEEK_CUR);
	if (read(fd, &bmp->width, sizeof(t_i32)) < 0)
		return (console(FATAL, __func__, __LINE__, "read fail").err);
	if (read(fd, &bmp->height, sizeof(t_i32)) < 0)
		return (console(FATAL, __func__, __LINE__, "read fail").err);
	if (!(bmp->pixels = malloc(sizeof(t_u32) * bmp->width * bmp->height)))
		return (console(FATAL, __func__, __LINE__, "malloc fail").err);
	lseek(fd, sizeof(t_u16), SEEK_CUR);
	if (read(fd, &bits_per_pixel, sizeof(t_u16)) < 0)
		return (console(FATAL, __func__, __LINE__, "read fail").err);
	lseek(fd, offset, SEEK_SET);
	if (!bmp_fill(fd, bmp, bits_per_pixel))
		return (console(FATAL, __func__, __LINE__, "bmp_fill fail").err);
	return (OK);
}