/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:41 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/23 11:21:30 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_win *wind, int x, int y, int color)
{
	int	*img;

	img = (int *)wind->addr;
	if (x >= 0 && x < wind->wind_x && y >= 0 && y < wind->wind_y)
		img[x + wind->wind_x * y] = color;
}

void	find_side_dist(t_rnd *rnd, t_player *ply)
{
	if (rnd->raydirx < 0)
	{
		rnd->stepx = -1;
		rnd->side_distx = (ply->posx - rnd->mapx) * rnd->delta_distx;
	}
	else
	{
		rnd->stepx = 1;
		rnd->side_distx = (rnd->mapx + 1 - ply->posx) * rnd->delta_distx;
	}
	if (rnd->raydiry < 0)
	{
		rnd->stepy = -1;
		rnd->side_disty = (ply->posy - rnd->mapy) * rnd->delta_disty;
	}
	else
	{
		rnd->stepy = 1;
		rnd->side_disty = (rnd->mapy + 1 - ply->posy) * rnd->delta_disty;
	}
}

void	ray_vars(t_win *wind, t_rnd *rnd, t_player *ply, int x)
{
	rnd->camx = (2 * x / wind->wind_x) - 1;
	rnd->raydirx = ply->dirx + (ply->planex * rnd->camx);
	rnd->raydiry = ply->diry + (ply->planey * rnd->camx);
	if (rnd->raydirx == 0)	
		rnd->delta_distx = 1 / 1e30;
	else
		rnd->delta_distx = 1 / rnd->raydirx;
	if (rnd->raydiry == 0)	
		rnd->delta_disty = 1 / 1e30;
	else
		rnd->delta_disty = 1 / rnd->raydiry;
	find_side_dist(rnd, ply);
}

void	ray_hit(t_cub *cub, t_rnd *rnd)
{
	rnd->hit = 0;

 	while (rnd->hit == 0)
	{
		if (rnd->side_distx < rnd->side_disty)
		{
			rnd->side_distx += rnd->delta_distx;
			rnd->mapx += rnd->stepx;
			rnd->side = 0;
		}
		else
		{
			rnd->side_disty += rnd->delta_disty;
			rnd->mapy += rnd->stepy;
			rnd->side = 1;
		}
		if (cub->map[rnd->mapx][rnd->mapy] > 0) 
			rnd->hit = 1;
	}
}

void	height_wall(t_rnd *rnd)
{
	int	h; //pending to check

	h = 500;
	
	if (rnd->side == 0) 
		rnd->perpwalldist = rnd->side_distx - rnd->delta_distx;
	else
		rnd->perpwalldist = rnd->side_disty - rnd->delta_disty;
	rnd->line_height = (int)(h / rnd->perpwalldist);
	rnd->line_start = (1080 / 2) - (rnd->line_height / 2);
	rnd->line_end = 1080 - rnd->line_start;
}

void render(t_win *wind, t_cub *cub, t_player *player)
{
	int		x;
	t_rnd	rnd;

	x = 0;
	(void)cub;
	while (x < wind->wind_x)
	{
		ray_vars(wind, &rnd, player, x);
		//ray_hit(cub, &rnd);
		//height_wall(&rnd);
		x++;
	}
}
