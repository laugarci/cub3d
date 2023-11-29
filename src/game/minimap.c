/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:13:11 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/29 12:14:16 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_minimap_aux(t_win *wind, int x, int y, int color)
{
	int	j;
	int	k;
	int	size;

	size = 8;
	if (wind->cub->rows * wind->cub->cols > 1500)
		size = 4;
	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			my_mlx_pixel_put(wind, k + (x * size) + 10, \
				j + (y * size) + 10, color);
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

	y = 0;
	while (y < cub->rows)
	{
		if (!cub->map[y])
			break ;
		x = 0;
		while (x < cub->cols)
		{
			if (cub->map[y][x] == '1')
				print_minimap_aux(wind, x, y, 0xFFFFFF);
			print_minimap_aux(wind, (int)wind->player->posx, \
				(int)wind->player->posy, 0xFF00FF);
			x++;
		}
		y++;
	}
}
