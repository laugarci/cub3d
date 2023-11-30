/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:56:13 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 20:36:21 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_and_exit_errors(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

void	init_vars(t_cub *cub, t_player *player)
{
	cub->n = NULL;
	cub->s = NULL;
	cub->e = NULL;
	cub->w = NULL;
	cub->map = NULL;
	cub->rows = 0;
	cub->cols = 0;
	cub->f[0] = -1;
	cub->f[1] = -1;
	cub->f[2] = -1;
	cub->c[0] = -1;
	cub->c[1] = -1;
	cub->c[2] = -1;
	cub->player[0] = -1;
	cub->player[1] = -1;
	cub->app_col[0] = 0;
	cub->app_col[1] = 0;
	cub->app_col[2] = 0;
	cub->app_col[3] = 0;
	player->up = 0;
	player->down = 0;
	player->left = 0;
	player->right = 0;
	player->cam_left = 0;
	player->cam_right = 0;
}

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
