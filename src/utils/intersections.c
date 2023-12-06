/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/06 16:02:28 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include <math.h>

double	rayhit_pl(t_vector ray0, t_vector ray_dir, t_plane *plane)
{
	double	denom;
	double	t;

	denom = dot(ray_dir, plane->n_vector);
	if (denom > 0.0000001f)
	{
		t = dot(v_subtract(plane->center, ray0), ray_dir) / denom;
		if (t >= 0)
			return (t);
	}
	return (0);
}

double	rayhit_sp(t_vector ray0, t_vector ray_dir, t_sphere *sp)
{
	double	coefs[3];
	double	r;
	double	discriminant;


	r = sp->diameter / 2;
	coef[0] = dot(ray_dir, ray_dir);
	coef[1] = 2 * dot(ray_dir, v_subtract(ray0, sp->center));
	coef[2] = dot(v_subtract(ray0, c), v_subtract(ray0, c)) - pow(r, 2);
	discriminant = pow(coef[1], 2) - 4 * coef[0] * coef[2];
	if (discriminant > 0)
		printf("Found 2 intersections with sphere\n");
	else if (discriminant < 0)
		printf("Found 0 intersections with sphere\n");
	else
		printf("Found 1 intersection with sphere\n");
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-coef[1] - sqrt(discriminant)) / (2.0 * coef[0]));
}

double	rayhit_cy(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
		
}
