/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:55:48 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/29 15:10:25 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	nord_position(t_player *player)
{
	player->dirx = 0;
	player->diry = -1;
	player->planex = 0.66;
	player->planey = 0;
}

void	sud_position(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = -0.66;
	player->planey = 0;
}

void	east_position(t_player *player)
{
	player->dirx = 1;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0.66;
}

void	west_position(t_player *player)
{
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0;
	player->planey = -0.66;
}

void	find_dir_player(t_cub *cub, t_player *player)
{
	player->posx = cub->player[1] + 0.5;
	player->posy = cub->player[0] + 0.5;
	if (cub->p == 'N')
		nord_position(player);
	else if (cub->p == 'S')
		sud_position(player);
	else if (cub->p == 'E')
		east_position(player);
	else if (cub->p == 'W')
		west_position(player);
}
