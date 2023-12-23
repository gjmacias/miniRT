/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/22 18:21:06 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include <math.h>

static double	quadratic_formula(double a, double b, double c)
{
	double	t[2];
	double	discriminant;

	discriminant = sqrt(pow(b, 2) - 4 * a * c);
	t[0] = (-b + discriminant) / 2 * a;
	t[1] = (-b - discriminant) / 2 * a;
	if (t[0] > 0 && t[0] < t[1])
		return (t[0]);
	else if (t[1] > 0)
		return (t[1]);
	return (0);
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
	t_vector	v;

	v = v_subtract(ray0, sp->center);
	coef[0] = dot(ray_dir, ray_dir);
	coef[1] = 2.0 * dot(ray_dir, &v);
	coef[2] = dot(&v, &v) - sp->r_sq;
	return (quadratic_formula(coef[0], coef[1], coef[2]));
}

double	rayhit_cy(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
	double		coef[3];
	double		dot_p[1];
	t_vector	v;
	double		t;

	v = v_subtract(ray0, cy->center);
	dot_p[0] = dot(ray_dir, cy->n_vector);
	dot_p[1] = dot(&v, cy->n_vector);
	coef[0] = dot(ray_dir, ray_dir) - pow(dot_p[0], 2);
	coef[1] = 2 * (dot(ray_dir, &v) - dot_p[0] * dot_p[1]);
	coef[2] = dot(&v, &v) - pow(dot_p[1], 2) - cy->r_sq;
	t = quadratic_formula(coef[0], coef[1], coef[2]);
	// ToDo: Calculate collision for top & bottom caps from the cylinder
	// rn it's an infinite cylinder.
	return (t);
}
