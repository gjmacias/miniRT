/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:05:00 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/21 17:32:10 by ffornes-         ###   ########.fr       */
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
    double rad = angle * (M_PI / 180);
    double cosA = cos(rad);
    double sinA = sin(rad);
    t_vector result;

    if (axis == 'x')
	{
        result.x = vec.x;
        result.y = vec.y * cosA - vec.z * sinA;
        result.z = vec.y * sinA + vec.z * cosA;
    } 
	else if (axis == 'y')
	{
        result.x = vec.x * cosA + vec.z * sinA;
        result.y = vec.y;
        result.z = -vec.x * sinA + vec.z * cosA;
    }
	else
		return (vec);
    return (result);
}
