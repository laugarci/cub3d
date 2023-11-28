/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stripe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:23:03 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/28 14:39:40 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_text_num(t_rnd *rnd)
{
	int	text;
	
	if (rnd->side == 1 && rnd->raydiry < 0) //N
		text = 0; 
	else if (rnd->side == 1 && rnd->raydiry > 0) //S
		text = 1; 
	else if (rnd->side == 0 && rnd->raydirx > 0) //E
		text = 2;
	else  //W
		text = 3;
	return (text);
}

float    find_x_onmap(t_win *wind, t_rnd *rnd)
{
	float	x_map;
	int		x_text;
	
	if (rnd->side == 0)
		x_map = wind->player->posy + rnd->perpwalldist * rnd->raydiry;
	else
		x_map = wind->player->posx + rnd->perpwalldist * rnd->raydirx;

	x_map = x_map - floor((x_map)); //es queda el decimal
	x_text = (int)(x_map * 64);
	/*if (rnd->side == 0 && rnd->raydiry > 0 )
		x_text = 64 - x_text - 1;
	else if (rnd->side == 1 && rnd->raydiry < 0)
		x_text = 64 - x_text - 1;*/
	return (x_text);
}

int	get_pix_text(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(int *)pixel);
}

void print_stripe(t_win *wind, t_rnd *rnd, int x)
{
	int 	y;
	int		n_text;
	int		x_text;
	float	step;
	float	y_text;
	int		color;
	//float	tex_pos;

	
	y = 0;
	n_text = get_text_num(rnd);
	x_text = find_x_onmap(wind, rnd);
	step = (float)64 / rnd->line_height;
	//tex_pos = (rnd->line_start - rnd->line_height / 2 + rnd->line_height / 2)  * step;

	if(rnd->line_height >= HEIGHT)
		y_text = ((rnd->line_height - HEIGHT) / 2) * step;
	else
		y_text = 0;

	while (y < rnd->line_start)
	{	
		my_mlx_pixel_put(wind, x, y, 0xFF00FF); //magenta
		y++;
	}
	while (rnd->line_start <= y && y < rnd->line_end)
	{
		color = get_pix_text(&wind->texture[n_text], x_text, (int)y_text);
		my_mlx_pixel_put(wind, x, y, color);
		y_text = y_text + step;
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(wind, x, y, 0xFFF0000); // red
		y++;
	}
}

	/*while (rnd->line_start <= y && y < rnd->line_end)
	{
		if (n_text == 0)
			color = 0x00B2FF; // blue d
		else if (n_text == 1)
			color = 0x01EA67; //green d
		else if (n_text == 2)
			color = 0xFF00E0; //pink
		else if (n_text == 3)
			color = 0xFFF700; //orange	
		my_mlx_pixel_put(wind, x, y, color);
		y++;
	}*/
