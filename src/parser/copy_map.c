/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/04 12:41:41 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	copy_map_aux(int k, int i, t_cub *cub, char **matrix)
{
	if (k < cub->cols)
	{
		while (k <= cub->cols)
		{
			matrix[i][k] = '1';
			k++;
		}
	}
	matrix[i][k] = '\0';
}

char	**copy_map(int init, t_cub *cub)
{
	int		i;
	int		k;
	char	**matrix;

	i = 0;
	matrix = malloc(sizeof(char *) * cub->rows);
	while (i < cub->rows)
	{
		matrix[i] = malloc(sizeof(char) * (cub->cols + 1));
		k = 0;
		if (cub->all[init][0] == '\n')
			break ;
		while (cub->all[init][k] && cub->all[init][k] != '\n')
		{
			if (cub->all[init][k] == ' ')
				matrix[i][k] = '1';
			else
				matrix[i][k] = cub->all[init][k];
			k++;
		}
		copy_map_aux(k, i, cub, matrix);
		i++;
		init++;
	}
	return (matrix);
}
