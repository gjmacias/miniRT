#include <minirt.h>

int	ft_exit(t_info_map *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}