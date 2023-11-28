/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:41 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/28 12:58:12 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_win *wind, int x, int y, int color)
{
	int	*img;

	img = (int *)wind->image.addr;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		img[x + WIDTH * y] = color;
}

void	ray_vars(t_rnd *rnd, t_player *ply, int x)
{
	rnd->camx = 2 * x / (float)WIDTH - 1;
	rnd->raydirx = ply->dirx + ply->planex * rnd->camx;
	rnd->raydiry = ply->diry + ply->planey * rnd->camx;
	
	printf("el raydirx es  %f, el raydiry %f\n", rnd->raydirx, rnd->raydiry);
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

void	ray_hit(t_cub *cub, t_rnd *rnd)
{
	rnd->hit = 0;
	
 	while (rnd->hit == 0)
	{
		if (rnd->side_distx < rnd->side_disty)
		{
			printf("entra x\n");
			rnd->side_distx += rnd->delta_distx;
			rnd->mapx += rnd->stepx;
			rnd->side = 0;
		}
		else
		{
			printf("entra y\n");
			rnd->side_disty += rnd->delta_disty;
			rnd->mapy += rnd->stepy;
			rnd->side = 1;
		}
		if (cub->map_aux[rnd->mapx][rnd->mapy] == '1')
		{
			rnd->hit = 1;
			printf("el side es %i el quadrat que ha xocat es x: %i i y: %i\n", rnd->side, rnd->mapx, rnd->mapy);
		}
	}
}

void	height_wall(t_win *wind, t_rnd *rnd)
{
	(void)wind;

	if (rnd->side == 0) 
		rnd->perpwalldist = fabsf(rnd->side_distx - rnd->delta_distx);
	else
		rnd->perpwalldist = fabsf(rnd->side_disty - rnd->delta_disty);
	
	rnd->line_height = (int)(HEIGHT / rnd->perpwalldist);
	
	rnd->line_start = (HEIGHT / 2) - (rnd->line_height / 2);
	if (rnd->line_start < 0)
		rnd->line_start = 0;
	rnd->line_end = rnd->line_height / 2 + (HEIGHT / 2);
	
	if (rnd->line_end >= HEIGHT)
		rnd->line_end = HEIGHT - 1;

	printf("line height %i\n", rnd->line_height);
	printf("line start %i\n", rnd->line_start);
	printf("line end %i\n", rnd->line_end);
}

int render(t_win *wind)
{
	int		x; 
	t_rnd	rnd;
	
	x = 0;
	//x = (1920 / 2);
	wind->image.img = mlx_new_image(wind->mlx, WIDTH, HEIGHT);
	wind->image.addr = mlx_get_data_addr(wind->image.img, &wind->image.bits_per_pixel, \
		&wind->image.line_len, &wind->image.endian);
	
	//if (x < WIDTH)
	while (x < WIDTH)
	{
		ray_vars(&rnd, wind->player, x);
		find_side_dist(&rnd, wind->player);
		ray_hit(wind->cub, &rnd);
		height_wall(wind, &rnd);
		print_stripe(wind, &rnd, x);
		x++;
	}
	
	//print_minimap(wind->cub, wind);
	print_help(wind, &rnd);
	mlx_put_image_to_window(wind->mlx, wind->mlx_win, wind->image.img, 0, 0);
	return (0);
}
