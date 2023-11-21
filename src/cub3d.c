/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:42:19 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 13:54:31 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_cub cub;

	if (ac == 2)
	{
		check_arg(av);
		open_map(av[1], &cub);
		int i = 0;
		while(i < 5)
		{
			printf("linea: %s\n", cub.map[i]);
			i++;
		}
	//	check_map(cub.map);
		init_vars(&cub);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
