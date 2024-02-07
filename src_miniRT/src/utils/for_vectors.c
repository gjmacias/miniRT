/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:52 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/05 19:26:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "vectors.h"

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
