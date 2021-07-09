/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:41 by rcabezas          #+#    #+#             */
/*   Updated: 2021/07/09 15:53:39 by rcabezas         ###   ########.fr       */
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

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vec
{
	int	x;
	int	y;
	int z;
}				t_vec;

typedef struct s_cam
{
	t_vec	pos;
	t_vec	**cam_points;
	t_img	img;
	t_vec	normal;
}				t_cam;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	t_vec	**points;
}				t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	char	*line;
	t_cam	camera;
}				t_fdf;

int		main(int argc, char **argv);

void	parse_file(t_fdf *f, char *file);

int		count_bidimensional_array(char **s);
void	count_map_size(t_fdf *f, char *file);
void	malloc_map(t_fdf *f);

void	draw(t_fdf *f);
void	color_put(t_fdf *f, int x, int y);

float	vector_length(t_vec v);
t_vec	normalize_vec(t_vec v);
float	dot_product(t_vec v1, t_vec v2);
t_vec	cross_product(t_vec v1, t_vec v2);
t_vec	suma_vec(t_vec v1, t_vec v2);
t_vec	resta_vec(t_vec v1, t_vec v2);
t_vec	vec_mult(t_vec v1, float x);
t_vec	vec_div(t_vec v1, float x);
t_vec	mult_fac(t_vec v1, t_vec v2);

void    init_camera(t_fdf *f);
void    display_points(t_fdf *f, t_vec point, int x, int y);
#endif