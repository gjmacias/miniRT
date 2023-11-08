#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_brightness(char *s, t_data *p, double *bright)
{
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Double brightness\n", 37);
		else
			write(2, " > Need parameter: brightness\n", 31);
		exit(EXIT_FAILURE);
	}
	(*bright) = ft_strtod(s);
}

void	input_possition(char *s, t_data *p, t_vector *center)
{
	if (!s || checker_uchar(s))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Vector possition\n", 36);
		else
			write(2, " > Need parameter: possition\n", 30);
		exit(EXIT_FAILURE);
	}
	arraytodouble(s, center);
}

void	input_vector(char *s, t_data *p, t_vector *vector)
{
	if (!s || checker_array_double(s))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Vector\n", 26);
		else
			write(2, " > Need parameter: Vector\n", 27);
		exit(EXIT_FAILURE);
	}
	arraytodouble(s, vector);
}

void	input_diameter(char *s, t_data *p, double *diameter)
{
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		if (s)
			write(2, " > Bad parameter: Double diameter\n", 35);
		else
			write(2, " > Need parameter: diameter\n", 29);
		exit(EXIT_FAILURE);
	}
	(*diameter) = ft_strtod(s);
}
