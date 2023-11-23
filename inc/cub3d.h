/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 11:38:32 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "defines.h"
#include "../mlx/mlx.h"

# include "../get_next_line/get_next_line.h"

typedef struct s_cub
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	int		f[3];
	int		c[3];
	char	**map;
	char	**all;
	int		player[2];
	int		rows;
	int		total_len;
}			t_cub;

typedef struct s_fds
{
	int		fd_n;
	int		fd_s;
	int		fd_e;
	int		fd_w;
}			t_fds;

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


void	check_arg(char **av);
void	init_vars(t_cub *cub);
void	open_map(char *path, t_cub *cub);
void	free_map(t_cub *cub);
void	check_map(t_cub *cub);
void	parse_file(t_cub *cub);
void	find_path_to_img(char *map, char **path);
char	**copy_map(int init, t_cub *cub);
void	free_all(t_cub *cub);
void	free_matrix(char **matrix, int len);
void	invalid_map(t_cub *cub);
int		check_one(char *str);
int		check_char(char c);
void	check_info(t_cub *cub);
int		check_player(t_cub *cub);
void	check_paths(t_cub *cub);

//RENDER
void    ft_init_vars(t_cub *cub, t_player *player);
void 	game(t_cub *cub, t_player *player);
void 	render(t_win *wind, t_cub *cub, t_player *player);

#endif
