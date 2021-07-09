/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:34:44 by rcabezas          #+#    #+#             */
/*   Updated: 2021/07/09 12:40:30 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw(t_fdf *f)
{
	int	i;
	int j;

	i = 0;
	while (i < f->map->size_x)
	{
		j = 0;
		while (j < f->map->size_y)
		{
			draw_point(f, f->map->points[i][j]);
			j++;
		}
		i++;
	}
}

void	color_put(t_fdf *f, int x, int y)
{
	int	i;

	i = y * f->camera.img.line_length + f->camera.img.bpp / 8 * x;
	f->camera.img.addr[i] = 126;
	f->camera.img.addr[i + 1] = 126;
	f->camera.img.addr[i + 2] = 126;
}

void	draw_point(t_fdf *f, t_vec point)
{
	
}