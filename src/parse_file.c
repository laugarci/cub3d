/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:36:28 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 19:17:15 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		find_number(char *map, int del)
{
	char *tmp;
	int i;
	int num;

	i = 0;
	tmp = malloc(sizeof(char) * del + 1);
	while (i < del)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = '\0';
	num = ft_atoi(tmp);
	free(tmp);
	return (num);
}
int		*find_color(char *map)
{
	int *color;
	int i;
	int j;
	int c;
	int num;

	color = malloc(sizeof(int) * 3);
	i = 0;
	j = 0;
	num = 0;
	while (map[i])
	{
		if (map[i] == ',' || map[i] == ' ' || map[i] == '\t')
			i++;
		if (map[i] >= '0' && map[i] <= '9')
		{
			c = 0;
			while (map[i] && map[i] >= '0' && map[i] <= '9' && map[i] != ',' && map[i] != '\n')
			{
				c++;
				i++;
			}
			color[num] = find_number(&map[i - c], c);
			num++;
			if (num == 3)
				break ;
		}
			i++;
	}
	return (color);
}

void	parse_file(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(cub->all[i])
	{
		j = 0;
		while (cub->all[i][j])
		{
			if (cub->all[i][j] == 'F' && !ft_strncmp(cub->all[i], "F ", 2))
				cub->f = find_color(&cub->all[i][j]);
			if (cub->all[i][j] == 'C' && !ft_strncmp(cub->all[i], "C ", 2))
				cub->c = find_color(&cub->all[i][j]);
			j++;
		}
		i++;
	}
}
