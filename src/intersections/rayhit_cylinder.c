/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhit_cylinder.c                                  :+:      :+:    :+:   */
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
		plane.n_vector = cy->n_vector;
	if (sign > 0.0)
	{
		new_center = *cy->top_center;
		itsc->type = TOP_CAP;
	}
	else 
	{
		new_center = *cy->bot_center;
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
	if (t[0] && (t[1] < 0 || t[0] < t[1]))
		aux_itsc.dist = t[0];
	else if (height_check(o, r, cy, t[1]))
	{
		aux_itsc.dist = t[1];
		aux_itsc.type = CYLINDER;
	}
	if (aux_itsc.dist >= EPSILON && (itsc->dist < 0 
		|| (itsc->dist >= EPSILON && aux_itsc.dist < itsc->dist)))
	{
		itsc->type = aux_itsc.type;
		if (itsc->type == BOT_CAP || itsc->type == TOP_CAP)
		{
			t_vector	v;
			t_vector	center;
			double		denom;

			denom = dot(r, cy->n_vector);
			if (aux_itsc.type == TOP_CAP)
				center = *cy->top_center;
			else if (aux_itsc.type == BOT_CAP)
				center = *cy->bot_center;
			v = v_subtract(&center, o);
			itsc->dist = dot(&v, cy->n_vector) / denom;
		}
		else
			itsc->dist = aux_itsc.dist;
		itsc->address = cy;
		itsc->mat = cy->material;
	}
	return ;
}
