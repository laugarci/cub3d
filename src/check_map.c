/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 12:56:05 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player(t_cub *cub)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub->rows)
	{
		while (cub->map[i][j] != '\n')
		{
			if (cub->map[i][j] == 'S' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				cub->player = malloc(sizeof(int) * 2);
				if (!cub->player)
				{
					printf("Malloc error\n");
					exit(-1);
				}
				cub->player[0] = i;
				cub->player[1] = j;
			}
			j++;
		}
		i++;
	}
}



void	check_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	find_player(cub);
	while (i < cub->rows)
	{
		j = 0;
		while(cub->map[i][j])
		{
			if (i == 0 || i == (cub->rows - 1))
				check_one(cub->map[i]); //checks retornan int
			if (j == 0)
				check_char(cub->map[i][j]);
			if (cub->map[i][j + 1] == '\n')
				check_char(cub->map[i][j]);
			j++;
		}
		i++;
	}
}