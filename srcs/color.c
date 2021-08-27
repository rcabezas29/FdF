/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:30:23 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/27 14:11:46 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	assign_color_to_points(t_fdf *f, int i, int j, char *hex)
{
	t_color	color;

	color = hex_to_color(hex);
	f->map->points[i][j].color.r = color.r;
	f->map->points[i][j].color.g = color.g;
	f->map->points[i][j].color.b = color.b;
}

t_color	hex_to_color(char *hex)
{
	t_color	color;
	int		len;
	int		decimal;
	int		base;

	len = ft_strlen(hex);
	decimal = 0;
	base = 1;
	while (len-- > 2)
	{
		hex[len] = ft_tolower(hex[len]);
		if ('a' <= hex[len] && hex[len] <= 'f')
			decimal += (hex[len] - 'a' + 10) * base;
		if ('0' <= hex[len] && hex[len] <= '9')
			decimal += (hex[len] - '0') * base;
		base *= 16;
	}
	color.b = (decimal & 0xFF00000) >> 16;
	color.g = (decimal & 0x00FF000) >> 8;
	color.r = (decimal & 0x00000FF);
	return (color);
}
