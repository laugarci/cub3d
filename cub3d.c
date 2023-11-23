/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:42:19 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 15:58:19 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void printf_mat(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 11)
		{
			printf("%c", cub->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	cub->f = malloc (sizeof(int) * 4);
	cub->f[0] = 255;
	cub->f[1] = 0;
	cub->f[2] = 0;

	cub->c = malloc (sizeof(int) * 4);
	cub->c[0] = 0;
	cub->c[1] = 255;
	cub->c[2] = 0;

	cub->map = malloc (sizeof(char *) * 8);
	cub->map[7] = NULL;
	while (i < 8)
	{
		cub->map[i] = malloc (sizeof(char) * 11);
		cub->map[i][10] = '\0';
		j = 0;
		while (j < 11)
		{
			if (i == 5 && j == 1)
				cub->map[i][j] = 'N';
			else if (i == 0 || i == 7)
				cub->map[i][j] = '1';
			else if (j == 0 || j == 10)
				cub->map[i][j] = '1';
			else if (i == 2 && (j == 3 || j == 4))
				cub->map[i][j] = '1';
			else if (i == 3 && (j == 3 || j == 4))
				cub->map[i][j] = '1';
			else
				cub->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub		cub;
	t_player	player;	
	
	(void)av;
	(void)ac;
	init_map(&cub);
	init_vars(&cub, &player);
	game(&cub, &player);
	return (0);
}
