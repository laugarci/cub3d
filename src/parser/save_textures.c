/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:00:18 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/26 20:10:41 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(t_win *wind, t_img *text)
{
	char *path;

    path = strdup("textures/bricks.xpm"); // no es pot utilitzar

    text->img = mlx_xpm_file_to_image(wind->mlx, \
			path, &text->height, &text->height);
    
    if (!text->img)
		return (1);

	if (text->width != 64 || text->height != 64)
		return (1);

	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, &text->line_len, &text->endian);
	if (!text->addr)
		return (1);		

	return (0);
}

void	save_textures(t_win *wind)
{
	int	i;
    
	
	i = 0;

	while (i < 4)
	{
		check_texture(wind, &wind->texture[i]);
		i++;
	}
}