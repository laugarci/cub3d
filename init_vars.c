/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:54:22 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/22 15:35:51 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player_pos(t_cub *cub, t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 11)
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0')
			{
				player->posx = i;
				player->posy = j;
				player->init_pos[0] = i;
				player->init_pos[1] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

void	find_dir_and_plane(t_cub *cub, t_player *player)
{
	if (cub->map[player->init_pos[0]][player->init_pos[1]] == 'N')
	{
		player->dirx = 0;
		player->diry = 1;
		player->planex = 0;
		player->planey = 0.66;
	}
	else if (cub->map[player->init_pos[0]][player->init_pos[1]] == 'S')
	{
		player->dirx = 0;
		player->diry = -1;
		player->planex = 0;
		player->planey = -0.66;
	}
	else if (cub->map[player->init_pos[0]][player->init_pos[1]] == 'E')
	{
		player->dirx = 1;
		player->diry = 0;
		player->planex = 0.66;
		player->planey = 0;
	}
	else if (cub->map[player->init_pos[0]][player->init_pos[1]] == 'W')
	{
		player->dirx = -1;
		player->diry = 0;
		player->planex = -0.66;
		player->planey = 0;
	}
}

void    init_vars(t_cub *cub, t_player *player)
{
	find_player_pos(cub, player);
	find_dir_and_plane(cub, player);
}
