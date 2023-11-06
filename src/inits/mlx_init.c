
#include "mlx.h"
#include "miniRT_defs.h"

void	start_mlx(t_vars *vars, t_mlx_data *d)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	d->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &d->bpps, &d->l_len, &d->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, d->img, 0, 0);
}
