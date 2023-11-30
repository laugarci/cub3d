/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:45:51 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 14:05:32 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_player *player, t_win *wind)
{
	int pxl;

	pxl = 68;
	if (player->direction == 0)
		player->file = mlx_xpm_file_to_image(wind->mlx,
				"./sprites/down.xpm", &pxl, &pxl);
	else if (player->direction == 1)
		player->file = mlx_xpm_file_to_image(wind->mlx,
				"./sprites/up.xpm", &pxl, &pxl);
	else if (player->direction == 2)
		player->file = mlx_xpm_file_to_image(wind->mlx,
				"./sprites/left.xpm", &pxl, &pxl);
	else if (player->direction == 3)
		player->file = mlx_xpm_file_to_image(wind->mlx,
				"./sprites/right.xpm", &pxl, &pxl);
	mlx_put_image_to_window(wind->mlx, wind->mlx_win,
		player->file, (pxl * HEIGHT), (pxl * (WIDTH / 2)));
}
