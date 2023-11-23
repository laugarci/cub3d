/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:33:31 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/23 15:50:23 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_win *wind)
{
	mlx_destroy_window(wind->mlx, wind->mlx_win);
	exit (0);
	return (0);
}

int	movements(int key, t_win *wind)
{
	if (key == ESC)
		close_window(wind);
	return (0);
}

void game(t_cub *cub, t_player *player)
{
	t_win wind;

	wind.wind_x = 1920;
	wind.wind_y = 1080;
	
	wind.mlx = mlx_init();
	wind.mlx_win = mlx_new_window(wind.mlx, wind.wind_x, wind.wind_y, "cub 3d besties");
//	wind.img = mlx_new_image(wind.mlx, wind.wind_x, wind.wind_y); //testing
//	wind.addr = mlx_get_data_addr(wind.img, &wind.bits_per_pixel, &wind.line_lenght, &wind.endian); //testing
	mlx_hook(wind.mlx_win, 17, 1L << 5, close_window, &wind);
	mlx_hook(wind.mlx_win, 2, 1L << 0, movements, &wind);
	render(&wind, cub, player);
	print_minimap(cub, &wind);

	mlx_loop(wind.mlx);
}
