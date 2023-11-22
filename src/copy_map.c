/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 10:55:20 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

char **copy_map(int init, t_cub *cub)
{
	int j;
	int i;
	int k;
	char **matrix;
	
	j = 0;
	i = 0;
	matrix = malloc(sizeof(char *) * (cub->rows - 6));
	while (i < (cub->rows - 6))
	{
		matrix[i] = malloc(sizeof(char) * (ft_strlen(cub->all[init]) + 1));
		k = 0;
		while (cub->all[init][k] && cub->all[init][k] != '\n')
		{
			matrix[i][k] = cub->all[init][k];
			k++;
		}
		matrix[i][k] = '\0'; 
		i++;
		init++;
	}
	return (matrix);
}
