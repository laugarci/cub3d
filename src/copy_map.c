/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 22:26:09 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

#include <stdlib.h>

char	**allocate_matrix(char *map, int rows)
{
	char **matrix;
	int	i;
	int j;
	int c;

	matrix = malloc(sizeof(char *) * rows);
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	c = 0;
	while(j < rows)
	{
		if (map[i] == '\n')
		{
			i++;
			c = i - c;		
			matrix[j] = malloc(sizeof(char) * (c + 1));
			j++;
		}
		i++;
	}
	return (matrix);
}

char **copy_map(char *map, t_cub *cub)
{
	int i;
	int j;
	int c;
	char **matrix;

	matrix = allocate_matrix(map, cub->rows);
	i = 0;
	j = 0;
	while(j < cub->rows)
	{
		c = 0;
		while(map[i] != '\n' && map[i])
		{
			matrix[j][c] = map[i];
			c++;
			i++;
		}
		if (map[i] == '\n')
		{
			matrix[j][c] = map[i];
			c++;
			i++;
		}
		matrix[j][c] = '\0';
		c++;
		j++;
	}
	return (matrix);
}

