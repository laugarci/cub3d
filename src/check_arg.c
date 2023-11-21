/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:34:16 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 13:54:28 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void	init_vars(t_cub *cub)
{
	cub->n = NULL;
	cub->s = NULL;
	cub->e = NULL;
	cub->w = NULL;
	cub->f = NULL;
	cub->c = NULL;
	cub->map = NULL;
}

void	open_map(char *path, t_cub *cub)
{
	int fd;
	int i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening the file\n");
		exit(-1);
	}
	while (42)
	{
		if (cub->map[i] == NULL)
			break ;
		cub->map[i] = get_next_line(fd);
		i++;
	}
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


