/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:33:31 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/26 20:10:48 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_win *wind)
{
	mlx_destroy_window(wind->mlx, wind->mlx_win);
	exit (0);
	return (0);
}

void game(t_cub *cub, t_player *player)
{
	t_win wind;

	wind.player = player;
	wind.cub = cub;
	wind.image.width = WIDTH;
	wind.image.height = HEIGHT;
	wind.mlx = mlx_init();
	wind.mlx_win = mlx_new_window(wind.mlx, wind.image.width, wind.image.height, "cub 3d besties");
	save_textures(&wind);
	mlx_hook(wind.mlx_win, 2, 1L << 0, movements, &wind);
	mlx_hook(wind.mlx_win, 17, 1L << 5, close_window, &wind);
	render(&wind);
	//print_minimap(cub, &wind);
	mlx_loop(wind.mlx);
}
