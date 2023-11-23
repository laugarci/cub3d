/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:02:22 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/23 09:59:36 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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

#endif
