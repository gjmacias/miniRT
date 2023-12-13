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
	int			pos[2];
	t_vector	normal;
	t_vector	v_fov;
	t_color		color;
	t_4Matrix	camera;

	camera = pos_camera(&(d->camera));
// DEBUG Prints
	printf("FOV: %.2f\n", d->camera.fov);
	print_matrix(&camera);
// ENDDEBUG
	pos[Y] = -1;
	while (++pos[Y] < d->height)
	{
		pos[X] = -1;
		while (++pos[X] < d->width)
		{
			v_fov = v_FOV(pos[X], pos[Y], d);
			normal = matrix_FOV(&camera, d, &v_fov);
			normalize_v(&normal);
			color = trace_ray(&normal, d);
			my_mlx_pixel_put(mlx, pos[X], pos[Y], color);
		}
		mlx_put_image_to_window(mlx->vars.mlx, mlx->vars.win, mlx->img, 0, 0);
	}
}
