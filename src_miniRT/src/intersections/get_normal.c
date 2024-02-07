/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:52:15 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:26:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "vectors.h"

static void	cylinder_normal(t_itsc *itsc)
{
	double		t;
	t_vector	new_center;
	t_vector	v1;

	new_center = ((t_cylinder *)itsc->address)->center;
	v1 = v_subtract(itsc->p, &new_center);
	t = dot(&v1, &((t_cylinder *)itsc->address)->n_vector);
	v1 = v_product(&((t_cylinder *)itsc->address)->n_vector, t);
	v1 = v_addition(&new_center, &v1);
	*itsc->normal = v_subtract(itsc->p, &v1);
	normalize_v(itsc->normal);
}

void	get_itsc_normal(t_itsc *itsc)
{
	t_vector	*v;

	if (itsc->type == PLANE)
		*itsc->normal = ((t_plane *)itsc->address)->n_vector;
	else if (itsc->type == SPHERE)
	{
		v = &((t_sphere *)itsc->address)->center;
		*itsc->normal = v_subtract(itsc->p, v);
		normalize_v(itsc->normal);
	}
	else if (itsc->type == CYLINDER)
		cylinder_normal(itsc);
	else if (itsc->type == TOP_CAP)
		*itsc->normal = ((t_cylinder *)itsc->address)->n_vector;
	else if (itsc->type == BOT_CAP)
		*itsc->normal = ((t_cylinder *)itsc->address)->i_n_vector;
}
