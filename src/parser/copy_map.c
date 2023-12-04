/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/04 15:47:14 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	copy_map_aux(int k, int i, t_cub *cub, char **matrix)
{
	if (k < cub->cols)
	{
		while (k < (cub->cols - 1))
		{
			matrix[i][k] = '1';
			k++;
		}
	}
	matrix[i][k] = '\0';
}

void	copy_map(int init, t_cub *cub)
{
	int		i;
	int		k;

	i = 0;
	cub->map = malloc(sizeof(char *) * cub->rows);
	if (!cub->map)
		exit(1);
	while (i < cub->rows)
	{
		cub->map[i] = malloc(sizeof(char) * (cub->cols + 1));
		k = 0;
		if (cub->all[init][0] == '\n' || cub->map[i] == NULL)
			break ;
		while (k < (int)ft_strlen(cub->all[init]))
		{
			if (cub->all[init][k] == ' ')
				cub->map[i][k] = '1';
			else
				cub->map[i][k] = cub->all[init][k];
			k++;
		}
		copy_map_aux(k, i, cub, cub->map);
		i++;
		init++;
	}
}
