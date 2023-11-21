/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/21 11:58:50 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>

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
}	t_cub;

# endif
