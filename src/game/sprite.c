/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:45:51 by laugarci          #+#    #+#             */
/*   Updated: 2023/11/30 14:57:10 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_player *player, t_win *wind)
{
	if (player->direction == 1)
		mlx_put_image_to_window(wind->mlx, wind->mlx_win, player->file[0], \
			(WIDTH / 2) - 330, (HEIGHT - 550));
	else if (player->direction == 2)
		mlx_put_image_to_window(wind->mlx, wind->mlx_win, player->file[1], \
			(WIDTH / 2) - 330, (HEIGHT - 550));
}
