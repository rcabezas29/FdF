/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:54:09 by rcabezas          #+#    #+#             */
/*   Updated: 2021/07/09 15:58:35 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_camera(t_fdf *f)
{
	f->camera.pos.x = f->map->size_x / 2;
	f->camera.pos.y = f->map->size_y / 2;
	f->camera.pos.z = 10;
	f->camera.normal = (t_vec){0, 0, -1};
}

void	get_display_points(t_fdf *f, t_vec point, int x, int y)
{
	 
}