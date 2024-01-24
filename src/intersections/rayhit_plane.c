/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhit_plane.c                                     :+:      :+:    :+:   */
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
