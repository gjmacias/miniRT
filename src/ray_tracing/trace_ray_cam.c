#include "miniRT.h"

static t_intersection	find_itsct(t_vector *ray, t_data *d)
{
	t_intersection	itsc;
	t_list			*aux;
	double			t;

	itsc.dist = -1;
	itsc.mat = new_material(new_color(127, 178, 255, 0), 0);
	aux = d->planes;
	while (aux)
	{
		t = rayhit_pl(&d->camera.center, ray, (t_plane *)aux->content);
		if (t > 0 && ((itsc.dist >= 0 && t < itsc.dist) || itsc.dist < 0))
		{
			itsc.dist = t;
			itsc.mat = ((t_plane *)aux->content)->material;
		}
		aux = aux->next;
	}
	aux = d->spheres;
	while (aux)
	{
		t = rayhit_sp(&d->camera.center, ray, (t_sphere *)aux->content);
		if (t >= 0 && ((itsc.dist >= 0 && t < itsc.dist) || itsc.dist < 0))
		{
			itsc.dist = t;
			itsc.mat = ((t_sphere *)aux->content)->material;
		}
		aux = aux->next;
	}
	return (itsc);
}

t_color	trace_ray(t_vector *ray, t_data *d)
{
	/*t_Intersection	itsct;
	t_vector		p;
	t_vector		dt;

	itsct = clst_intsct(camera()->pos, ray, t_min, t_max);
	dt = vector_mult(ray, itsct.clst_t);
	p = vector_add(camera()->pos, dt);
	if (itsct.clst_cy != NULL)
		return (cyl_color(itsct, ray, p, dt));
	if (itsct.clst_pl != NULL)
		return (pln_color(itsct, ray, p, dt));
	if (itsct.clst_sp != NULL)
		return (sphr_color(itsct, ray, p, dt));
	return (background_color(ray));*/

//	min = max;


	t_color	color;
	t_intersection	itsct;
	
	itsct = find_itsct(ray, d);
	color = itsct.mat.color;

//	color.r = (int)(ray.x + ray.z) % 255;
//	color.g = (int)(ray.x - ray.z) % 255;
//	color.b = (int)(ray.x) % 255;
	return (color);
}
