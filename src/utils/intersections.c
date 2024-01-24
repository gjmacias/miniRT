/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/01/23 19:25:22 by ffornes-         ###   ########.fr       */
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
	t[0] = (-b + discriminant) / (2 * a);
	t[1] = (-b - discriminant) / (2 * a);
	if (t[0] >= 0 && t[0] < t[1])
		return (t[0]);
	else if (t[1] >= 0)
		return (t[1]);
	return (-1);
}

void	rayhit_pl(t_vector *o, t_vector *r, t_plane *pl, t_itsc *itsc)
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

void	rayhit_sp(t_vector *o, t_vector *r, t_sphere *sp, t_itsc *itsc)
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

double	cy_caps(t_vector *o, t_vector *r, t_cylinder *cy, t_itsc *itsc)
{
	t_plane		plane;
	double		sign;
	t_vector	new_center;
	t_itsc		aux;
	t_vector	p;
	double		t;

	sign = -dot(r, cy->n_vector);
	if (sign == 0.0)
		return (0);
	sign /= fabs(sign);
	if (sign > 0)
	{
		new_center = *cy->top_center;
		plane.n_vector = cy->n_vector;
		itsc->type = TOP_CAP;
	}
	else
	{
		new_center = *cy->bot_center;
		plane.n_vector = cy->i_n_vector;
		itsc->type = BOT_CAP;
	}
	plane.center = &new_center;
	aux.dist = -1;
	rayhit_pl(o, r, &plane, &aux);
	if (aux.dist < 0)
		return (0);	
	p = get_itsc_p(r, o, aux.dist);
	p = v_subtract(&new_center, &p);
	t = pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2);
	return (t <= cy->r_sq);
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

void	rayhit_cy(t_vector *o, t_vector *r, t_cylinder *cy, t_itsc *itsc)
{
	double		coef[3];
	double		dot_p[2];
	t_vector	v;
	double		t[2];
	t_itsc		aux_itsc;
	
	init_itsc(&aux_itsc);
	t[0] = cy_caps(o, r, cy, &aux_itsc);
	v = v_subtract(o, cy->center);
	dot_p[0] = dot(r, cy->n_vector);
	dot_p[1] = dot(&v, cy->n_vector);
	coef[0] = 1.0 - pow(dot_p[0], 2);
	coef[1] = 2 * (dot(r, &v) - dot_p[0] * dot_p[1]);
	coef[2] = dot(&v, &v) - pow(dot_p[1], 2) - cy->r_sq;
	t[1] = quadratic_formula(coef[0], coef[1], coef[2]);

	if (t[0] && (t[1] < EPSILON || t[0] < t[1]))
		aux_itsc.dist = t[0];
	else if (height_check(o, r, cy, t[1]))
	{
		aux_itsc.dist = t[1];
		aux_itsc.type = CYLINDER;
	}
	else
		return ;
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
