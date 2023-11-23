/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:41 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/23 17:31:52 by julolle-         ###   ########.fr       */
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
	rnd->camx = 2 * x / (double)wind->wind_x - 1;
	rnd->raydirx = ply->dirx + ply->planex * rnd->camx;
	rnd->raydiry = ply->diry + ply->planey * rnd->camx;
	rnd->mapx = (int)ply->posx;
	rnd->mapy = (int)ply->posy;
	if (rnd->raydirx == 0)
		rnd->delta_distx = 1e30;
	else
		rnd->delta_distx = 1 / rnd->raydirx;
	if (rnd->raydiry == 0)	
		rnd->delta_disty = 1e30;
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

void	height_wall(t_win *wind, t_rnd *rnd)
{

	if (rnd->side == 0) 
		rnd->perpwalldist = rnd->side_distx - rnd->delta_distx;
	else
		rnd->perpwalldist = rnd->side_disty - rnd->delta_disty;
	rnd->line_height = (int)(wind->wind_y / rnd->perpwalldist);
	
	rnd->line_start = (wind->wind_y / 2) - (rnd->line_height / 2);
	if (rnd->line_start < 0)
		rnd->line_start = 0;
	rnd->line_end = wind->wind_y - rnd->line_start;
}

void print_stripe(t_win *wind, t_rnd *rnd, int x)
{
	int y;
	int color;

	color = 0xFFF0000;
	y = 0;
	while (y < wind->wind_y)
	{
		if (y < rnd->line_start)
			my_mlx_pixel_put(wind, x, y, 0xFF00FF);
		else if (rnd->line_start < y && rnd->line_end > y)
			my_mlx_pixel_put(wind, x, y, 0x00FFFF);
		else
			my_mlx_pixel_put(wind, x, y, 0x01EA67);
		y++;
	}
}

void debug_game(t_cub *cub, t_player *player, t_rnd *rnd)
{
	(void)cub;
//	printf("posx %f posy %f\n", player->posx, player->posy);
	printf("dirx %f diry %f\n", player->dirx, player->diry);
	printf("planex %f planey %f\n\n\n", player->planex, player->planey);
	
	printf("mapx %i mapy %i\n", rnd->mapx, rnd->mapy);
	printf("stepx %i stepy %i\n", rnd->stepx, rnd->stepy);
	printf("line start %i line end %i\n", rnd->line_start, rnd->line_end);
}

void render(t_win *wind, t_cub *cub, t_player *player)
{
	int		x;
	t_rnd	rnd;

	x = 0;
	wind->img = mlx_new_image(wind->mlx, wind->wind_x, wind->wind_y);
	wind->addr = mlx_get_data_addr(wind->img, &wind->bits_per_pixel, \
		&wind->line_lenght, &wind->endian);
	printf("x: %d y: %d\n", player->posx, player->posy);
	while (x < wind->wind_x)
	{
		ray_vars(wind, &rnd, player, x);
		ray_hit(cub, &rnd);
		height_wall(wind, &rnd);
		print_stripe(wind, &rnd, x);
		x++;
	}
	mlx_put_image_to_window(wind->mlx, wind->mlx_win, wind->img, 0, 0);
}
