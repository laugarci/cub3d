/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:36:28 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 15:16:50 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	find_number(char *map, int del)
{
	char	*tmp;
	int		i;
	int		num;

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

void	find_color(char *map, int color[3])
{
	int	i;
	int	c;
	int	num;

	i = 0;
	num = 0;
	while (map[i] && map[i] != '\n' && num < 3)
	{
		if ((map[i] >= '0' && map[i] <= '9') || (map[i] == '-'
				&& (map[i + 1] >= '0' && map[i + 1] <= '9')))
		{
			c = 0;
			if (map[i] == '-')
				c++;
			i += c;
			while (map[i] && map[i] >= '0' && map[i] <= '9')
			{
				c++;
				i++;
			}
			color[num++] = find_number(&map[i - c], c);
		}
		i++;
	}
}

int	all_found(t_cub *cub)
{
	if (cub->n == NULL || cub->s == NULL || cub->w == NULL || cub->e == NULL)
		return (0);
	else if (cub->f[0] == -1 || cub->f[1] == -1 || cub->f[2] == -1)
		return (0);
	else if (cub->c[0] == -1 || cub->f[1] == -1 || cub->f[2] == -2)
		return (0);
	if (cub->map != NULL)
		return (0);
	return (1);
}

void	parse_file_aux(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->total_len)
	{
		j = 0;
		while (cub->all[i][j])
		{
			if (!ft_strncmp(&cub->all[i][j], "NO ", 3))
				find_path_to_img(&cub->all[i][j], &cub->n);
			if (!ft_strncmp(&cub->all[i][j], "SO ", 3))
				find_path_to_img(&cub->all[i][j], &cub->s);
			if (!ft_strncmp(&cub->all[i][j], "WE ", 3))
				find_path_to_img(&cub->all[i][j], &cub->w);
			if (!ft_strncmp(&cub->all[i][j], "EA ", 3))
				find_path_to_img(&cub->all[i][j], &cub->e);
			j++;
		}
		i++;
	}
}

void	parse_file(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	parse_file_aux(cub);
	while (i < cub->total_len)
	{
		j = 0;
		while (cub->all[i][j])
		{
			if (cub->all[i][j] == 'F' && !ft_strncmp(&cub->all[i][j], "F ", 2))
				find_color(&cub->all[i][j], cub->f);
			if (cub->all[i][j] == 'C' && !ft_strncmp(&cub->all[i][j], "C ", 2))
				find_color(&cub->all[i][j], cub->c);
			if (!ft_strncmp(&cub->all[i][j], "1", 1) && all_found(cub) && (i = 6))
				cub->map = copy_map(i, cub);
			j++;
		}
		i++;
	}
}
