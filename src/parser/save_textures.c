/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:00:18 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/28 13:14:54 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(t_win *wind, t_img *text)
{
	char *path;

    path = strdup("textures/img.xpm"); // no es pot utilitzar
    text->img = mlx_xpm_file_to_image(wind->mlx, \
			path, &text->width, &text->height);
    if (!text->img)
		return (1);
	if (text->width != 64 || text->height != 64)
		return (1);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, &text->line_len, &text->endian);
	if (!text->addr)
		return (1);
	return (0);
}

void	change_map(t_cub *cub)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;

	cub->map_aux = malloc (sizeof(char*) * cub->cols);
	cub->map_aux[cub->cols] = NULL;
	
	while (cols < cub->cols)
	{
		rows = 0;
		cub->map_aux[cols] = malloc (sizeof(char) * cub->rows);
		cub->map_aux[cols][cub->rows] = '\0';
		while (rows < cub->rows)
		{
			cub->map_aux[cols][rows] = cub->map[rows][cols];
			rows++;
		}
		cols++;
	}
}

void	save_textures(t_win *wind)
{
	int	i;
	change_map(wind->cub);
	i = 0;
	while (i < 4)
	{
		if (check_texture(wind, &wind->texture[i]))
			printf("la textura no esta ok\n");
		i++;
	}
}
