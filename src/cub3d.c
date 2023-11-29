/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:42:19 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/29 12:42:01 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info(t_cub *cub)
{
	printf("PATH NO: %s\nPATH SO: %s\nPATH WE: %s\nPATH EA: %s\n", cub->n, cub->s, cub->w, cub->e);
	printf("COLOR F: %d %d %d\nCOLOR C: %d %d %d\n", cub->f[0], cub->f[1], cub->f[2], cub->c[0], cub->c[1], cub->c[2]);
	printf("Player position: row: %d col: %d\n", cub->player[0], cub->player[1]);
	printf("Map has %d rows and %d cols\n", cub->rows, cub->cols);
	printf("Initial direction %c\n", cub->p);
	int i = 0;
	while (i < (cub->rows))
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub		cub;
	t_player	player;	

	if (ac != 2)
	{
		printf("Error: invalid arguments.\n");
		return (1);
	}
	check_arg(av);
	init_vars(&cub);
	open_map(av[1], &cub);
	parse_file(&cub);
	check_info(&cub);
	check_map(&cub, &player);
	check_paths(&cub);
	count_cols(&cub);
	print_info(&cub);
	game(&cub, &player);
	free_all(&cub);
	return (0);
}
