/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:59:43 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/24 11:33:21 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_cam_left(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = 0;
	player->planey += 0.1;
}

void	move_cam_right(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = 0;
	player->planey -= 0.1;
}
