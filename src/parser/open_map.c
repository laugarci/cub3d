/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:34:16 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/04 20:22:22 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		exit(-1);
	}
	return (fd);
}

int	count_lines(char *path)
{
	char	*line;
	int		i;
	int		fd;

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
		free(line);
	}
	if (close(fd) < 0)
		exit(-1);
	return (i);
}

void	copy_line(char *line, char **map, int row)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	map[row] = malloc(sizeof(char) * i + 1);
	if (!map[row])
		exit(-1);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		map[row][i] = line[i];
		i++;
	}
	map[row][i] = '\0';
}

void	open_map(char *path, t_cub *cub)
{
	int		fd;
	int		count;
	char	*line;

	count = count_lines(path);
	cub->all = malloc(sizeof(char *) * count);
	if (!cub->all)
		exit(-1);
	fd = open_file(path);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!ft_strncmp(line, "\n", 1))
			free(line);
		else
		{
			copy_line(line, cub->all, cub->total_len);
			cub->total_len++;
			free(line);
		}
		line = get_next_line(fd);
	}
	cub->rows = cub->total_len - 6;
	close(fd);
}

void	check_arg(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 4))
	{
		printf("Error: invalid file\n");
		exit(-1);
	}
}
