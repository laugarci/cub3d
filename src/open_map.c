/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:34:16 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 12:38:11 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int		open_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		exit(-1);
	}
	return (fd);
}

int		count_lines(char *path)
{
	char 	*line;
	int		i;
	int 	fd;

	i = 0;
	line = NULL;
	fd = open_file(path);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "\n", 1))
			i++;
	}
	if (close(fd) < 0)
		exit(-1);
	return (i);
}

void	open_map(char *path, t_cub *cub)
{
	int		fd;
	int		i;
	int		count;

	i = 0;
	count = count_lines(path);
	cub->all = malloc(sizeof(char *) * count);
	if (!cub->all)
	{
		printf("Malloc error\n");
		exit(-1);
	}
	fd = open_file(path);
	while(42)
	{
		cub->all[i] = get_next_line(fd);
		if (cub->all[i] == NULL)
			break ;
		else if (!ft_strncmp(cub->all[i], "\n", 1))
		{
			free(cub->all[i]);
			cub->all[i] = NULL;
		}
		else
			i++;
	}
	cub->total_len = i;
	cub->rows = i - 6;
	close(fd);
}

void	check_arg(char **av)
{
	int len;

	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 4))
	{
		printf("Error: el archivo no es valido\n");
		exit(-1);
	}
}
