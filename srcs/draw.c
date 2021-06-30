/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:34:44 by rcabezas          #+#    #+#             */
/*   Updated: 2021/06/30 12:50:37 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void    draw(t_fdf *f)
{
    int i;
    int j;
    int dist;

    dist = 1200 / f->map->size_x;
    i = 0;
    while (i < f->map->size_x)
    {
        j = 0;
        while (j < f->map->size_y)
        {
            color_put(f, i * dist, j * dist);
            j++;
        }
        i++;
    }
    
}

void		color_put(t_fdf *f, int x, int y)
{
	int	i;
    
	i = y * f->img.line_length + f->img.bpp / 8 * x;
	f->img.addr[i] = 126;
	f->img.addr[i + 1] = 126;
	f->img.addr[i + 2] = 126;
}