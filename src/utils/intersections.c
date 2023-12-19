/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/19 13:29:34 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include <math.h>

double	rayhit_pl(t_vector *ray0, t_vector *ray_dir, t_plane *plane)
{
	double		t;
	double		denom;
	t_vector	v;

	denom = dot(ray_dir, plane->n_vector);
	if (denom)
	{
		v = v_subtract(plane->center, ray0);
		t = dot(&v, plane->n_vector) / denom;
		return (t);
	}
	return (0);
}

double	rayhit_sp(t_vector *ray0, t_vector *ray_dir, t_sphere *sp)
{
	double		coef[3];
	double		discriminant;
	t_vector	v;

	v = v_subtract(ray0, sp->center);
	coef[0] = dot(ray_dir, ray_dir);
	coef[1] = 2.0 * dot(ray_dir, &v);
	coef[2] = dot(&v, &v) - sp->r_sq;
	discriminant = pow(coef[1], 2) - 4 * coef[0] * coef[2];
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-coef[1] - sqrt(discriminant)) / (2.0 * coef[0]));
}

/*
double	rayhit_cy(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
	A = ray0;
	b = ray_dir;

	P(t) =	A + tb;
			p0 + vt;

	((ray0->x + ray_dir->x * t) * (ray0->x + ray_dir->x * t)) + ((ray0->z + ray_dir->z * t) * (ray0->z + ray_dir->z * t)) = cy->r_sq;
	pow(ray0->x, 2) + 2.0 * (ray0->x * ray_dir->x * t) + pow(ray_dir->x * t, 2) + pow(ray0->z, 2) + 2.0 * (ray0->z * ray_dir->z * t) + pow(ray_dir->z * t, 2) = cy->r_sq;
	pow(ray0->x, 2) + pow(ray0->z, 2) + 2.0 * (ray0->x * ray_dir->x * t) + pow(ray_dir->x * t, 2) + 2.0 * (ray0->z * ray_dir->z * t) + pow(ray_dir->z * t, 2) = cy->r_sq;
}
*/
