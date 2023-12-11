#include "miniRT.h"
#include "mlx.h"

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
	int			x;
	int			y;
	t_vector	normal;
	t_color		color;
	t_4Matrix	camera;

	camera = pos_camera(&(d->camera));
	y = -1;
	while (++y < d->height)
	{
		x = -1;
		while (++x < d->width)
		{
			normal = matrix_vector(&camera, d, (t_vector){(float)x, (float)y, 1.0});
			color = trace_ray(normal, d->render_MIN, d->render_MAX);
			my_mlx_pixel_put(mlx, x, y, color);
		}
	}
	mlx_put_image_to_window(mlx->vars.mlx, mlx->vars.win, mlx->img, 0, 0);
}
