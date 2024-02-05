/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhit_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:25:27 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "intersections.h"
#include "vectors.h"
#include <math.h>

static int	height_check(t_vector *o, t_vector *r, t_cylinder *cy, double t)
{
	double		h;
	t_vector	aux;
	t_vector	itsc_p;

	itsc_p = get_itsc_p(r, o, t);
	aux = v_subtract(&itsc_p, &cy->center);
	h = dot(&cy->n_vector, &aux);
	if (fabs(h) <= cy->half_height)
		return (1);
	return (0);
}

static double	main_itsc(t_vector *o, t_vector *r, t_cylinder *cy)
{
	double		coef[3];
	double		dot_p[2];
	t_vector	v;

	v = v_subtract(o, &cy->center);
	dot_p[0] = dot(r, &cy->n_vector);
	dot_p[1] = dot(&v, &cy->n_vector);
	coef[0] = 1.0 - pow(dot_p[0], 2);
	coef[1] = 2 * (dot(r, &v) - dot_p[0] * dot_p[1]);
	coef[2] = dot(&v, &v) - pow(dot_p[1], 2) - cy->r_sq;
	return (quadratic_formula(coef[0], coef[1], coef[2]));
}

static void	set_itsc(t_itsc *itsc, t_itsc *aux_itsc, t_itsc *cap_itsc, \
		t_cylinder *cy)
{
	if (aux_itsc->dist >= EPSILON && (itsc->dist < 0
			|| (itsc->dist >= EPSILON && aux_itsc->dist < itsc->dist)))
	{
		itsc->type = aux_itsc->type;
		if (itsc->type == BOT_CAP || itsc->type == TOP_CAP)
			itsc->dist = cap_itsc->dist;
		else
			itsc->dist = aux_itsc->dist;
		itsc->address = cy;
		itsc->mat = cy->material;
	}
}

void	rayhit_cy(t_vector *o, t_vector *r, t_cylinder *cy, t_itsc *itsc)
{
	double		t[2];
	t_itsc		aux_itsc;
	t_itsc		cap_itsc;

	init_itsc(&aux_itsc);
	init_itsc(&cap_itsc);
	t[0] = cy_caps(o, r, cy, &cap_itsc);
	t[1] = main_itsc(o, r, cy);
	if (t[0] >= EPSILON && (t[0] <= t[1] || t[1] < EPSILON))
	{
		aux_itsc.type = cap_itsc.type;
		aux_itsc.dist = cap_itsc.dist;
	}
	else if (height_check(o, r, cy, t[1]) && t[1] >= EPSILON)
	{
		aux_itsc.type = CYLINDER;
		aux_itsc.dist = t[1];
	}
	set_itsc(itsc, &aux_itsc, &cap_itsc, cy);
	return ;
}
