/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:15:05 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/26 10:38:07 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	assign_pixels_to_points(t_fdf *f, int i, int j, int z)
{
	int	x;
	int y;

	x = i * f->scale + f->initial_pix.x;
	y = j * f->scale + f->initial_pix.y;
	f->map->points[i][j].x = (y - x) * cos(M_PI / 6) + 1920;
	f->map->points[i][j].y = (-z * f->height) + (x + y) * sin(M_PI / 6);
}
