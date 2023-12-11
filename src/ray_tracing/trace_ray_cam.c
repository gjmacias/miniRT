#include "miniRT.h"

t_color	trace_ray(t_vector ray, t_data *d)
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
	double	t;
	t_list	*aux;
	
	color.r = 0;
	color.g = 0;
	color.b = 0;
	aux = d->planes;
	while (aux)
	{
		t = rayhit_pl(d->camera.center, ray, (t_plane *)aux->content);
		if (t)
		{
			color.r = ((t_plane *)aux->content)->material.color.r;
			color.g = ((t_plane *)aux->content)->material.color.g;
			color.b = ((t_plane *)aux->content)->material.color.b;
		}
		aux = aux->next;
	}
	aux = d->spheres;
	while (aux)
	{
		t = rayhit_sp(d->camera.center, ray, (t_sphere *)aux->content);
		if (t > -1)
		{
			color.r = ((t_sphere *)aux->content)->material.color.r;
			color.g = ((t_sphere *)aux->content)->material.color.g;
			color.b = ((t_sphere *)aux->content)->material.color.b;
		}
		aux = aux->next;
	}
	color.a = 0;

//	color.r = (int)(ray.x + ray.z) % 255;
//	color.g = (int)(ray.x - ray.z) % 255;
//	color.b = (int)(ray.x) % 255;
	/*(void)ray;
	color.r = 255;
	color.g = 255;
	color.b = 255;*/
	return (color);
}
