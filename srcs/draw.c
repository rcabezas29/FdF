/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:34:44 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/27 14:13:11 by rcabezas         ###   ########.fr       */
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
	int	i;

	if (pix.point.y < 1080 && pix.point.x < 1920
		&& pix.point.x > 0 && pix.point.y > 0)
	{
		i = pix.point.y * f->img.line_length + f->img.bpp / 8 * pix.point.x;
		put_rgb(f->img.addr + i, pix.color);
	}
}

void	put_rgb(unsigned char *addr, t_color color)
{
	addr[0] = color.r;
	addr[1] = color.g;
	addr[2] = color.b;
}
