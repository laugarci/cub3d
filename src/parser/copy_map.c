/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/29 14:34:23 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

char	**copy_map(int init, t_cub *cub)
{
	int		i;
	int		k;
	char	**matrix;

	i = 0;
	matrix = malloc(sizeof(char *) * cub->rows);
	while (i < cub->rows)
	{
		matrix[i] = malloc(sizeof(char) * (ft_strlen(cub->all[init]) + 1));
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
		matrix[i][k] = '\0';
		i++;
		init++;
	}
	return (matrix);
}

void	count_cols(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < cub->rows)
	{
		j = 0;
		while (cub->map[i][j])
			j++;
		if (j > count)
			count = j;
		i++;
	}
	cub->cols = count;
}
