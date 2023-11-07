#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "miniRT_defs.h"

void	check_format_dotrt(char *txt)
{
	if (ft_strncmp(&txt[ft_strlen(txt) - 3], ".rt", 3) != 0
		|| ft_strlen(txt) <= 3)
	{
		write(2, "Error: Bad extension: Needs to end with <.rt>\n", 47);
		exit (EXIT_FAILURE);
	}
}

void	checker_main(char **arguments)
{
	check_format_dotrt(arguments[1]);
}
