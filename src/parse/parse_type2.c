#include "miniRT.h"
#include "miniRT_defs.h"
#include "libft.h"

void	p_plane(char **arguments, t_data *p)
{
	p->info.planes += 1;
	input_possition(arguments[1], p);
	input_vector(arguments[2], p);
	input_color(arguments[3], p);
	if (arguments[4])
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > too many arguments\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	p_sphere(char **arguments, t_data *p)
{
	p->info.spheres += 1;
	input_possition(arguments[1], p);
	input_diameter(arguments[2], p);
	input_color(arguments[3], p);
	if (arguments[4])
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > too many arguments\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	p_clinder(char **arguments, t_data *p)
{
	p->info.cylinders += 1;
	input_possition(arguments[1], p);
	input_vector(arguments[2], p);
	input_diameter(arguments[3], p);
	input_height(arguments[4], p);
	input_color(arguments[5], p);
	if (arguments[6])
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > too many arguments\n", 23);
		exit(EXIT_FAILURE);
	}
}
