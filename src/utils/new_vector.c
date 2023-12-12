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

double	change_angle(double x, double y, double a)
{
	double res;
	double rad;
	double rad_plus;

	rad_plus = a * (M_PI / 180);
	rad = atan(y / x);
	rad = rad + rad_plus;
	res = 1 * cos(rad);
	return (res);
}

t_vector change_n_vec(t_vector n_vec, char *s)
{
	if(ft_strncmp(s, "UP", 3) == 0)
	{
		n_vec.z = change_angle(n_vec.z, n_vec.y, 5.0);
		n_vec.y = sqrt(1 - pow(n_vec.z, 2));
	}
	else if(ft_strncmp(s, "DOWN", 5) == 0)
	{
		n_vec.z = change_angle(n_vec.z, n_vec.y, -5.0);
		n_vec.y = sqrt(1 - pow(n_vec.z, 2));
	}
	else if(ft_strncmp(s, "LEFT", 5) == 0)
	{
		n_vec.z = change_angle(n_vec.z, n_vec.x, 5.0);
		n_vec.x = sqrt(1 - pow(n_vec.z, 2));
	}
	else if(ft_strncmp(s, "RIGHT", 6) == 0)
	{
		n_vec.z = change_angle(n_vec.z, n_vec.x, -5.0);
		n_vec.x = sqrt(1 - pow(n_vec.z, 2));
	}
	print_vector(n_vec);
	return (n_vec);
}