/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:59:16 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/21 15:17:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "miniRT_defs.h"

t_vector	v_addition(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vector	v_subtract(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

t_vector	v_product(t_vector *v1, double n)
{
	t_vector	result;

	result.x = v1->x * n;
	result.y = v1->y * n;
	result.z = v1->z * n;
	return (result);
}

double	vector_length(t_vector *vector)
{
	double	len;

	len = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	return (len);
}
