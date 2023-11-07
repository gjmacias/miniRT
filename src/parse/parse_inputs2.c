#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_fov(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: FOV\n", 24);
		exit(EXIT_FAILURE);
	}
}

void	input_height(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: height\n", 27);
		exit(EXIT_FAILURE);
	}
}

void	input_color(char *arg, t_data *p)
{
	if (!arg)
	{
		write(2, "Error in line: < ", 18);
		write(2, ft_itoa(p->line), ft_strlen(ft_itoa(p->line)));
		write(2, " > Need parameter: color\n", 26);
		exit(EXIT_FAILURE);
	}
}
