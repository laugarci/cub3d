/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 14:12:29 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	find_player(t_cub *cub)
{
	int	i;
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

int	check_one(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			flag = 1;
		i++;
	}
	return (flag);
}

int	check_char(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

void	invalid_map(t_cub *cub)
{
	printf("Invalid map\n");
	free_all(cub);
	exit(-1);
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
		while (cub->map[i][j])
		{
			if (i == 0 || i == (cub->rows - 1))
				if (check_one(cub->map[i]))
					invalid_map(cub);
			if (j == 0)
				if (check_char(cub->map[i][j]))
					invalid_map(cub);
			if (cub->map[i][j + 1] == '\n')
				if (check_char(cub->map[i][j]))
					invalid_map(cub);
			j++;
		}
		i++;
	}
}
