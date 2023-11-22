/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:36:28 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 12:33:54 by laugarci         ###   ########.fr       */
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
	int c;
	int num;

	color = malloc(sizeof(int) * 3);
	i = 0;
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

int		check_nums(t_cub *cub)
{
	int i;

	i = 0;
	while(i < 3)
	{
		if (cub->f[i] < 0 || cub->f[i] > 255)
			return (1);
		i++;
	}
	i = 0;
	while(i < 3)
	{
		if (cub->c[i] < 0 || cub->c[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

void	check_info(t_cub *cub)
{
	if (cub->w == NULL || cub->e == NULL || cub->n == NULL || cub->s == NULL)
	{
		printf("Error: map texture information is missing.\n");
		free_all(cub);
		exit(-1);
	}
	else if (cub->f == NULL || cub->c == NULL || check_nums(cub))
	{
		printf("Error: Floor and/or sky colors are missing or invalid.\n");
		free_all(cub);
		exit(-1);
	}
	else if (cub->map == NULL)
	{
		printf("Error: map not found.\n");
		free_all(cub);
		exit(-1);
	}
}
void	parse_file(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (cub->all[i])
	{
		j = 0;
		while (cub->all[i][j])
		{
			if (cub->all[i][j] == 'F' && !ft_strncmp(&cub->all[i][j], "F ", 2))
				cub->f = find_color(&cub->all[i][j]);
			if (cub->all[i][j] == 'C' && !ft_strncmp(&cub->all[i][j], "C ", 2))
				cub->c = find_color(&cub->all[i][j]);
			if (!ft_strncmp(&cub->all[i][j], "NO ", 3))
				cub->n = find_path_to_img(&cub->all[i][j]);
			if (!ft_strncmp(&cub->all[i][j], "SO ", 3))
				cub->s = find_path_to_img(&cub->all[i][j]);
			if (!ft_strncmp(&cub->all[i][j], "WE ", 3))
				cub->w = find_path_to_img(&cub->all[i][j]);
			if (!ft_strncmp(&cub->all[i][j], "EA ", 3))
				cub->e = find_path_to_img(&cub->all[i][j]);
			if (!ft_strncmp(&cub->all[i][j], "111", 3) && cub->map == NULL)	
				cub->map = copy_map(i, cub);
			j++;
		}
		i++;
	}
	check_info(cub);
}
