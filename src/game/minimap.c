/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:13:11 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 16:01:01 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_minimap_aux(t_cub *cub, t_win *wind, int x, int y, int color)
{
	int	j;
	int	k;
	int	size;

	size = 8;
	if (cub->rows * cub->cols > 1500)
		size = 4;
	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			my_mlx_pixel_put(wind->img, k + (x * size) + 10, j + (y * size) + 10, color);
			k++;
		}
		j++;
	}
}
void	print_minimap(t_cub *cub, t_win *wind)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->rows)
	{
		if (!cub->map[x][y])
			break ;
		x = 0;
		while (x < cub->cols)
		{
			if (cub->map[y][x] == '1')
				print_minimap_aux(cub, wind, x, y, 0x00ffffff);
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'W'
			|| cub->map[y][x] == 'E' || cub->map[y][x] == 'S')
				print_minimap_aux(cub, wind, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
