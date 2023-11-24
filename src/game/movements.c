/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:00 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/24 12:31:16 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_player *player, t_cub *cub, int x, int y)
{
//	cub->map[x][y] = '0';
//	cub->map[x - 1][y] = cub->p;
	player->posx = x - 1;
	(void)y;
	(void)cub;
}

void	move_down(t_player *player, t_cub *cub, int x, int y)
{
//	cub->map[x][y] = '0';
//	cub->map[x + 1][y] = cub->p;
	player->posx = x + 1;
	(void)y;
	(void)cub;
}

void	move_left(t_player *player, t_cub *cub, int x, int y)
{
//	cub->map[x][y] = '0';
//	cub->map[x][y - 1] = cub->p;
	player->posy = y - 1;
	(void)x;
	(void)cub;
}

void	move_right(t_player *player, t_cub *cub, int x, int y)
{
//	cub->map[x][y] = '0';
//	cub->map[x][y + 1] = cub->p;
	player->posy = y + 1;
	(void)x;
	(void)cub;
}

int	movements(int mov, t_win *wind)
{
	int x;
	int y;

	x = wind->player->posx;
	y = wind->player->posy;
	if (mov == ESC)
		close_window(wind);
	if (mov == UP && wind->cub->map[x - 1][y] != '1')
		move_up(wind->player, wind->cub, x, y);
	if (mov == LEFT && wind->cub->map[x][y - 1] != '1')
		move_left(wind->player, wind->cub, x, y);
	if (mov == DOWN && wind->cub->map[x + 1][y] != '1')
		move_down(wind->player, wind->cub, x, y);
	if (mov == RIGHT && wind->cub->map[x][y + 1] != '1')
		move_right(wind->player, wind->cub, x, y);
	if (mov == CAM_RIGHT)
		move_cam_right(wind->player);
	if (mov == CAM_LEFT)
		move_cam_left(wind->player);
	render(wind);
//	print_minimap(wind->cub, wind);
	return (0);
}
