/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:00:18 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/30 15:05:39 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*find_path(t_cub *cub, int i)
{
	char	*path;

	if (i == 0)
		path = cub->n;
	else if (i == 1)
		path = cub->s;
	else if (i == 2)
		path = cub->e;
	else
		path = cub->w;
	return (path);
}

void	init_text_colors(t_cub *cub)
{
	cub->colors[0] = 0xFCE5CD;
	cub->colors[1] = 0xF9CB9C;
	cub->colors[2] = 0xF6B26B;
	cub->colors[3] = 0xE69138;
}

void	save_sprite_char(t_win *wind, t_player *player)
{
	int pxl;
	
	player->file[0] = mlx_xpm_file_to_image(wind->mlx, \
		"./sprites/char_N_1.xpm", &pxl, &pxl);
	player->file[1] = mlx_xpm_file_to_image(wind->mlx, \
		"./sprites/char_N_2.xpm", &pxl, &pxl);
}

void	save_images(t_win *wind)
{
	t_img	*text;
	int		i;

	i = 0;
	init_text_colors(wind->cub);
	save_sprite_char(wind, wind->player);
	while (i < 4)
	{
		if (wind->cub->app_col[i] != 1)
		{
			text = &wind->texture[i];
			text->img = mlx_xpm_file_to_image(wind->mlx, find_path(wind->cub, i), \
				&text->width, &text->height);
			if (!text->img || text->width != IMAGE || text->height != IMAGE)
				wind->cub->app_col[i] = 1;
			text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, \
				&text->line_len, &text->endian);
			if (!text->addr)
				wind->cub->app_col[i] = 1;
		}
		i++;
	}
}
