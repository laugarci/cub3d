/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:31:30 by laugarci          #+#    #+#             */
/*   Updated: 2023/12/03 19:39:38 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	movements(int mov, t_win *wind)
{
	if (mov == ESC)
		close_window(wind);
	if (mov == CAM_RIGHT && wind->player->cam_left == 0)
		wind->player->cam_right = 1;
	if (mov == CAM_LEFT && wind->player->cam_right == 0)
		wind->player->cam_left = 1;
	if (mov == UP)
		wind->player->up = 1;
	if (mov == LEFT)
		wind->player->left = 1;
	if (mov == RIGHT)
		wind->player->right = 1;
	if (mov == DOWN)
		wind->player->down = 1;
	if (mov == TURBO)
	{
		if (wind->player->speed == FAST_SPEED)
			wind->player->speed = SPEED;
		else
			wind->player->speed = FAST_SPEED;
	}
	return (0);
}

int	stop_movement(int mov, t_win *wind)
{
	if (mov == UP)
		wind->player->up = 0;
	if (mov == LEFT)
		wind->player->left = 0;
	if (mov == RIGHT)
		wind->player->right = 0;
	if (mov == DOWN)
		wind->player->down = 0;
	if (mov == CAM_RIGHT)
		wind->player->cam_right = 0;
	if (mov == CAM_LEFT)
		wind->player->cam_left = 0;
	return (0);
}
