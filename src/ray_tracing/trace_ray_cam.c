/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:21 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 16:15:09 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

t_color	trace_ray(t_vector *ray, t_data *d)
{
	t_color	color;
	t_intersection	itsc;
	
	itsc.dist = -1;
	itsc.mat = new_material(new_color(127, 178, 255, 0), 0); // Color is skyblue
	color = calc_ambient(&itsc.mat, d->ambient_light);
	find_itsct(&itsc, ray, d);
	if (itsc.dist >= 0) // There is itsc
	{
		color = itsc.mat.color;
		// Calculate color with ambient light
		color = calc_ambient(&itsc.mat, d->ambient_light);
		/*
		aux = d->lights;
		while (aux) // Calculate vector between itsc.point and light.center
		{
			itsc_to_light(color, (t_vector ) itsc.point, (t_vector) itsc.dir, aux);
			aux = aux->next;	
		}
		*/
	}
	return (color);
}
