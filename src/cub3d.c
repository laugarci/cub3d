/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:42:19 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 20:22:29 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	init_vars(&cub, &player);
	open_map(av[1], &cub);
	parse_file(&cub);
	check_info(&cub);
	check_map(&cub, &player);
	check_paths(&cub);
	check_paths_to_img(&cub);
	count_cols(&cub);
	game(&cub, &player);
	free_all(&cub);
	return (0);
}
