/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 20:29:08 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "defines.h"
# include "../mlx/mlx.h"
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
	int		x;
	int		y;
	int		app_col[4];
	int		colors[4];
}			t_cub;

typedef struct s_player
{
	int		up; //
	int		down;//
	int		left;//
	int		right;//
	int		cam_left;
	int		cam_right;
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	int		direction;
	char	*file[2];
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

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	t_cub		*cub;
	t_player	*player;
	t_img		image;
	t_img		texture[4];
}	t_win;

typedef struct s_rnd
{
	int		mapx;
	int		mapy;
	float	camx;
	float	raydirx;
	float	raydiry;
	float	delta_distx;
	float	delta_disty;
	int		stepx;
	int		stepy;
	float	side_distx;
	float	side_disty;
	int		hit;
	int		side;
	float	perpwalldist;
	int		line_height;
	int		line_start;
	int		line_end;
}	t_rnd;

//PARSER
void		check_arg(char **av);
void		init_vars(t_cub *cub, t_player *player);
void		open_map(char *path, t_cub *cub);
void		free_map(t_cub *cub);
void		check_map(t_cub *cub, t_player *player);
void		parse_file(t_cub *cub);
void		find_path_to_img(char *map, char **path);
char		**copy_map(int init, t_cub *cub);
void		free_all(t_cub *cub);
void		free_matrix(char **matrix, int len);
void		invalid_map(t_cub *cub);
int			check_one(char *str);
int			check_char(char c);
void		check_info(t_cub *cub);
int			check_player(t_cub *cub);
void		check_paths(t_cub *cub);
void		count_cols(t_cub *cub);
void		print_and_exit_errors(char *str);
void		check_paths_to_img(t_cub *cub);

//MOVEMENTS
void		find_dir_player(t_cub *cub, t_player *player);
void		move_cam_left(t_player *player, float oldirx, float oldplanex);
void		move_cam_right(t_player *player, float olddirx,	float oldplanex);
int			move_mouse(t_win *wind);
int			movements(int mov, t_win *wind);
void		move_cam(t_player *player);
void		put_player(t_player *player, t_win *wind);
int			stop_movement(int mov, t_win *wind);
void		move(t_win *wind);

//MINIMAP
void		print_minimap(t_cub *cub, t_win *wind);
int			check_dec(float x, float y);

//RENDER
void		game(t_cub *cub, t_player *player);
int			render(t_win *wind);
void		print_stripe(t_win *wind, t_rnd *rnd, int x);
int			rgb_to_hex(int r, int g, int b);
void		my_mlx_pixel_put(t_win *wind, int x, int y, int color);
void		save_images(t_win *wind);

//MAP
int			close_window(t_win *wind);
int			check_correct(char **map, int x, int y);

#endif
