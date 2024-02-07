/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:05:00 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:09:05 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT_defs.h"
#include "miniRT.h"
#include <math.h>

t_vector	new_vector(double x, double y, double z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vector	tmp_vector(double x, double y, double z)
{
	t_vector	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_vector	ptop_vector(t_vector end, t_vector start)
{
	t_vector	result;

	result.x = start.x - end.x;
	result.y = start.y - end.y;
	result.z = start.z - end.z;
	return (result);
}

t_vector	change_angle(t_vector vec, double angle, char axis)
{
	double		rad;
	double		cos_a;
	double		sin_a;
	t_vector	result;

	rad = angle * (M_PI / 180);
	cos_a = cos(rad);
	sin_a = sin(rad);
	if (axis == 'x')
	{
		result.x = vec.x;
		result.y = vec.y * cos_a - vec.z * sin_a;
		result.z = vec.y * sin_a + vec.z * cos_a;
	}
	else if (axis == 'y')
	{
		result.x = vec.x * cos_a + vec.z * sin_a;
		result.y = vec.y;
		result.z = -vec.x * sin_a + vec.z * cos_a;
	}
	else
		return (vec);
	return (result);
}
