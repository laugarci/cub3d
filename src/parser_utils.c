/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:56:13 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 15:38:07 by laugarci         ###   ########.fr       */
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

void	free_map(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->rows)
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
}
