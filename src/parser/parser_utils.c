/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:56:13 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/04 20:19:48 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_and_exit_errors(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

void	init_vars_aux(t_player *player)
{
	player->up = 0;
	player->down = 0;
	player->left = 0;
	player->right = 0;
	player->cam_left = 0;
	player->cam_right = 0;
}

void	init_vars(t_cub *cub, t_player *player)
{
	cub->n = NULL;
	cub->s = NULL;
	cub->e = NULL;
	cub->w = NULL;
	cub->map = NULL;
	cub->rows = 0;
	cub->cols = 0;
	cub->f[0] = -1;
	cub->f[1] = -1;
	cub->f[2] = -1;
	cub->c[0] = -1;
	cub->c[1] = -1;
	cub->c[2] = -1;
	cub->player[0] = -1;
	cub->player[1] = -1;
	cub->app_col[0] = 0;
	cub->app_col[1] = 0;
	cub->app_col[2] = 0;
	cub->app_col[3] = 0;
	cub->total_len = 0;
	init_vars_aux(player);
}

void	check_numbers_are_correct(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (ft_isalpha(number[i]))
			print_and_exit_errors("Floor and/or sky colors are \
				missing or invalid.");
		if (number[i] == '-')
			print_and_exit_errors("Floor and/or sky colors are \
				missing or invalid.");
		i++;
	}
}
