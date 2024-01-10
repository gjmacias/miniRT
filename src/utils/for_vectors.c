/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:52 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 16:15:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	neg_vector(t_vector *v)
{
	t_vector	result;

	result.x = -(v->x);
	result.y = -(v->y);
	result.z = -(v->z);
	return (result);
}

float	angle_vectors(t_vector *a, t_vector *b)
{
	float	magnitude1;
	float	magnitude2;
	float	scalar;
	float	radians;

	magnitude1 = v_magnitude(a);
	magnitude2 = v_magnitude(b);
	scalar = dot(a, b);
	radians = (acos(scalar / (magnitude1 * magnitude2)));
	return (radians);
}

t_vector	cross_product(t_vector *a, t_vector *b)
{
	t_vector	result;

	result.x = a->y * b->z - a->z * b->y;
	result.y = a->z * b->x - a->x * b->z;
	result.z = a->x * b->y - a->y * b->x;
	if (fabs(result.x) < EPSILON && fabs(result.y) < EPSILON
		&& fabs(result.z) < EPSILON)
	{
		a->x = -1;
		a->y = 0;
		a->z = 0;
		return (cross_product(a, b));
	}
	return (result);
}

void	normalize_v(t_vector *vector)
{
	double		len;

	len = v_magnitude(vector);
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
}

t_vector	calculate_ray_direction(int x, int y, t_data *d)
{
	t_vector	result;
	double		size;
	double		work_fov;

	work_fov = 180.0 - d->camera->fov;
	size = d->height;
	if (d->width < size)
		size = d->width;
	result.x = ((2.0 * x) / d->width) - 1.0;
	result.y = 1.0 - ((2.0 * y) / d->height);
	result.z = tan((work_fov / 2) * (M_PI / 180));
	normalize_v(&result);
	result = rotate_vector_by_quaternion(result, *(d->camera->q));
	normalize_v(&result);
	return (result);
}
