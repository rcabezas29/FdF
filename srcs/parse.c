/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:49:56 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/24 13:27:05 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	parse_file(t_fdf *f, char *file)
{
	int		fd;
	char	**split;
	int		i;
	int		j;

	count_map_size(f, file);
	f->scale = 1000 / f->map->size_x;
	f->height = 10;
	f->initial_pix.x = 900;
	f->initial_pix.y = -500;
	f->initial_pix.z = 0;
	malloc_map(f);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &f->line) > 0)
	{
		split = ft_split(f->line, ' ');
		j = 0;
		while (split[j] != '\0')
		{
			assign_pixels_to_points(f, i, j, ft_atoi(split[j]));
			j++;
		}
		free(f->line);
		f->line = NULL;
		i++;
	}
	free(f->line);
	f->line = NULL;
	close(fd);
}
