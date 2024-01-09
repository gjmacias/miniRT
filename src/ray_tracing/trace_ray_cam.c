/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:21 by gmacias-          #+#    #+#             */
/*   Updated: 2024/01/08 14:57:08 by ffornes-         ###   ########.fr       */
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
		if (t >= EPSILON && ((itsc->dist >= EPSILON && t < itsc->dist) || itsc->dist < 0))
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
	else if (itsc->type == CYLINDER) // ToDo: Differenciate cap-cylinder hits
	{
		double		t;
		t_vector	new_center;
		t_vector	v1;
		
		// This is for the cylinder in general NOT the caps
		new_center = *((t_cylinder *)itsc->address)->center;
		new_center.y -= ((t_cylinder *)itsc->address)->height / 2;
		v1 = v_subtract(itsc->p, &new_center);
		t = dot(&v1, ((t_cylinder *)itsc->address)->n_vector);
		v1 = v_product(((t_cylinder *)itsc->address)->n_vector, t);
		v1 = v_addition(&new_center, &v1);
		*itsc->normal = v_subtract(itsc->p, &v1);
		normalize_v(itsc->normal);
	}
}

double	light_itscs(t_intersection *itsc_0, t_vector *p1, t_data *d, double ray_n)
{
	t_intersection	itsc_1;
	t_vector		dir;
	t_vector		magnitude;
	double			dir_n;

	itsc_1.dist = -1;
	dir = v_subtract(p1, itsc_0->p);
	magnitude = dir;
	normalize_v(&dir);
	find_itsct(&itsc_1, &dir, d, itsc_0->p);
	if (itsc_1.dist > EPSILON && itsc_1.dist < v_magnitude(&magnitude))
		return (0.0);
	dir_n = dot(&dir, itsc_0->normal);
	if (itsc_0->type == PLANE && dir_n)
	{
		if (dir_n > 0.0 )
		{
			if (ray_n > 0.0)
				return (0);
		}
		else if (ray_n < 0.0)
			return (0);
		else
			*itsc_0->normal = v_product(itsc_0->normal, -1.0);
	}
	return (angle_vectors(&dir, itsc_0->normal));
}

t_color	trace_ray(t_vector *ray, t_data *d)
{
	t_intersection	itsc;
	double			tmp;
	t_light			*light;

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
	itsc.mat = new_material(new_color(127, 178, 255, 0), 0); // Background color
	find_itsct(&itsc, ray, d, d->camera->center);
	if (itsc.type > 0) // There is itsc
	{
		*itsc.p = get_itsc_p(ray, d->camera->center, itsc.dist);
		get_itsc_normal(&itsc);
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
		if (d->lights)
		{
			light = (t_light *)d->lights->content;
			tmp = light_itscs(&itsc, light->center, d, dot(ray, itsc.normal));
			if (tmp > 0)
				itsc.mat.color = calc_light(&itsc.mat, light, tmp);
		}
	}
	else
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
	free(itsc.p);
	free(itsc.normal);
	return (itsc.mat.color);
}
