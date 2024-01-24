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
