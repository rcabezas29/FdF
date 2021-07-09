/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:57 by rcabezas          #+#    #+#             */
/*   Updated: 2021/07/09 13:56:48 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	f->camera.img.ptr = mlx_new_image(f->mlx_ptr, 1920, 1080);
	f->camera.img.addr = mlx_get_data_addr(f->camera.img.ptr,
			&f->camera.img.bpp, &f->camera.img.line_length,
			&f->camera.img.endian);
	init_camera(f);
	draw(f);
	f->win_ptr = mlx_new_window(f->mlx_ptr, 1920, 1080, "window");
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->camera.img.ptr, 0, 0);
	mlx_hook(f->win_ptr, 17, 0, exiting, f);
	mlx_loop(f->mlx_ptr);
}
