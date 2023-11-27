#include "miniRT.h"

t_3Matrix	pos_camera(t_data *d)
{
	t_vector	cross;
	t_vector	init;
	float		angle;
	t_3Matrix	matrix;

	init.x = 1;
	init.y = 0;
	init.z = 0;
	angle = angle_vectors(init, d->camera.n_vector);
	cross = cross_product(init, d->camera.n_vector);
	init = cross;
	matrix = create_matrix(init, angle);
	return (matrix);
}

void	render_camera(t_data *d)
{
	t_color		color;
	int			x;
	int			y;
	t_vector	normal;
	t_3Matrix	camera;

	camera = pos_camera(d);
	x = ((d->width / 2) * -1);
	y = (d->height / 2);
	while (--y >= (d->height / 2) * -1)
	{
		while (++x <= (d->width / 2))
		{
			normal = mult_mtrx_vector(&camera, canvas_to_viewport(x, y));
			color = trace_ray(normal, d->render_MIN, d->render_MAX); // crear  funcion
			put_pixel(x, y, color); // revisar axis, my_mlx, my plx pixe put
		}
		x = ((d->width / 2) * -1);
	}
	mlx_put_image_to_window(d->, mlibx()->win, mlibx()->img, 0, 0);
}
