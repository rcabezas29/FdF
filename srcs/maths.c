/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:03:48 by rcabezas          #+#    #+#             */
/*   Updated: 2021/07/09 12:23:33 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_vec	suma_vec(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec	resta_vec(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vec	vec_mult(t_vec v1, float x)
{
	t_vec	v;

	v.x = v1.x * x;
	v.y = v1.y * x;
	v.z = v1.z * x;
	return (v);
}

t_vec	vec_div(t_vec v1, float x)
{
	t_vec	v;

	v.x = v1.x / x;
	v.y = v1.y / x;
	v.z = v1.z / x;
	return (v);
}

float	vector_length(t_vec v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vec	normalize_vec(t_vec v)
{
	t_vec	normal_vector;
	float	length;

	length = vector_length(v);
	normal_vector.x = v.x / length;
	normal_vector.y = v.y / length;
	normal_vector.z = v.z / length;
	return (normal_vector);
}

float	dot_product(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vec	mult_fac(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);