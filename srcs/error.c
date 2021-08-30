/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:03:09 by rcabezas          #+#    #+#             */
/*   Updated: 2021/08/30 19:09:01 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error_handling(int error)
{
	if (error == 1)
	{
		ft_putstr("Error - conflicting map\n");
		exit(EXIT_SUCCESS);
	}
	else if (error == 2)
	{
		ft_putstr("Error - wrong number of arguments\n");
		exit(EXIT_SUCCESS);
	}
}
