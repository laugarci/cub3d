/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:34:16 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 12:29:23 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

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


