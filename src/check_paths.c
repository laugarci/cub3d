/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:24:07 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 10:14:32 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	check_xpm(char *str)
{
	int len;

	len = ft_strlen(str);
	if (ft_strncmp(str + len - 4, ".xpm", 4))
	{
		printf("Error: invalid path for img\n");
		exit(-1);
	}
}

void	check_paths(t_cub *cub)
{
	check_xpm(cub->n);
	check_xpm(cub->s);
	check_xpm(cub->e);
	check_xpm(cub->w);
}
