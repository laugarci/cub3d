/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:13:11 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/27 18:42:52 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_minimap_aux(t_cub *cub, t_win *wind, int x, int y, int color)
{
	int	j;
	int	k;
	int	size;

	(void)cub;
	size = 20;
	//if (cub->rows * cub->cols > 1500)
		//size = 4;
	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			my_mlx_pixel_put(wind, j + (x * size), \
				k + (y * size), color);
			k++;
		}
		j++;
	}
}

int	check_dec(float x, float y)
{
	if (x - (int)x != 0 || y - (int)y != 0)
		return (1);
	return (0);
}




void	print_minimap(t_cub *cub, t_win *wind)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < cub->cols)
	{
		//if (!cub->map[y])
			//break ;
		
		y = 0;
		while (y < cub->rows)
		{
			if (cub->map_aux[x][y] == '1')
				print_minimap_aux(cub, wind, x, y, 0xFF00FF);
			/*if (cub->map_aux[x][y] == 'N' || cub->map_aux[x][y] == 'W'
			|| cub->map_aux[x][y] == 'E' || cub->map_aux[x][y] == 'S')
				print_minimap_aux(cub, wind, wind->player->posy, \
					wind->player->posx, 0xFF00FF);*/
			y++;
		}
		x++;
	}

	printf("posx %f, posy %f\n", wind->player->posx, wind->player->posy);
	//print_minimap_aux(cub, wind, (int)wind->player->posx, (int)wind->player->posy, 0x00FFFF);
	//my_mlx_pixel_put(wind, (int)(wind->player->posx * 8), (int)(wind->player->posy * 8), 0x00FFFF);
}
