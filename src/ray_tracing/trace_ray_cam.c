#include "miniRT.h"

static t_intersection	find_itsct(t_vector ray, t_data *d)
{
	t_intersection	itsc;
	t_list			*aux;
	double			t;

	itsc.dist = -1;
	itsc.mat = new_material(new_color(0, 0, 0, 0), 0);
	aux = d->planes;
	while (aux)
	{
		t = rayhit_pl(d->camera.center, ray, (t_plane *)aux->content);
		if (t >= 0 && ((itsc.dist >= 0 && t < itsc.dist) || itsc.dist < 0))
		{
			itsc.dist = t;
			itsc.mat = ((t_plane *)aux->content)->material;
		}
		aux = aux->next;
	}
	aux = d->spheres;
	while (aux)
	{
		t = rayhit_sp(d->camera.center, ray, (t_sphere *)aux->content);
		if (t >= 0 && ((itsc.dist >= 0 && t < itsc.dist) || itsc.dist < 0))
		{
			itsc.dist = t;
			itsc.mat = ((t_sphere *)aux->content)->material;
		}
		aux = aux->next;
	}
	return (itsc);
}

t_color	trace_ray(t_vector ray, t_data *d)
{
	t_color	color;
	t_intersection	itsct;
	
	color = new_color(0, 0, 0, 0);
	itsct = find_itsct(ray, d);
	if (itsct.dist >= 0)
		color = itsct.mat.color;
	return (color);
}
