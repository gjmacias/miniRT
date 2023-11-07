#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_brightness(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: brightness\n", 31);
		exit(EXIT_FAILURE);
	}
}

void	input_possition(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: possition\n", 30);
		exit(EXIT_FAILURE);
	}
}

void	input_vector(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: vector\n", 27);
		exit(EXIT_FAILURE);
	}
}

void	input_diameter(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: diameter\n", 29);
		exit(EXIT_FAILURE);
	}
}
