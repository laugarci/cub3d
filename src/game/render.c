/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:41 by julolle-          #+#    #+#             */
/*   Updated: 2023/12/03 16:52:42 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_vars(t_rnd *rnd, t_player *ply, int x)
{
	rnd->camx = 2 * x / (float)WIDTH - 1;
	rnd->raydirx = ply->dirx + ply->planex * rnd->camx;
	rnd->raydiry = ply->diry + ply->planey * rnd->camx;
	rnd->mapx = (int)ply->posx;
	rnd->mapy = (int)ply->posy;
	if (rnd->raydirx == 0)
		rnd->delta_distx = 1e30;
	else
		rnd->delta_distx = fabsf(1 / rnd->raydirx);
	if (rnd->raydiry == 0)
		rnd->delta_disty = 1e30;
	else
		rnd->delta_disty = fabsf(1 / rnd->raydiry);
}

void	side_dist(t_rnd *rnd, t_player *ply)
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
		if (cub->map[rnd->mapy][rnd->mapx] == '1')
			rnd->hit = 1;
	}
}

void	wall_height(t_rnd *rnd)
{
	if (rnd->side == 0)
		rnd->perpwalldist = fabsf(rnd->side_distx - rnd->delta_distx);
	else
		rnd->perpwalldist = fabsf(rnd->side_disty - rnd->delta_disty);
	if (rnd->perpwalldist < 1e-2)
		rnd->perpwalldist = 1e-2;
	rnd->line_height = (int)(HEIGHT / rnd->perpwalldist);
	rnd->line_start = (HEIGHT / 2) - (rnd->line_height / 2);
	rnd->line_start = (HEIGHT / 2) - (rnd->line_height / 2);
	if (rnd->line_start < 0)
		rnd->line_start = 0;
	rnd->line_end = (HEIGHT / 2) + (rnd->line_height / 2);
	if (rnd->line_end >= HEIGHT)
		rnd->line_end = HEIGHT - 1;
}

int	render(t_win *wind)
{
	int		x;
	t_rnd	rnd;

	x = 0;
	while (x < WIDTH)
	{
		ray_vars(&rnd, wind->player, x);
		side_dist(&rnd, wind->player);
		ray_hit(wind->cub, &rnd);
		wall_height(&rnd);
		print_stripe(wind, &rnd, x);
		x++;
	}
	print_minimap(wind->cub, wind);
	move(wind);
	move_cam(wind->player);
	move_mouse(wind);
	mlx_put_image_to_window(wind->mlx, wind->mlx_win, wind->image.img, 0, 0);
	put_player(wind->player, wind);
	return (0);
}
