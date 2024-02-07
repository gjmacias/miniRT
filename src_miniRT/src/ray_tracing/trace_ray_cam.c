/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:21 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/07 20:04:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "intersections.h"
#include "vectors.h"
#include "libft.h"

static void	find_itsct(t_itsc *itsc, t_vector *ray, t_data *d, t_vector *center)
{
	t_list	*aux;

	aux = d->planes;
	while (aux)
	{
		rayhit_pl(center, ray, (t_plane *)aux->content, itsc);
		aux = aux->next;
	}
	aux = d->spheres;
	while (aux)
	{
		rayhit_sp(center, ray, (t_sphere *)aux->content, itsc);
		aux = aux->next;
	}
	aux = d->cylinders;
	while (aux)
	{
		rayhit_cy(center, ray, (t_cylinder *)aux->content, itsc);
		aux = aux->next;
	}
}

t_vector	get_itsc_p(t_vector *ray, t_vector *ray_o, double t)
{
	t_vector	tmp;

	tmp = tmp_vector(ray->x * t, ray->y * t, ray->z * t);
	return (v_addition(ray_o, &tmp));
}

double	light_itscs(t_itsc *itsc_0, t_vector *o, t_data *d, double ray_n)
{
	t_itsc		itsc_1;
	t_vector	dir;
	double		dir_n;
	double		magnitude;

	init_itsc(&itsc_1);
	dir = v_subtract(itsc_0->p, o);
	magnitude = v_magnitude(&dir);
	normalize_v(&dir);
	find_itsct(&itsc_1, &dir, d, o);
	if (itsc_1.dist >= 0 && itsc_1.dist + EPSILON < magnitude)
		return (-1);
	dir_n = dot(&dir, itsc_0->normal);
	if (itsc_0->type == PLANE && dir_n)
	{
		if (dir_n < 0.0 && ray_n >= 0.0)
			return (-1.0);
		else if (dir_n >= 0.0 && ray_n < 0.0)
			return (-1.0);
		else if (dir_n == 0 || (dir_n > 0.0 && ray_n >= 0.0))
			*itsc_0->normal = v_product(itsc_0->normal, -1.0);
	}
	dir = v_product(&dir, -1);
	return (angle_vectors(&dir, itsc_0->normal));
}

static void	light_calcs(t_itsc *itsc, t_vector *ray, t_data *d)
{
	t_light	*light;
	double	tmp;

	*itsc->p = get_itsc_p(ray, d->camera->center, itsc->dist);
	get_itsc_normal(itsc);
	itsc->mat.color = calc_ambient(&itsc->mat, d->ambient_light);
	if (d->lights)
	{
		light = (t_light *)d->lights->content;
		tmp = light_itscs(itsc, &light->center, d, dot(ray, itsc->normal));
		if (tmp >= 0)
			itsc->mat.color = calc_light(&itsc->mat, light, tmp);
	}
}

t_color	trace_ray(t_vector *ray, t_data *d)
{
	t_itsc	itsc;

	itsc.type = 0;
	itsc.dist = -1;
	itsc.p = ft_calloc(1, sizeof(t_vector));
	if (!itsc.p)
		clean_exit(d, 12);
	itsc.normal = ft_calloc(1, sizeof(t_vector));
	if (!itsc.normal)
	{
		free(itsc.p);
		clean_exit(d, 12);
	}
	itsc.mat = new_material(new_color(127, 178, 255, 0), 0);
	find_itsct(&itsc, ray, d, d->camera->center);
	if (itsc.type > 0 && itsc.type < 6)
		light_calcs(&itsc, ray, d);
	else
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
	free(itsc.p);
	free(itsc.normal);
	return (itsc.mat.color);
}
