/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/01/08 18:33:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include <math.h>

static double	quadratic_formula(double a, double b, double c)
{
	double	t[2];
	double	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < EPSILON)
		return (0);
	discriminant = sqrt(discriminant);
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
		if (t < 0)
			return (0);
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

static double	cy_caps(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
	double	sign;
	
	sign = -dot(ray_dir, cy->n_vector);
	if (sign == 0.0)
		return (0);
	sign /= fabs(sign);
	
	double		denom;
	double		t;
	t_vector	v;
	denom = dot(ray_dir, cy->n_vector);
	if (denom)
	{
		v = v_subtract(cy->center, ray0);
		v.y -= cy->height / 2;
		if (sign > 0.0)
			v.y += cy->height;
		t = dot(&v, cy->n_vector) / denom;
		if (t < EPSILON)
			return (0);
	}
	t_vector	v1;
	v1 = get_itsc_p(ray_dir, ray0, t);
	v1 = v_subtract(&v, &v1);
	if ((pow(v1.x, 2) + pow(v1.z, 2)) <= cy->r_sq)
		return (t);
	return (0);
}

double	rayhit_cy(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
	double		coef[3];
	double		dot_p[2];
	t_vector	v;
	double		t;

	t = cy_caps(ray0, ray_dir, cy);
	if (t)
		return (t);

	v = v_subtract(ray0, cy->center);

	dot_p[0] = dot(ray_dir, cy->n_vector);
	dot_p[1] = dot(&v, cy->n_vector);

	coef[0] = 1.0 - pow(dot_p[0], 2);
	coef[1] = 2 * (dot(ray_dir, &v) - dot_p[0] * dot_p[1]);
	coef[2] = dot(&v, &v) - pow(dot_p[1], 2) - cy->r_sq;

	t = quadratic_formula(coef[0], coef[1], coef[2]);

	if (t > 0)
	{
		// Should have cy->height already divided by 2 ?
		// Must do this with cylinder normal instead of assuming
		// 		height will be Y.
		double	max_h = cy->height / 2 + cy->center->y;
		double	min_h = cy->center->y - cy->height / 2;
		double	h;
		h = (ray_dir->y * t) + ray0->y;
		if (h != 0 && (h > max_h || h < min_h))
			return (0);
		return (t);
	}
	return (0);
}
