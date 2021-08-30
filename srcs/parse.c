/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:49:56 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/30 19:01:12 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	parse_point(t_fdf *f, char **split, int i, int j)
{
	char	**color_split;

	color_split = ft_split(split[j], ',');
	assign_pixels_to_points(f, i, j, ft_atoi(color_split[0]));
	if (color_split[1])
		assign_color_to_points(f, i, j, color_split[1]);
	free_double_ptr(color_split);
}

void	parse_file(t_fdf *f, char *file)
{
	int		fd;
	char	**split;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handling(1);
	i = 0;
	while (get_next_line(fd, &f->line) > 0)
	{
		split = ft_split(f->line, ' ');
		j = 0;
		while (split[j] != '\0')
		{
			parse_point(f, split, i, j);
			j++;
		}
		free_double_ptr(split);
		free(f->line);
		i++;
	}
	free(f->line);
	close(fd);
}

void	init_map_scale(t_fdf *f, char *file)
{
	count_map_size(f, file);
	f->max_height = 10;
	f->scale = 800 / f->map->size_x;
	f->height = f->scale / 5;
	f->initial_pix = (t_point){1000 - 200
		* (f->map->size_y / f->map->size_x), -350, 0};
}
