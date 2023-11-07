#include "miniRT.h"
#include "miniRT_defs.h"
#include "libft.h"

void	p_ambient_ligth(char **arguments, t_data *p)
{
	p->info.ambient_light += 1;
	if (p->info.ambient_light > 1)
	{
		write(2, "Error: ambient ligth < ", 24);
		write(2, arguments[0], ft_strlen(arguments[0]));
		write(2, " > is DUPLICATED\n", 18);
		exit(EXIT_FAILURE);
	}
	input_brightness(arguments[1], p);
	input_color(arguments[2], p);
	if (arguments[3])
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > too many arguments\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	p_camera(char **arguments, t_data *p)
{
	p->info.camera += 1;
	if (p->info.camera > 1)
	{
		write(2, "Error: camera < ", 17);
		write(2, arguments[0], ft_strlen(arguments[0]));
		write(2, " > is DUPLICATED\n", 18);
		exit(EXIT_FAILURE);
	}
	input_possition(arguments[1], p);
	input_vector(arguments[2], p);
	input_FOV(arguments[3], p);
	if (arguments[4])
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > too many arguments\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	p_ligths(char **arguments, t_data *p)
{
	p->info.lights += 1;
	input_possition(arguments[1], p);
	input_brightness(arguments[2], p);
	input_color(arguments[3], p);
	if (arguments[4])
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > too many arguments\n", 23);
		exit(EXIT_FAILURE);
	}
}

void	parse_type(char **arguments, t_data *p)
{
	init_parameters_info(p);
	printpp(arguments);
	if (ft_strlen(arguments[0]) == 1)
	{
		if (ft_strncmp("A", arguments[0], 2) == 0)
			p_ambient_ligth(arguments, p);
		else if (ft_strncmp("C", arguments[0], 2) == 0)
			p_camera(arguments, p);
		else if (ft_strncmp("L", arguments[0], 2) == 0)
			p_ligths(arguments, p);
	}
	else if (ft_strlen(arguments[0]) == 2)
	{
		if (ft_strncmp("pl", arguments[0], 3) == 0)
			p_plane(arguments, p);
		else if (ft_strncmp("sp", arguments[0], 3) == 0)
			p_sphere(arguments, p);
		else if (ft_strncmp("cy", arguments[0], 3) == 0)
			p_clinder(arguments, p);
	}
	else
	{
		write(2, "Error: < ", 10);
		write(2, arguments[0], ft_strlen(arguments[0]));
		write(2, " > is a invalid input\n", 23);
		exit(EXIT_FAILURE);
	}
}
