#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "miniRT_defs.h"

int	ft_exit(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}