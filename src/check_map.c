/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 16:13:45 by laugarci         ###   ########.fr       */
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
	j = 0;
//	while (i < cub->rows)
//	{	
//		find_player(cub);

//	}
//		i++;
//	}
	cub = NULL;
}
