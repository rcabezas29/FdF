/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:53:32 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/26 09:55:34 by rcabezas         ###   ########.fr       */
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
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dist = sqrt(pow(dx, 2) + pow(dy, 2));
	stepx = dx / dist;
	stepy = dy / dist;
	while (i < dist)
	{
		color_put(f, (t_pixel){p1.x + stepx * i, p1.y + stepy * i, 0});
		i += 1;
	}
}