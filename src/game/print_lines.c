/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:16:48 by julolle-          #+#    #+#             */
/*   Updated: 2023/11/27 20:19:32 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

void print_line(t_win *wind, float x0, float x1, float y0, float y1)
{

    float   dy;
    float   dx;
    float   sx;
    float   sy;
    float error;
    float e2;
     
    
  
    int size;
    size = 20;
    
    //y1 = y1 * 3;
   // x1 = x1 * 3;

    dx = fabsf(x1 - x0);
    sx = x0 < x1 ? 1 : -1;
    dy = -fabsf(y1 - y0);
    sy = y0 < y1 ? 1 : -1;
    error = dx + dy;
    
    while (1)
    {
        my_mlx_pixel_put(wind, x0, y0, 0xFF00FF);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * error;
        if (e2 >= dy)
        {    
            if (x0 == x1) 
                break ;
            error = error + dy;
            x0 = x0 + sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1 )
                break;
            error = error + dx;
            y0 = y0 + sy;
	    }  
    }
   
}


void    print_help(t_win *wind, t_rnd *rnd)
{
	(void)rnd;
    //print_line(wind, 40, 70, 40, 70);
    printf("posx %f, pos y %f\n", wind->player->posx, wind->player->posy);
    printf("dirx %f, diry %f\n", wind->player->dirx, wind->player->diry);
   print_line(wind, wind->player->posx, wind->player->posx + (20 * wind->player->dirx), wind->player->posy, wind->player->posy + (20 * wind->player->diry));

}