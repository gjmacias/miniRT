/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/22 17:23:18 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include <math.h>

static double	quadratic_formula(double a, double b, double c)
{
	double	t[2];

	t[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
	t[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
	if (t[0] < t[1])
		return (t[0]);
	return (t[1]);
}

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
	double		t[2];
	t_vector	v;

	v = v_subtract(ray0, sp->center);
	coef[0] = dot(ray_dir, ray_dir);
	coef[1] = 2.0 * dot(ray_dir, &v);
	coef[2] = dot(&v, &v) - sp->r_sq;
	discriminant = pow(coef[1], 2) - 4 * coef[0] * coef[2];
	if (discriminant < 0)
		return (-1.0);
	t[0] = (-coef[1] + sqrt(discriminant)) / (2.0 * coef[0]);
	t[1] = (-coef[1] - sqrt(discriminant)) / (2.0 * coef[0]);
	if ((t[0] > 0 && (t[0] < t[1])) || (t[0] < 0 && (t[0] > t[1])))
		return (t[0]);
	return (t[1]);
}

double	rayhit_cy(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
	t_vector	x;
	double		t;

	x = v_subtract(ray0, cy->center);
	t = quadratic_formula(dot(ray_dir, ray_dir) - pow(dot(ray_dir, cy->n_vector), 2), \
		2 * (dot(ray_dir, &x) - dot(ray_dir, cy->n_vector) * dot(&x, cy->n_vector)), \
		dot(&x, &x) - pow(dot(&x, cy->n_vector), 2) - cy->r_sq);
	return (t);
}
