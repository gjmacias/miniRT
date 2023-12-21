#include "miniRT.h"
#include "miniRT_defs.h"

double	color_percentage(unsigned char x)
{
	double	percentage;

	percentage = x / 255.0;
	return (percentage);
}

unsigned char percentage_color(double percentage)
{
	unsigned char	result;

	result = percentage * (256 - EPSILON);
	return (result);
}

double	rad_percentage(double rad)
{
	double	percentage;

	if (rad < (M_PI / 2))
		percentage = rad / (M_PI / 2);
	else
		percentage = 1.0;
	return (percentage);
}

t_color	calc_ambient(t_material *m, t_ambiental a)
{
	t_color result;

	result.r = color_percentage(a.color.r) * a.brightness * m->color.r;
	result.g = color_percentage(a.color.g) * a.brightness * m->color.g;
	result.b = color_percentage(a.color.b) * a.brightness * m->color.b;
	return(result);
}

t_color	calc_light(t_material *m, t_light *l, double rad)
{
	t_color			result;
	unsigned char	tmp;

	tmp = l->color.r * l->brightness * rad_percentage(rad);
	if (m->color.r + tmp > 255)
		result.r = 255;
	else
		result.r = m->color.r + tmp;
	tmp = l->color.g * l->brightness * rad_percentage(rad);
	if (m->color.g + tmp > 255)
		result.g = 255;
	else
		result.g = m->color.g + tmp;
	tmp = l->color.b * l->brightness * rad_percentage(rad);
	if (m->color.b + tmp > 255)
		result.b = 255;
	else
		result.b = m->color.b + tmp;
	return(result);
}