/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:53:32 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/27 14:10:11 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

float	know_dist(int one, int two, float dist)
{
	return ((two - one) / dist);
}

void	bresenham(t_fdf *f, t_pixel p1, t_pixel p2)
{
	float	dist;
	float	stepx;
	float	stepy;
	float	i;
	t_color	color;

	i = 0;
	dist = sqrt(pow(p2.point.x - p1.point.x, 2)
			+ pow(p2.point.y - p1.point.y, 2));
	stepx = know_dist(p1.point.x, p2.point.x, dist);
	stepy = know_dist(p1.point.y, p2.point.y, dist);
	while (i < dist)
	{
		color = linear_gradient(dist, sqrt(pow(stepx * i, 2)
					+ pow(stepy * i, 2)), p1.color, p2.color);
		color_put(f, (t_pixel){color,
			(t_point){p1.point.x + stepx * i, p1.point.y + stepy * i, 0}});
		i += 1;
	}
}

t_color	linear_gradient(float t_dist, float cur_dist, t_color c1, t_color c2)
{
	float	percent;
	t_color	color;

	percent = cur_dist / t_dist;
	color.r = c2.r * percent + c1.r * (1 - percent);
	color.g = c2.g * percent + c1.g * (1 - percent);
	color.b = c2.b * percent + c1.b * (1 - percent);
	return (color);
}
