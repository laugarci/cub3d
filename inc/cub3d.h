/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 17:37:03 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "../get_next_line/get_next_line.h"

typedef struct s_cub
{
	//PATH TO IMG
	char *n;
	char *s;
	char *e;
	char *w;
	//COLORS
	int *f;
	int *c;
	//MAP
	char **map;
	char **all;
	//PLAYER POSITION
	int *player;
	//ROWS
	int rows;
}	t_cub;

void	check_arg(char **av);
void	init_vars(t_cub *cub);
void	open_map(char *path, t_cub *cub);
void	free_map(t_cub *cub);
void	check_map(t_cub *cub);
void	parse_file(t_cub *cub);

# endif
