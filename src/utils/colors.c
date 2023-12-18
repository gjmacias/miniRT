#include "miniRT.h"
#include "miniRT_defs.h"

double	color_percentage(unsigned char x)
{
	float	percentage;

	percentage = x / 255.0;
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

	result.r = color_percentage(a.color.r) * a.brightness * m->color.r;
	result.g = color_percentage(a.color.g) * a.brightness * m->color.g;
	result.b = color_percentage(a.color.b) * a.brightness * m->color.b;
	return(result);
}
