/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:21 by gmacias-          #+#    #+#             */
/*   Updated: 2024/01/23 18:52:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "libft.h"

static void	find_itsct(t_itsc *itsc, t_vector *ray, t_data *d, t_vector *center)
{
	t_list			*aux;

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

void	get_itsc_normal(t_itsc *itsc)
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
	else if (itsc->type == CYLINDER)
	{
		double		t;
		t_vector	new_center;
		t_vector	v1;
		
		new_center = *((t_cylinder *)itsc->address)->center;
		v1 = v_subtract(itsc->p, &new_center);
		t = dot(&v1, ((t_cylinder *)itsc->address)->n_vector);
		v1 = v_product(((t_cylinder *)itsc->address)->n_vector, t);
		v1 = v_addition(&new_center, &v1);
		*itsc->normal = v_subtract(itsc->p, &v1);
		normalize_v(itsc->normal);
	}
	else if (itsc->type == TOP_CAP)
		*itsc->normal = *((t_cylinder *)itsc->address)->n_vector;
	else if (itsc->type == BOT_CAP)
		*itsc->normal = *((t_cylinder *)itsc->address)->i_n_vector;
}

double	light_itscs(t_itsc *itsc_0, t_vector *p1, t_data *d, double ray_n)
{
	t_itsc		itsc_1;
	t_vector	dir;
	t_vector	magnitude;
	double		dir_n;

	itsc_1.dist = -1;
	dir = v_subtract(p1, itsc_0->p);
	magnitude = dir;
	normalize_v(&dir);
	find_itsct(&itsc_1, &dir, d, itsc_0->p);
	if (itsc_1.dist > EPSILON && itsc_1.dist < v_magnitude(&magnitude))
		return (-1.0);
	dir_n = dot(&dir, itsc_0->normal);
	if ((itsc_0->type == PLANE || itsc_0->type == TOP_CAP || itsc_0->type == BOT_CAP) && dir_n)
	{
		if (dir_n > 0.0 && ray_n > 0.0)
			return (-1.0);
		else if (dir_n <= 0.0 && ray_n < 0.0)
			return (-1.0);
		else if (dir_n == 0)
			*itsc_0->normal = v_product(itsc_0->normal, -1.0);
	}
	return (angle_vectors(&dir, itsc_0->normal));
}

t_color	trace_ray(t_vector *ray, t_data *d)
{
	t_itsc	itsc;
	double	tmp;
	t_light	*light;

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
	if (itsc.type > 0 && itsc.type < 6) // There is itsc
	{
		if (itsc.type == BOT_CAP)
			printf("FOUND BOT CAP\n");
		else if (itsc.type == TOP_CAP)
			printf("FOUND TOP CAP\n");
		*itsc.p = get_itsc_p(ray, d->camera->center, itsc.dist);
		get_itsc_normal(&itsc);
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
		if (d->lights)
		{
			light = (t_light *)d->lights->content;
			tmp = light_itscs(&itsc, light->center, d, dot(ray, itsc.normal));
			if (tmp >= 0)
				itsc.mat.color = calc_light(&itsc.mat, light, tmp);
		}
	}
	else
		itsc.mat.color = calc_ambient(&itsc.mat, d->ambient_light);
	free(itsc.p);
	free(itsc.normal);
	return (itsc.mat.color);
}
