/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:00:18 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/28 20:27:02 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(t_win *wind, t_img *text, char *path)
{
	text->img = mlx_xpm_file_to_image(wind->mlx, path, &text->width, \
		&text->height);
	if (!text->img)
		return (1);
//	if (text->width != IMAGE || text->height != IMAGE)
//		return (1);
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, \
		&text->line_len, &text->endian);
	if (!text->addr)
		return (1);
	return (0);
}

void	save_textures(t_win *wind)
{
	if (check_texture(wind, &wind->texture[0], wind->cub->n))
		printf("la textura no esta ok\n");
	if (check_texture(wind, &wind->texture[1], wind->cub->s))
		printf("la textura no esta ok\n");
	if (check_texture(wind, &wind->texture[2], wind->cub->e))
		printf("la textura no esta ok\n");
	if (check_texture(wind, &wind->texture[3], wind->cub->w))
		printf("la textura no esta ok\n");
}
