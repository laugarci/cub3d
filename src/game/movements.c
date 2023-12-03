/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:23:00 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/03 19:20:57 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_up(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx + \
		player->dirx * player->speed, player->posy))
		player->posx += player->dirx * player->speed;
	if (check_correct(cub->map, player->posx, \
		player->posy + player->diry * player->speed))
		player->posy += player->diry * player->speed;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	do_right(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx - \
		player->diry * player->speed, player->posy))
		player->posx -= player->diry * player->speed;
	if (check_correct(cub->map, player->posx, \
			player->posy + player->dirx * player->speed))
		player->posy += player->dirx * player->speed;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	do_down(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx - \
		player->dirx * player->speed, player->posy))
		player->posx -= player->dirx * player->speed;
	if (check_correct(cub->map, player->posx, \
		player->posy + WALL_SPACE - player->diry * player->speed))
		player->posy -= player->diry * player->speed;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	do_left(t_player *player, t_cub *cub)
{
	if (check_correct(cub->map, player->posx + \
		player->diry * player->speed, player->posy))
		player->posx += player->diry * player->speed;
	if (check_correct(cub->map, player->posx, \
			player->posy - player->dirx * player->speed))
		player->posy -= player->dirx * player->speed;
	if (player->direction == 1)
		player->direction = 2;
	else
		player->direction = 1;
}

void	move(t_win *wind)
{
	if (wind->player->up)
		do_up(wind->player, wind->cub);
	if (wind->player->down)
		do_down(wind->player, wind->cub);
	if (wind->player->left)
		do_right(wind->player, wind->cub);
	if (wind->player->right)
		do_left(wind->player, wind->cub);
}
