/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:56:13 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 12:50:14 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_cub *cub)
{
	cub->n = NULL;
	cub->s = NULL;
	cub->e = NULL;
	cub->w = NULL;
	cub->f = NULL;
	cub->c = NULL;
	cub->map = NULL;
	cub->rows = 0;
	cub->player = NULL;
}

void	free_file(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->all != NULL)
	{
		while(i < cub->total_len)
		{
			free(cub->all[i]);
			i++;
		}
		free(cub->all);
		cub->all = NULL;
	}
}

void	free_all(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->all != NULL)
		free_file(cub);
	if (cub->f != NULL)
		free(cub->f);
	if (cub->c != NULL)
		free(cub->c);
	if (cub->n != NULL)
		free(cub->n);
	if (cub->s != NULL)
		free(cub->s);
	if (cub->w != NULL)
		free(cub->w);
	if (cub->e != NULL)
		free(cub->e);
	if (cub->player != NULL)
		free(cub->player);
	if (cub->map != NULL)
	{
		i = 0;
		while(i < cub->rows)

		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
		cub->map = NULL;
	}
}
