/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:57 by rcabezas          #+#    #+#             */
/*   Updated: 2021/06/24 18:45:31 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_fdf   *f;
    
    if (argc != 2)
    {
        ft_putstr("Error - wrong number of arguments\n");
        return (0);
    }
    f = malloc(sizeof(t_fdf));
	ft_bzero(f, sizeof(t_fdf));
	f->mlx_ptr = mlx_init();
    parse_file(f, argv[1]);
}
