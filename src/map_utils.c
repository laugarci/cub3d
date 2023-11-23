/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:46:14 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 20:21:23 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	check_one(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			flag = 1;
		i++;
	}
	return (flag);
}

int	check_char(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

void	invalid_map(t_cub *cub)
{
	printf("Error: invalid map\n");
	free_all(cub);
	exit(-1);
}
