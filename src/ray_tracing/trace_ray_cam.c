/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:21 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/22 19:37:00 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

static void	find_itsct(t_intersection *itsc, t_vector *ray, t_data *d, t_vector *center)
{
	t_list			*aux;
	double			t;

	aux = d->planes;
	while (aux)
	{
		t = rayhit_pl(center, ray, (t_plane *)aux->content);
		if (t > EPSILON && ((itsc->dist >= EPSILON && t < itsc->dist) || itsc->dist < 0))
		{
			itsc->dist = t;
			itsc->mat = ((t_plane *)aux->content)->material;
			itsc->address = (t_plane *)aux->content;
			itsc->type = 1;
		}
		aux = aux->next;
	}
	aux = d->spheres;
	while (aux)
	{
		t = rayhit_sp(center, ray, (t_sphere *)aux->content);
		if (t >= EPSILON && ((itsc->dist >= EPSILON && t < itsc->dist) || itsc->dist < 0))
		{
			itsc->dist = t;
			itsc->mat = ((t_sphere *)aux->content)->material;
			itsc->address = (t_sphere *)aux->content;
			itsc->type = 2;
		}
		aux = aux->next;
	}
	aux = d->cylinders;
	while (aux)
	{
		t = rayhit_cy(center, ray, (t_cylinder *)aux->content);
		if (t >= 0 && ((itsc->dist >= 0 && t < itsc->dist) || itsc->dist < 0))
		{
			itsc->dist = t;
			itsc->mat = ((t_cylinder *)aux->content)->material;
			itsc->address = (t_cylinder *)aux->content;
			itsc->type = 3;
		}
		aux = aux->next;
	}
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
	t_vector		magnitude;

	itsc.dist = -1;
	itsc.type = 0;
	itsc.p = NULL;
	itsc.address = NULL;
	dir = v_subtract(p1, p0);
	magnitude = dir;
	normalize_v(&dir);
	find_itsct(&itsc, &dir, d, p0);
	if (itsc.dist > EPSILON && itsc.dist < v_magnitude(&magnitude))
		return (0);
	return (angle_vectors(&dir, r));
}

void	get_itsc_normal(t_intersection *itsc)
{
	t_vector	*v;

	if (itsc->type == PLANE)
		*itsc->normal = *((t_plane *)itsc->address)->n_vector;
	else if (itsc->type == SPHERE)
	{
		v = ((t_sphere *)itsc->address)->center;
		*itsc->normal = v_subtract(itsc->p, v);
		normalize_v(itsc->normal);
	}
	else if (itsc->type == CYLINDER) // ToDo
	{
		printf("XD!");
	}
}

t_color	trace_ray(t_vector *ray, t_data *d)
{
	t_intersection	itsc;
	double			tmp;
	t_light			*aux;

	itsc.type = 0;
	itsc.address = NULL;
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
	itsc.mat = new_material(new_color(127, 178, 255, 0), 0); // Color is skyblue
	find_itsct(&itsc, ray, d, d->camera->center);
	if (itsc.type > 0) // There is itsc
	{
		*itsc.p = get_itsc_p(ray, d->camera->center, itsc.dist);
		get_itsc_normal(&itsc);
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
		if (d->lights)
		{
			aux = (t_light *)d->lights->content;
			tmp = light_itscs(itsc.p, aux->center, d, itsc.normal);
			if (tmp > 0)
				itsc.mat.color = calc_light(&itsc.mat, aux, tmp);
//			else
//				itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
		}
	}
	else
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
	free(itsc.p);
	free(itsc.normal);
	return (itsc.mat.color);
}
