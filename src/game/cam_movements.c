/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:59:43 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 20:30:54 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_cam_left(t_player *player, float olddirx, float oldplanex)
{
	player->dirx = player->dirx * cos(TURN) - player->diry * sin(TURN);
	player->diry = olddirx * sin(TURN) + player->diry * cos(TURN);
	player->planex = player->planex * cos(TURN) - player->planey * sin(TURN);
	player->planey = oldplanex * sin(TURN) + player->planey * cos(TURN);
}

void	move_cam_right(t_player *player, float olddirx, float oldplanex)
{
	player->dirx = player->dirx * cos(-TURN) - player->diry * sin(-TURN);
	player->diry = olddirx * sin(-TURN) + player->diry * cos(-TURN);
	player->planex = player->planex * cos(-TURN) - player->planey * sin(-TURN);
	player->planey = oldplanex * sin(-TURN) + player->planey * cos(-TURN);
}

void	move_cam(t_player *player)
{
	float	olddirx;
	float	oldplanex;

	olddirx = player->dirx;
	oldplanex = player->planex;
	if (player->cam_left)
		move_cam_left(player, olddirx, oldplanex);
	if (player->cam_right)
		move_cam_right(player, olddirx, oldplanex);
}
