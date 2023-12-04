/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:32 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:12:31 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	find_player_check(char c)
{
	if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	find_player(t_cub *cub)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < cub->rows)
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (find_player_check(cub->map[i][j]))
			{
				flag++;
				if (flag > 1)
					print_and_exit_errors("too much players");
				cub->player[0] = i;
				cub->player[1] = j;
				cub->p = cub->map[i][j];
				cub->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	check_margin(t_cub *cub)
{
	int	i;
	int	j;
	int	zero;

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
	int	i;
	int	j;
	int	zero;

	i = 0;
	zero = 0;
	while (i < cub->rows)
	{
		j = 0;
		while (cub->map[i][j])
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
