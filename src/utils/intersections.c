/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/01/22 19:21:24 by ffornes-         ###   ########.fr       */
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

void	rayhit_pl(t_vector *o, t_vector *r, t_plane *pl, t_intersection *itsc)
{
	double		t;
	double		denom;
	t_vector	v;

	denom = dot(r, pl->n_vector);
	if (denom)
	{
		v = v_subtract(pl->center, o);
		t = dot(&v, pl->n_vector) / denom;
		if (t < EPSILON)
			return ;
		if (itsc->dist < 0 || (itsc->dist >= EPSILON && t < itsc->dist))
		{
			itsc->dist = t;
			itsc->mat = pl->material;
			itsc->address = pl;
			itsc->type = PLANE;
		}
	}
	return ;
}

void	rayhit_sp(t_vector *o, t_vector *r, t_sphere *sp, t_intersection *itsc)
{
	double		coef[3];
	double		t;
	t_vector	v;

	v = v_subtract(o, sp->center);
	coef[0] = dot(r, r);
	coef[1] = 2.0 * dot(r, &v);
	coef[2] = dot(&v, &v) - sp->r_sq;
	t = quadratic_formula(coef[0], coef[1], coef[2]);
	if (t < EPSILON)
		return ;
	if (itsc->dist < 0 || (itsc->dist >= EPSILON && t < itsc->dist))
	{
		itsc->dist = t;
		itsc->mat = sp->material;
		itsc->address = sp;
		itsc->type = SPHERE;
	}
	return ;
}

static double	cy_caps(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy)
{
	double	sign;
	double		denom;
	double		t;
	t_vector	v;
	t_vector	v1;
	
	sign = -dot(ray_dir, cy->n_vector);
	if (sign == 0.0)
		return (0);
	sign /= fabs(sign);
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
	else
		return (0);
	v1 = get_itsc_p(ray_dir, ray0, t);
	if ((pow(v1.x - v.x, 2) + pow(v1.z - v.z, 2)) <= cy->r_sq)
		return (t);
	return (0);
}

static int	height_check(t_vector *o, t_vector *r, t_cylinder *cy, double t)
{
	double		h;
	t_vector	aux;
	t_vector	itsc_p;

	itsc_p = get_itsc_p(r, o, t);
	aux = v_subtract(&itsc_p, cy->center);
	h = dot(cy->n_vector, &aux);
	if (fabs(h) <= cy->half_height)
		return (1);
	return (0);
}

t_intersection	set_cy_itsc(t_vector *o, t_vector *r, t_cylinder *cy, double t[2])
{
	t_intersection	itsc;
	
	itsc.dist = -1;
	if (t[0] && (t[1] < EPSILON || t[0] < t[1]))
	{
		itsc.dist = t[0];
		itsc.type = CAP;
	}
	else if (height_check(o, r, cy, t[1]))
	{
		itsc.dist = t[1];
		itsc.type = CYLINDER;
	}
	return (itsc);
}

void	rayhit_cy(t_vector *o, t_vector *r, t_cylinder *cy, t_intersection *itsc)
{
	double			coef[3];
	double			dot_p[2];
	t_vector		v;
	double			t[2];
	t_intersection	aux_itsc;

	t[0] = cy_caps(o, r, cy);
	v = v_subtract(o, cy->center);
	dot_p[0] = dot(r, cy->n_vector);
	dot_p[1] = dot(&v, cy->n_vector);
	coef[0] = 1.0 - pow(dot_p[0], 2);
	coef[1] = 2 * (dot(r, &v) - dot_p[0] * dot_p[1]);
	coef[2] = dot(&v, &v) - pow(dot_p[1], 2) - cy->r_sq;
	t[1] = quadratic_formula(coef[0], coef[1], coef[2]);
	aux_itsc = set_cy_itsc(o, r, cy, t);
	if (aux_itsc.dist >= EPSILON && (itsc->dist < 0 
		|| (itsc->dist >= EPSILON && aux_itsc.dist < itsc->dist)))
	{
		itsc->dist = aux_itsc.dist;
		itsc->type = aux_itsc.type;
		itsc->address = cy;
		itsc->mat = cy->material;
	}	
	return ;
}
