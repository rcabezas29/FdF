/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:53:32 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/27 12:08:10 by rcabezas         ###   ########.fr       */
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
	
	i = 0;
	dx = p2.point.x - p1.point.x;
	dy = p2.point.y - p1.point.y;
	dist = sqrt(pow(dx, 2) + pow(dy, 2));
	stepx = dx / dist;
	stepy = dy / dist;
	while (i < dist)
	{
		color_put(f, (t_pixel){p1.color, (t_point){p1.point.x + stepx * i, p1.point.y + stepy * i, 0}});
		i += 1;
	}
}