/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:34:44 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/26 10:38:44 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw(t_fdf *f)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < f->map->size_y)
	{
		j = 0;
		while (j < f->map->size_x)
		{
			if (j != 0)
				bresenham(f, f->map->points[i][j - 1], f->map->points[i][j]);
			if (i != 0)
				bresenham(f, f->map->points[i - 1][j], f->map->points[i][j]);
			j++;
		}
		i++;
	}
}

void	color_put(t_fdf *f, t_pixel pix)
{
	int i;

	if (pix.y < 1080 && pix.x < 1920 && pix.x > 0 && pix.y > 0)
	{
		i = pix.y * f->img.line_length + f->img.bpp / 8 * pix.x;
		put_rgb(f->img.addr + i, 255, 255, 255);
	}
}

void	put_rgb(unsigned char *addr, unsigned char r, unsigned char g, unsigned char b)
{
	addr[0] = r;
	addr[1] = g;
	addr[2] = b;
}
