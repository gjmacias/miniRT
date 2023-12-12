#include "miniRT.h"
#include "mlx.h"
#include <limits.h>

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
	printf("FOV: %.2f\n", d->camera.fov);
	print_matrix(&camera);
	y = -1;
	while (++y < d->height)
	{
		x = -1;
		while (++x < d->width)
		{
			normal = matrix_FOV(&camera, d, v_FOV(x, y, d));
			normal = normalize_v(normal);
			color = trace_ray(normal, d);
			my_mlx_pixel_put(mlx, x, y, color);
		}
		mlx_put_image_to_window(mlx->vars.mlx, mlx->vars.win, mlx->img, 0, 0);
	}
}
