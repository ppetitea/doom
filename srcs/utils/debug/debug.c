/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:07:04 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/14 23:49:34 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"index.h"
#include	"libft.h"
#include	<stdio.h>
#include	<stdlib.h>

void	debug_bmp_header(t_bitmap_texture *bmp)
{
	printf("bpp %d\n", bmp->head.bits_per_pixel);
	printf("compression %d\n", bmp->head.compression);
	printf("img size %d\n", bmp->head.image_size_bytes);
	printf("x res %d\n", bmp->head.x_resolution_ppm);
	printf("y res %d\n", bmp->head.y_resolution_ppm);
	printf("planes %d\n", bmp->head.num_planes);
	printf("y %d\n", bmp->head.height);
	printf("x %d\n", bmp->head.width);
	printf("\n");
}

t_result	debug(t_game *game)
{
	static	t_bool			init = TRUE;
	static	t_bitmap_texture	*bmp;
	// static	t_texture			*texture1;
	// static	t_texture			*texture2;
	// static	t_texture			*texture3;
	// t_texture_args				args;
	
	if (init)
	{
		if (!(bmp = load_bmp("resources/textures/sprites/shoot/shoot5.bmp")))
			return (throw_error("initialize_images_list", "failed to load bmp"));
	
		// if (!(bmp = load_bmp("resources/textures/tmp/msi.bmp")))
		// 	return (throw_error("initialize_images_list", "failed to load bmp"));
		// if (!(bmp = load_bmp("resources/textures/tmp/msi.bmp")))
		// 	return (throw_error("debug", "failed to load bmp"));
		// args = texture_args("foo", ft_vec2i(100, 100), ft_usize(200, 200), -1);
		// texture1 = create_texture_with_bmp(args, *bmp);
		// args = texture_args("foo", ft_vec2i(150, 150), ft_usize(200, 200), -1);
		// texture2 = create_texture_with_bmp(args, *bmp);
		// args = texture_args("foo", ft_vec2i(0, 0), ft_usize(200, 200), -1);
		// texture3 = create_texture_with_bmp(args, *bmp);
		init = FALSE;
	}

	render_bmp(ft_vec2i(100, 100), game->interface.screen, *bmp);
	// render_bmp(ft_vec2i(0, 0), game->screen, *bmp);
	// render_texture(game->screen, texture1, ft_vec2i(0, 0));
	// render_texture(game->screen, texture2, ft_vec2i(0, 0));
	// render_texture(game->screen, texture3, ft_vec2i(0, 0));
	return (OK);
}
