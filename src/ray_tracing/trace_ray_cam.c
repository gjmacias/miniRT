/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:21 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/21 19:09:49 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

static void	find_itsct(t_intersection *itsc, t_vector *ray, t_data *d)
{
	t_list			*aux;
	double			t;

	aux = d->planes;
	while (aux)
	{
		t = rayhit_pl(d->camera->center, ray, (t_plane *)aux->content);
		if (t > 0 && ((itsc->dist >= 0 && t < itsc->dist) || itsc->dist < 0))
		{
			itsc->dist = t;
			itsc->mat = ((t_plane *)aux->content)->material;
		}
		aux = aux->next;
	}
	aux = d->spheres;
	while (aux)
	{
		t = rayhit_sp(d->camera->center, ray, (t_sphere *)aux->content);
		if (t >= 0 && ((itsc->dist >= 0 && t < itsc->dist) || itsc->dist < 0))
		{
			itsc->dist = t;
			itsc->mat = ((t_sphere *)aux->content)->material;
		}
		aux = aux->next;
	}
	aux = d->cylinders;
	/*
	while (aux)
	{
		t = rayhit_cy(d->camera->center, ray, (t_cylinder *)aux->content);
		if (t >= 0 && ((itsc->dist >= 0 && t < itsc->dist) || itsc->dist < 0))
		{
			itsc->dist = t;
			itsc->mat = ((t_cylinder *)aux->content)->material;
		}
		aux = aux->next;
	}
	*/
}

t_vector	get_itsc_p(t_vector *ray, t_vector *ray_o, double t)
{
	t_vector	tmp;

	tmp = tmp_vector(ray->x * t, ray->y * t, ray->z * t);
	return (v_addition(ray_o, &tmp));
}

double	light_itscs(t_vector *p0, t_vector *p1, t_data *d, t_vector *r)
{
	t_intersection	itsc;
	t_vector		dir;
	t_vector		neg_ray;

	itsc.dist = -1;
	itsc.mat = new_material(new_color(0, 0, 0, 0), 0);
	itsc.p = NULL;
	dir = v_subtract(p1, p0);
	normalize_v(&dir);
	find_itsct(&itsc, &dir, d);
	if (itsc.dist >= EPSILON)
		return (0);
	neg_ray = neg_vector(r);
	return (angle_vectors(&dir, &neg_ray));
}

t_color	trace_ray(t_vector *ray, t_data *d)
{
	t_intersection	itsc;
	double			tmp;
	t_light			*aux;

	itsc.dist = -1;
	itsc.mat = new_material(new_color(127, 178, 255, 0), 0); // Color is skyblue
	itsc.p = ft_calloc(1, sizeof(t_vector));
	if (!itsc.p)
		clean_exit(d, 12);
//	itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
	find_itsct(&itsc, ray, d);
	if (itsc.dist >= 0) // There is itsc
	{
		*itsc.p = get_itsc_p(ray, d->camera->center, itsc.dist);
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
		aux = (t_light *)d->lights->content;
		tmp = light_itscs(itsc.p, aux->center, d, ray);\
		if (tmp)
			itsc.mat.color = calc_light(&itsc.mat, aux, tmp);
	}
	free(itsc.p);
	return (itsc.mat.color);
}
