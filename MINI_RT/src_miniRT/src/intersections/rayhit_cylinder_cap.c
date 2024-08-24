/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhit_cylinder_cap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:38:14 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:25:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "intersections.h"
#include "vectors.h"
#include <math.h>

static int	set_center(t_vector *r, t_cylinder *cy, t_vector *center, \
		unsigned char *type)
{
	double	sign;

	sign = -dot(r, &cy->n_vector);
	if (sign == 0.0)
		return (0);
	sign /= fabs(sign);
	if (sign > 0.0)
	{
		*center = cy->top_center;
		*type = TOP_CAP;
	}
	else
	{
		*center = cy->bot_center;
		*type = BOT_CAP;
	}
	return (1);
}

double	cy_caps(t_vector *o, t_vector *r, t_cylinder *cy, t_itsc *itsc)
{
	t_plane			plane;
	t_vector		new_center;
	t_vector		p;
	unsigned char	type;

	if (!set_center(r, cy, &new_center, &type))
		return (-1);
	plane.n_vector = cy->n_vector;
	plane.center = new_center;
	rayhit_pl(o, r, &plane, itsc);
	if (itsc->dist < 0)
		return (-1);
	itsc->type = type;
	p = get_itsc_p(r, o, itsc->dist);
	p = v_subtract(&new_center, &p);
	return ((pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2)) <= cy->r_sq);
}
