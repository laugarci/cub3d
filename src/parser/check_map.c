/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 20:51:36 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	find_player(t_cub *cub)
{
	int	i;
	int	j;
	int flag;

	i = 0;
	flag = 0;
	while (i < cub->rows)
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'S' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				flag++;
				if (flag > 1)
				{
					printf("Error: too much players\n");
					exit(-1);
				}
				cub->player[0] = i;
				cub->player[1] = j;
				cub->p = cub->map[i][j];
				cub->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (flag > 1)
	{
		printf("Error: too much players\n");
		exit(-1);
	}
}

void	find_dir_player(t_cub *cub, t_player *player)
{
	player->posx = cub->player[0];
	player->posy = cub->player[1];

	if (cub->p == 'N')
	{
		player->dirx = 0;
		player->diry = 1;
		player->planex = 0;
		player->planey = 0.66;
	}
	else if (cub->p == 'S')
	{
		player->dirx = 0;
		player->diry = -1;
		player->planex = 0;
		player->planey = -0.66;
	}
	else if (cub->p == 'E')
	{
		player->dirx = 1;
		player->diry = 0;
		player->planex = 0.66;
		player->planey = 0;
	}
	else if (cub->p == 'W')
	{
		player->dirx = -1;
		player->diry = 0;
		player->planex = -0.66;
		player->planey = 0;
	}
}

void	check_margin(t_cub *cub)
{
	int i;
	int j;
	int zero;

	i = 0;
	zero = 0;
	while (i < cub->rows)
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (i == 0 || i == (cub->rows - 1))
				if (check_one(cub->map[i]))
					invalid_map(cub);
			if (i == (cub->rows - 1))
				if (check_one(cub->map[i]))
					invalid_map(cub);
			if (j == 0 || ((size_t)j + 1) == ft_strlen(cub->map[i]))
				if (check_char(cub->map[i][j]))
					invalid_map(cub);
			j++;
		}
		i++;
	}
}

void	check_playable(t_cub *cub)
{
	int i;
	int j;
	int zero;

	i = 0;
	zero = 0;
	while (i < cub->rows)
	{
		j = 0;
		while(cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
				zero = 1;
			j++;
		}
		i++;
	}
	if (zero == 0)
		invalid_map(cub);
}

void	check_map(t_cub *cub, t_player *player)
{
	find_player(cub);
	find_dir_player(cub, player);
	if (check_player(cub))
	{
		printf("Error: player needed.\n");
		free_all(cub);
		exit(-1);
	}
	check_margin(cub);
	check_playable(cub);
}
