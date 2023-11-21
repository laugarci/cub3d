/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:42:19 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 11:43:07 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_cub cub;

	if (ac == 2)
	{
		check_arg(av[1]);
		check_map(av[1]);
		init_vars(&cub);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
