/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:25 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/01 11:39:58 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_win *wind, int x, int y, int color)
{
	unsigned int	*img;

	img = (unsigned int *)wind->image.addr;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		img[x + WIDTH * y] = color;
}

int	check_correct(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

int	rgb_to_hex(int r, int g, int b)
{
	unsigned int	hexa;

	hexa = (r << 16) | (g << 8) | b;
	return (hexa);
}
