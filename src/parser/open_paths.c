/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:37:07 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 12:07:34 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_path(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	check_paths_to_img(t_cub *cub)
{
	if (open_path(cub->n))
		cub->app_col[0] = 1;
	if (open_path(cub->s))
		cub->app_col[1] = 1;
	if (open_path(cub->e))
		cub->app_col[2] = 1;
	if (open_path(cub->w))
		cub->app_col[3] = 1;
}
