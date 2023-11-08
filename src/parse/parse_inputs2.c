#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_array_uchar(char *s, t_color *color)
{
	int	x[6];

	x[0] = 0;
	x[5] = 1;
	x[4] = 255;
	x[1] = ft_strtouc(s);
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			x[5] += 1;
			x[x[5]] = ft_strtouc(&s[x[0] + 1]);
		}
		x[0] += 1;
	}
	color->r = x[1];
	color->g = x[2];
	color->b = x[3];
	color->a = x[4];
}

void	input_array_double(char *s, t_vector *vector)
{
	int	x[5];

	x[0] = 0;
	x[4] = 1;
	x[1] = checker_double(s , ',');
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			x[4] += 1;
			x[x[4]] = checker_double(&s[x[0] + 1], ',');
		}
		x[0] += 1;
	}
	vector->x = x[1];
	vector->y = x[2];
	vector->z = x[3];
}

void	input_fov(char *s, t_data *p, double *fov)
{
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Double FOV\n", 30);
		else
			write(2, " > Need parameter: FOV\n", 24);
		exit(EXIT_FAILURE);
	}
	(*fov) = ft_strtod(s);
}

void	input_height(char *s, t_data *p, double *height)
{
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Double height\n", 33);
		else
			write(2, " > Need parameter: height\n", 27);
		exit(EXIT_FAILURE);
	}
	(*height) = ft_strtod(s);
}

void	input_color(char *s, t_data *p, t_color *color)
{
	if (!s || checker_uchar(s))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Vector color\n", 32);
		else
			write(2, " > Need parameter: color\n", 26);
		exit(EXIT_FAILURE);
	}
	input_array_uchar(s, color);
}
