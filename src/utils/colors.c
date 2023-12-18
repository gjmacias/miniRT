#include "miniRT.h"
#include "miniRT_defs.h"

double	color_percentage(unsigned char x)
{
	float	percentage;

	percentage = x / 255;
	return (percentage);
}

unsigned char percentage_color(double percentage)
{
	unsigned char	result;

	result = percentage * (256 - EPSILON);
	return (result);
}

t_color	calc_ambient(t_material *m, t_ambiental a)
{
	t_color result;

	result.r = percentage_color(color_percentage(a.color.r) * a.brightness * color_percentage(m->color.r));
	result.g = percentage_color(color_percentage(a.color.g) * a.brightness * color_percentage(m->color.g));
	result.b = percentage_color(color_percentage(a.color.b) * a.brightness * color_percentage(m->color.b));
	return(result);
}