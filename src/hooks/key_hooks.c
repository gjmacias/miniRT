#include "mlx.h"
#include "miniRT_defs.h"
#include <stdlib.h>

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
