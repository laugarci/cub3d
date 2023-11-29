/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:00:18 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/29 16:40:07 by laugarci         ###   ########.fr       */
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

void	apply_colors(t_cub *cub)
{
	cub->colors[0] = 0xFCE5CD;
	cub->colors[1] = 0xF9CB9C;
	cub->colors[2] = 0xF6B26B;
	cub->colors[3] = 0xE69138;
}

void	save_textures(t_win *wind)
{
	t_img	*text;
	int		i;

	i = 0;
	wind->cub->app_col = 0;
	while (i < 4)
	{
		text = &wind->texture[i];
		text->img = mlx_xpm_file_to_image(wind->mlx, find_path(wind->cub, i), \
			&text->width, &text->height);
		if (!text->img || text->width != IMAGE || text->height != IMAGE)
			wind->cub->app_col = 1;
		text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, \
			&text->line_len, &text->endian);
		if (!text->addr)
			wind->cub->app_col = 1;
		i++;
	}
	if (wind->cub->app_col == 1)
		apply_colors(wind->cub);
}
