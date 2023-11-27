/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_img_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:28:48 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/27 10:25:06 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

char	*copy_path(char *map, int del)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * del + 1);
	while (i < del)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	find_path_to_img(char *map, char **path)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	map += 3;
	if (*path != NULL)
	{
		printf("Error: too much paths\n");
		exit(-1);
	}
	while (map[i])
	{
		if (map[i] == '\n')
			break ;
		if (map[i] == ' ' || map[i] == '\t')
		{
			while (map[i] == ' ' || map[i] == '\t')
				i++;
		}
		else
		{
			c = 0;
			while (map[i] && map[i] != ' '
				&& map[i] != '\t' && map[i] != '\n')
			{
				c++;
				i++;
			}
			*path = copy_path(&map[i - c], c);
			break ;
		}
	}
	if (*path == NULL)
	{
		printf("Error: path to image not found, please, check your file\n");
		exit(-1);
	}
}
