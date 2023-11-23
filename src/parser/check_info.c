/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:00:06 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 12:34:27 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	check_player(t_cub *cub)
{
	if (cub->player[0] == -1 && cub->player[1] == -1)
		return(1);
	return(0);
}

int	check_nums(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (cub->f[i] < 0 || cub->f[i] > 255)
			return (1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (cub->c[i] < 0 || cub->c[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

void	check_info(t_cub *cub)
{
	if (cub->w == NULL || cub->e == NULL || cub->n == NULL || cub->s == NULL)
	{
		printf("Error: map texture information is missing.\n");
		free_all(cub);
		exit(-1);
	}
	else if (check_nums(cub))
	{
		printf("Error: Floor and/or sky colors are missing or invalid.\n");
		free_all(cub);
		exit(-1);
	}
	else if (cub->map == NULL)
	{
		printf("Error: map not found.\n");
		free_all(cub);
		exit(-1);
	}
}
