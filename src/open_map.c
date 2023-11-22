/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:34:16 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/22 19:47:55 by laugarci         ###   ########.fr       */
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
	}
	if (close(fd) < 0)
		exit(-1);
	return (i);
}

void	copy_line(char *line, char ***map, int row)
{
	int len;

	len = ft_strlen(line);
	(*map)[row] = malloc(sizeof(char) * len + 1);
	if (!(*map)[row])
		exit(-1);
	ft_strlcpy((*map)[row], line, len);
}

void	open_map(char *path, t_cub *cub)
{
	int		fd;
	int		i;
	int		count;
	char	*line;

	i = 0;
	count = count_lines(path);
	cub->all = malloc(sizeof(char *) * count);
	if (!cub->all)
	{
		printf("Malloc error\n");
		exit(-1);
	}
	fd = open_file(path);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (!ft_strncmp(line, "\n", 1))
			free(line);
		else
		{
			copy_line(line, &(cub->all), i);
			i++;
			free(line);
		}
	}
	cub->total_len = i;
	cub->rows = i - 6;
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
