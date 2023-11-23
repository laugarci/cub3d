/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:00 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 17:22:14 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_player *player, int x)
{
	player->posx = x - 1;
}

void	move_down(t_player *player,  int x)
{
	player->posx = x + 1;
}

void	move_left(t_player *player, int y)
{
	player->posy = y - 1;
}

void	move_right(t_player *player, int y)
{
	player->posy = y + 1;
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
		move_up( wind->player, x);
	if (mov == LEFT && wind->cub->map[x][y - 1] != '1')
		move_left(wind->player, y);
	if (mov == DOWN && wind->cub->map[x + 1][y] != '1')
		move_down(wind->player, x);
	if (mov == RIGHT && wind->cub->map[x][y + 1] != '1')
		move_right(wind->player, y);
	render(wind, wind->cub, wind->player);
	return (0);
}
