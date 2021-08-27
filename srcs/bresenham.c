/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:53:32 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/27 13:18:38 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	bresenham(t_fdf *f, t_pixel p1, t_pixel p2)
{
	float dx;
	float dy;
	float dist;
	float stepx;
	float stepy;
	float i;
	t_color color;
	
	i = 0;
	dx = p2.point.x - p1.point.x;
	dy = p2.point.y - p1.point.y;
	dist = sqrt(pow(dx, 2) + pow(dy, 2));
	stepx = dx / dist;
	stepy = dy / dist;
	while (i < dist)
	{
		color = linear_gradient(dist, sqrt(pow(stepx * i, 2) + pow(stepy * i, 2)), p1.color, p2.color);
		color_put(f, (t_pixel){color, (t_point){p1.point.x + stepx * i, p1.point.y + stepy * i, 0}});
		i += 1;
	}
}

t_color	linear_gradient(float total_dist, float current_dist, t_color c1, t_color c2)
{
	float percent;
	t_color color;

	percent = current_dist / total_dist;
	color.r = c2.r * percent + c1.r * (1 - percent);
	color.g = c2.g * percent + c1.g * (1 - percent);
	color.b = c2.b * percent + c1.b * (1 - percent);
	return (color);
}