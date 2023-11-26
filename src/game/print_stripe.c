/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stripe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:23:03 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/26 20:12:28 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_text_num(t_rnd *rnd)
{
	int	text;
	
	if (rnd->side == 0 && rnd->raydiry > 0) //N
		text = 0; 
	else if (rnd->side == 0 && rnd->raydiry < 0) //S
		text = 1; 
	else if (rnd->side == 1 && rnd->raydirx > 0) //E
		text = 2;
	else  //W
		text = 3;
	return (text);
}

float    find_x_onmap(t_win *wind, t_rnd *rnd)
{
	float x_map;
	
	if (rnd->side == 0)
		x_map = wind->player->posy + rnd->perpwalldist + rnd->raydiry;
	else
		x_map = wind->player->posx + rnd->perpwalldist + rnd->raydirx;

	x_map -= floor((x_map)); //es queda el decimal
	return (x_map);
}

int	get_pix_text(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	return (*(int *)pixel);
}

void	apply_textures(t_win *wind, t_rnd *rnd, int x, int y)
{
	float	x_map;
	float	y_map;
	int		n_text;
	//float 	step;
	int		color;

	n_text = get_text_num(rnd);
	x_map = find_x_onmap(wind, rnd);
	y_map = (float)64 * y / rnd->line_height;
	color = get_pix_text(&wind->texture[n_text], x_map, y_map);
	my_mlx_pixel_put(wind, x, y, color);
}

void print_stripe(t_win *wind, t_rnd *rnd, int x)
{
	int y;
	int color;

	color = 0xFFF0000;
	y = 0;

	while (y < HEIGHT)
	{
		if (y < rnd->line_start)
			my_mlx_pixel_put(wind, x, y, 0xFF00FF);
		else if (rnd->line_start < y && rnd->line_end > y)
			apply_textures(wind, rnd, x, y);
			//my_mlx_pixel_put(wind, x, y, 0xFF00FF);
		else
			my_mlx_pixel_put(wind, x, y, 0x01EA67);
		y++;
	}
}