/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 10:46:42 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "defines.h"

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
	
} t_cub;

typedef struct s_win {
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		wind_x;
	int		wind_y;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_win;

typedef struct s_player {
	int		init_pos[2];
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
}	t_player;

typedef struct s_rnd {
	int		mapx;
	int		mapy;
	float	camx;
	float 	raydirx;
	float	raydiry;
	float	delta_distx; 
	float	delta_disty;
	int		stepx; //direction ray on axis x (1->R,  -1->L)
	int		stepy;
	float	side_distx; //distance ray on to next side X
	float	side_disty;
	int		hit; //hit == 0
	int		side; // side=0 (if ray hits X) // side=1 (if ray hits Y)
	float	perpwalldist;
	int		line_height;
	int		line_start;
	int		line_end;
}	t_rnd;

void    init_vars(t_cub *cub, t_player *player);
void 	game(t_cub *cub, t_player *player);
void 	render(t_win *wind, t_cub *cub, t_player *player);

# endif
