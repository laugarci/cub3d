/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:00 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 15:29:38 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./mlx/mlx.h"

void	move_up(t_cub *cub)
{
	cub->map[cub->y][cub->x] = '0';
	cub->map[cub->y - 1][game->p_x] = 'P'; //Letra correspondiente
	cub->direction = 1;
}

void	move_down(t_cub *cub)
{
	cub->map[cub->y][cub->x] = '0';
	cub->map[cub->y + 1][cub->x] = 'P'; //letra correspondiente
	cub->direction = 0;
}

void	move_left(t_cub *cub)
{
	cub->map[cub->y][cub->x] = '0';
	cub->map[cub->y][cub->x - 1] = 'P'; //letra correspondiente
	cub->direction = 2;
}

void	move_right(t_cub *cub)
{
	cub->map[cub->y][cub->x] = '0';
	cub->map[cub->y][cub->x + 1] = 'P'; //letra correspondiente
	cub->direction = 3;
}

void	movements(int mov, t_cub *cub, t_player *player)
{
	if (mov == ESC)
		close_window(cub); //cerrar ventana
	if (mov == UP && cub->map[cub->y - 1][cub->x] != '1')
		move_up(cub);
	if (mov == LEFT && game->map[cub->y][cub->x - 1] != '1')
		move_left(cub);
	if (mov == DOWN && game->map[cub->y + 1][cub->x] != '1')
		move_down(cub);
	if (mov == RIGHT && game->map[cub->y][cub->x + 1] != '1')
		move_right(cub);
//	put_img(cub);
}
