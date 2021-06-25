/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:41 by rcabezas          #+#    #+#             */
/*   Updated: 2021/06/25 18:06:05 by rcabezas         ###   ########.fr       */
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

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		**map_ptr;
}				t_map;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct  s_fdf
{
    void    *mlx_ptr;
    void	*win_ptr;
	t_map	*map;
	char	*line;
	t_img		img;
}               t_fdf;


int		main(int argc, char **argv);

void    parse_file(t_fdf *f, char *file);

int		count_bidimensional_array(char **s);
void	count_map_size(t_fdf *f, char *file);
void	malloc_map(t_fdf *f);

void	draw(t_fdf *f);
#endif