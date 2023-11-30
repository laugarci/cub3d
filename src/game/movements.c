/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:00 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 14:37:54 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_up(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx + \
		player->dirx * SPEED, player->posy))
		player->posx += player->dirx * SPEED;
	if (check_correct(cub->map, player->posx, \
		player->posy + player->diry * SPEED))
		player->posy += player->diry * SPEED;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	do_left(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx - player->diry * SPEED, \
			player->posy))
		player->posx -= player->diry * SPEED;
	if (check_correct(cub->map, player->posx, \
			player->posy + player->dirx * SPEED))
		player->posy += player->dirx * SPEED;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	do_down(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx - \
		player->dirx * SPEED, player->posy))
		player->posx -= player->dirx * SPEED;
	if (check_correct(cub->map, player->posx, \
		player->posy - player->diry * SPEED))
		player->posy -= player->diry * SPEED;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	do_right(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx + player->diry * SPEED, \
			player->posy))
		player->posx += player->diry * SPEED;
	if (check_correct(cub->map, player->posx, \
			player->posy - player->dirx * SPEED))
		player->posy -= player->dirx * SPEED;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

int	movements(int mov, t_win *wind)
{
	if (mov == ESC)
		close_window(wind);
	if (mov == UP)
		do_up(wind->player, wind->cub);
	if (mov == DOWN)
		do_down(wind->player, wind->cub);
	if (mov == LEFT)
		do_left(wind->player, wind->cub);
	if (mov == RIGHT)
		do_right(wind->player, wind->cub);
	if (mov == CAM_RIGHT)
		move_cam(wind->player, CAM_RIGHT);
	if (mov == CAM_LEFT)
		move_cam(wind->player, CAM_LEFT);
	return (0);
}
