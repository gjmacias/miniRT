
#include <minirt.h>

void	ft_check_format_dotrt(t_info_map *data)
{
	if (ft_strcmpr(&data->txt[ft_strlen(data->txt) - 3], ".rt") != 0
		|| ft_strlen(data->txt) <= 3)
	{
		write(2, "Error\nBad extension\n", 20);
		exit (EXIT_FAILURE);
	}
}