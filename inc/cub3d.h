/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/28 15:26:23 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "defines.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <string.h>
 
# include "../get_next_line/get_next_line.h"

typedef struct s_cub
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	char	p;
	int		f[3];
	int		c[3];
	char	**map;
	char	**map_aux;
	char	**all;
	int		player[2];
	int		rows;
	int		cols;
	int		total_len;
	int		x; //float
	int		y; //float
	
}			t_cub;


typedef struct s_player {
	float	posx; //float
	float	posy; //float
	//float	ang;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_win {
	void		*mlx;
	void		*mlx_win;
	t_cub		*cub;
	t_player	*player;
	t_img		image;
	t_img		texture[4];
}	t_win;

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


//PARSER
void	check_arg(char **av);
void	init_vars(t_cub *cub);
void	open_map(char *path, t_cub *cub);
void	free_map(t_cub *cub);
void	check_map(t_cub *cub, t_player *player);
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
void	count_cols(t_cub *cub);
void	save_textures(t_win *wind);

//MINIMAP
void	print_minimap(t_cub *cub, t_win *wind);
int		check_dec(float x, float y);

//RENDER
void	game(t_cub *cub, t_player *player);
int		render(t_win *wind);
void	my_mlx_pixel_put(t_win *wind, int x, int y, int color);
void	 print_stripe(t_win *wind, t_rnd *rnd, int x);
unsigned int	rgb_to_hex(int r, int g, int b);

//UTILS
unsigned int	rgb_to_hex(int r, int g, int b);

//MAP
int		movements(int mov, t_win *wind);
int		close_window(t_win *wind);
void	move_cam(t_player *player, int mov);
int		check_correct(char **map, int x, int y);

#endif
