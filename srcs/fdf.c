/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:57 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/27 09:38:22 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	exiting(t_fdf *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fdf	*f;

	if (argc != 2)
	{
		ft_putstr("Error - wrong number of arguments\n");
		return (0);
	}
	f = ft_calloc(sizeof(t_fdf), 1);
	f->map = ft_calloc(sizeof(t_map), 1);
	f->mlx_ptr = mlx_init();
	parse_file(f, argv[1]);
	f->img.ptr = mlx_new_image(f->mlx_ptr, 1920, 1080);
	f->img.addr = (unsigned char *)mlx_get_data_addr(f->img.ptr,
			&f->img.bpp, &f->img.line_length,
			&f->img.endian);
	draw(f);
	f->win_ptr = mlx_new_window(f->mlx_ptr, 1920, 1080, "window");
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.ptr, 0, 0);
	mlx_hook(f->win_ptr, 17, 0, exiting, f);
	mlx_loop(f->mlx_ptr);
}
