#include "miniRT.h"

t_4Matrix	pos_camera(t_camera *c)
{
	t_4Matrix	matrix;

	init_matrix(&matrix);
	create_pos_matrix(&matrix, c);
	create_direction_matrix(&matrix, c);
	return (matrix);
}

void	render_camera(t_data *d, t_mlx_data *mlx)
{
	t_color		color;
	int			x;
	int			y;
	t_vector	normal;
	t_4Matrix	camera;

	camera = pos_camera(d);
	x = ((d->width / 2) * -1);
	y = (d->height / 2);
	while (--y >= (d->height / 2) * -1)
	{
		while (++x <= (d->width / 2))
		{
			normal = mult_mtrx_vector(&camera, canvas_to_viewport(x, y)); //revisar que hace
			color = trace_ray(normal, d->render_MIN, d->render_MAX);
			my_mlx_pixel_put(mlx, x, y, color);
		}
		x = ((d->width / 2) * -1);
	}
	mlx_put_image_to_window(mlx->vars.mlx, mlx->vars.win, mlx->img, 0, 0);
}
