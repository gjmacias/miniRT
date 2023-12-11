#include "miniRT.h"

t_color	trace_ray(t_vector ray, int min, int max)
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
	min = max;
	t_color	color;

	color.r = (int)(ray.x + ray.z) % 255;
	color.g = (int)(ray.x - ray.z) % 255;
	color.b = (int)(ray.x) % 255;
	/*(void)ray;
	color.r = 255;
	color.g = 255;
	color.b = 255;*/
	color.a = 0;
	return (color);
}