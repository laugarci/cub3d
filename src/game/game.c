/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:33:31 by julolle-          #+#    #+#             */
/*   Updated: 2023/12/03 19:35:23 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_win *wind)
{
	mlx_destroy_window(wind->mlx, wind->mlx_win);
	free_all(wind->cub);
	exit (0);
	return (0);
}

void	game(t_cub *cub, t_player *player)
{
	t_win	wind;

	player->direction = 1;
	player->speed = SPEED;
	wind.player = player;
	wind.cub = cub;
	wind.image.width = WIDTH;
	wind.image.height = HEIGHT;
	wind.mlx = mlx_init();
	wind.mlx_win = mlx_new_window(wind.mlx, WIDTH, HEIGHT, "cub 3d besties");
	wind.image.img = mlx_new_image(wind.mlx, WIDTH, HEIGHT);
	wind.image.addr = mlx_get_data_addr(wind.image.img, \
		&(wind.image.bits_per_pixel), &(wind.image.line_len), \
		&(wind.image.endian));
	save_images(&wind);
	mlx_mouse_move(wind.mlx_win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(wind.mlx_win, 2, 1L << 0, movements, &wind);
	mlx_hook(wind.mlx_win, 3, 1L << 0, stop_movement, &wind);
	mlx_hook(wind.mlx_win, 17, 1L << 5, close_window, &wind);
	render(&wind);
	mlx_loop_hook(wind.mlx, render, &wind);
	mlx_loop(wind.mlx);
}
