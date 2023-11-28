/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:25 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/28 12:31:29 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_correct(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (map[x][y] == '1')
		return (0);
	return (1);
}

unsigned int	rgb_to_hex(int r, int g, int b)
{
	unsigned int hexa;

	hexa = (r << 16) | (g << 8) | b;
	return (hexa);
}
