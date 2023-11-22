/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 18:39:37 by laugarci         ###   ########.fr       */
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
	printf("rows: %d\n", cub->rows);
	while (i < cub->rows)
	{
		write(1, "entra\n", 6);
		j = 0;
		printf("aqui >> %s\n", cub->map[i]);
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'S' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				flag++;
				if (flag > 1)
				{
					printf("Too much players\n");
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
			if (i == 0 || (size_t)i == ft_strlen(cub->map[i]))
				if (check_one(cub->map[i]))
				{
					printf("1\n");
					invalid_map(cub);
				}
			if (i == cub->rows)
				if (check_one(cub->map[i]))
				{
					invalid_map(cub);
					printf("2\n");
				}
			if (j == 0 || cub->map[i][j + 1] == '\n')
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

void	check_map(t_cub *cub)
{
	write(1, "h\n", 2);
	find_player(cub);
	write(1, "1\n", 2);
	check_margin(cub);
	check_playable(cub);
}
