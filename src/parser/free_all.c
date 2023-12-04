/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:18:13 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/04 20:19:45 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **matrix, int len)
{
	int	i;

	i = 0;
	if (matrix != NULL)
	{
		while (i < len)
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}

void	free_all(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->all != NULL)
		free_matrix(cub->all, cub->total_len);
	if (cub->n != NULL)
		free(cub->n);
	if (cub->s != NULL)
		free(cub->s);
	if (cub->w != NULL)
		free(cub->w);
	if (cub->e != NULL)
		free(cub->e);
	if (cub->map != NULL)
		free_matrix(cub->map, cub->rows);
}
