#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

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
	arraytouchar(s, color);
}
