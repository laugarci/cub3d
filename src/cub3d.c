/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:42:19 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 10:14:34 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info(t_cub *cub)
{
	printf("PATH NO: %s\nPATH SO: %s\nPATH WE: %s\nPATH EA: %s\n", cub->n, cub->s, cub->w, cub->e);
	printf("COLOR F: %d %d %d\nCOLOR C: %d %d %d\n", cub->f[0], cub->f[1], cub->f[2], cub->c[0], cub->c[1], cub->c[2]);
	printf("Player position: row: %d col: %d\n", cub->player[0], cub->player[1]);
	
	int i = 0;
	while (i < (cub->rows))
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
	{
		printf("Error: invalid arguments.\n");
		return(1);
	}
	check_arg(av);
	init_vars(&cub);
	open_map(av[1], &cub);
	parse_file(&cub);
	check_info(&cub);
	check_map(&cub);
	check_paths(&cub);
	print_info(&cub);
	free_all(&cub);
	return (0);
}
