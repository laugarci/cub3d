/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:23:03 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/24 14:13:44 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_text(t_win *wind, t_rnd *rnd)
{
	int	text;

	if (rnd->side == 0 && wind->player->raydiry > 0) //N
		text = 0; 
	else if (rnd->side == 0 && wind->player->raydiry < 0) //S
		text = 1; 
	else if (rnd->side == 1 && wind->player->raydirx > 0) //E
		text = 2;
	else if (rnd->side == 1 && wind->player->raydirx < 0) //W
		text = 3;
	return (text);
}

float    find_x_onmap(t_win *wind, t_rnd *rnd)
{
	float x;
	
	if (side == 0)
		x_map = wind->player->posy + rnd->perpWallDist + wind->player->raydiry;
	else
		x_map = wind->player->posx + rnd->perpWallDist + wind->player->raydirx;

	x -= floor((x_map)); //es queda el decimal
}

void	get_pix_text()
{
	


}


void	apply_textures(t_win *wind, t_rnd *rnd, int x)
{
	float	x_map;
	int		text;
	float 	step;
	
	text = get_text(wind, rnd);
	x_map = find_x_onmap(wind, rnd);
	get_pix_text()

	
}