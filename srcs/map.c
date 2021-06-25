/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:09:17 by rcabezas          #+#    #+#             */
/*   Updated: 2021/06/25 10:57:25 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_map(t_fdf *f)
{
	int i;

	i = 0;
	f->map->map_ptr = malloc(sizeof(int *) * f->map->size_y);
	while (i < f->map->size_y)
	{
		f->map->map_ptr[i] = malloc(sizeof(int) * f->map->size_x);
		i++;
	}
}

void	count_map_size(t_fdf *f, char *file)
{
    int		fd;
	int		i;
	char	**split;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &f->line) > 0)
	{
		split = ft_split(f->line, ' ');
		if (f->map->size_x == 0)
		{
			f->map->size_x = count_bidimensional_array(split);
		}
		else if (count_bidimensional_array(split) != f->map->size_x)
		{
			ft_putstr("Error - conflicting map\n");
			exit(EXIT_SUCCESS);
		}
		free(f->line);
		f->line = NULL;
        i++;
	}
	free(f->line);
	f->line = NULL;
	close(fd);
	f->map->size_y = i;
}

int	count_bidimensional_array(char **s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}