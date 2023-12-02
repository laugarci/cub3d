/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stripe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:23:03 by julolle-          #+#    #+#             */
/*   Updated: 2023/12/02 16:39:40 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	txt_n(t_rnd *rnd)
{
	int	text;

	if (rnd->side == 1 && rnd->raydiry < 0)
		text = 0;
	else if (rnd->side == 1 && rnd->raydiry > 0)
		text = 1;
	else if (rnd->side == 0 && rnd->raydirx > 0)
		text = 2;
	else
		text = 3;
	return (text);
}

int	pix_text(t_win *wind, t_rnd *rnd, int x, int y)
{
	char	*pixel;
	t_img	*img;
	int		n_txt;

	n_txt = txt_n(rnd);
	if (wind->cub->app_col[n_txt] == 0)
	{
		img = &wind->texture[n_txt];
		pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		return (*(int *)pixel);
	}
	else
		return (wind->cub->colors[n_txt]);
}

int	x_text(t_win *wind, t_rnd *rnd)
{
	float	x_map;
	float	x_text;

	if (rnd->side == 0)
		x_map = wind->player->posy + rnd->perpwalldist * rnd->raydiry;
	else
		x_map = wind->player->posx + rnd->perpwalldist * rnd->raydirx;
	x_map = x_map - floor((x_map));
	x_text = (x_map * (float)IMAGE);
	if (rnd->side == 0 && rnd->raydirx < 0)
		x_text = IMAGE - x_text - 1;
	else if (rnd->side == 1 && rnd->raydiry > 0)
		x_text = IMAGE - x_text - 1;
	return (x_text);
}

int	y_init_on_text(t_rnd *rnd)
{
	float	y_text;
	float	step;

	step = (float)IMAGE / rnd->line_height;
	if (rnd->line_height >= HEIGHT)
		y_text = ((rnd->line_height - HEIGHT) / 2) * step;
	else
		y_text = 0;
	return (y_text);
}

void	print_stripe(t_win *wind, t_rnd *rnd, int x)
{
	int		y;
	int		color;
	float	step;
	float	tex_pos;
	int		tex_y;

	(void)x;
	y = 0;
	step = (float)IMAGE / rnd->line_height;
	tex_pos = (rnd->line_start - HEIGHT / 2 + rnd->line_height / 2) * step;
	color = rgb_to_hex(wind->cub->c[0], wind->cub->c[1], wind->cub->c[2]);
	while (y < rnd->line_start)
		my_mlx_pixel_put(wind, x, y++, color);
	while (y < rnd->line_end)
	{
		tex_y = (int)tex_pos & (IMAGE - 1);
		tex_pos = tex_pos + step;
		color = pix_text(wind, rnd, x_text(wind, rnd), tex_y);
		my_mlx_pixel_put(wind, x, y, color);
		y++;
	}
	color = rgb_to_hex(wind->cub->f[0], wind->cub->f[1], wind->cub->f[2]);
	while (y <= HEIGHT)
		my_mlx_pixel_put(wind, x, y++, color);
}
