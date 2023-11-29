/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:21 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/29 18:40:48 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_mouse(t_win *wind)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(wind->mlx_win, &x, &y);
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		mlx_mouse_move(wind->mlx_win, WIDTH / 2, HEIGHT / 2);
	else if ((WIDTH / 2 - x) < -MOUSE_MARGIN)
		move_cam_left(wind->player, wind->player->dirx, wind->player->planex);
	else if ((HEIGHT / 2 - x) > MOUSE_MARGIN)
		move_cam_right(wind->player, wind->player->dirx, wind->player->planex);
	return (0);
}
