/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:41 by rcabezas          #+#    #+#             */
/*   Updated: 2021/07/28 13:58:28 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>

# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct s_pixel
{
	int	x;
	int y;
	int	z;
}				t_pixel;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	t_pixel	**points;
}				t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	char	*line;
	t_img	img;
	t_pixel	initial_pix;
	int		height;
	int		scale;
}				t_fdf;

int		main(int argc, char **argv);

void	parse_file(t_fdf *f, char *file);

int		count_bidimensional_array(char **s);
void	count_map_size(t_fdf *f, char *file);
void	malloc_map(t_fdf *f);

void	draw(t_fdf *f);
void	color_put(t_fdf *f, t_pixel pix);

void	bresenham(t_pixel p1, t_pixel p2);
void	assign_pixels_to_points(t_fdf *f, int i, int j, int z);
#endif