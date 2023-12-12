/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:05:00 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/21 13:13:55 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT_defs.h"
#include "miniRT.h"
#include <math.h>

t_vector	*new_vector(double x, double y, double z)
{
	t_vector	*out;

	out = ft_calloc(sizeof(t_vector), 1);
	if (!out)
		return (NULL);
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
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

t_vector change_n_vec(t_vector n_vec, char *s)
{
	if(ft_strncmp(s, "UP", 3) == 0)
		n_vec = change_angle(n_vec, -5.0, 'x');
	else if(ft_strncmp(s, "DOWN", 5) == 0)
		n_vec = change_angle(n_vec, 5.0, 'x');
	else if(ft_strncmp(s, "LEFT", 5) == 0)
		n_vec = change_angle(n_vec, 5.0, 'y');
	else if(ft_strncmp(s, "RIGHT", 6) == 0)
		n_vec = change_angle(n_vec, -5.0, 'y');
	n_vec = normalize_v(n_vec);
	print_vector(n_vec);
	return (n_vec);
}