/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:52:52 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/23 18:50:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include <math.h>

double	rayhit_plane(t_vector ray0, t_vector ray_dir, t_plane *plane)
{
	double	denom;
	double	t;

	denom = scalar_product(ray_dir, plane->n_vector);
	if (denom > 0.0000001f)
	{
		t = scalar_product(v_subtract(plane->center, ray0), ray_dir) / denom;
		if (t >= 0)
			return (t);
	}
	return (0);
}

double	rayhit_sphere(t_vector *ray0, t_vector *ray_dir, t_sphere *sphere)
{
	
}
