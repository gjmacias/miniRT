#include "miniRT.h"

t_3Matrix	pos_camera(t_data *d)
{
	t_Vector		cross;
	float			angle;
	t_3Matrix	matrix;

	angle = angle_btwn_vectors(camera()->initial_dir, camera()->dir);
	cross = cross_product(camera()->initial_dir, camera()->dir);
	matrix = create_rot_matrix(cross, angle);
	return (matrix);
}

void	render_camera(t_data *d)
{
	t_Color		color;
	int			x;
	int			y;
	t_Vector	normal;
	t_3Matrix	camera;

	camera = pos_camera(d);
	x = ((d->width / 2) * -1);
	y = (d->height / 2);
	while (--y >= (d->height / 2) * -1)
	{
		while (++x <= (d->width / 2))
		{
			normal = mult_mtrx_vector(&camera, canvas_to_viewport(x, y));
			color = trace_ray(normal, T_MIN, T_MAX); // crear  funcion
			put_pixel(x, y, color); // revisar axis, my_mlx, my plx pixe put
		}
		x = ((d->width / 2) * -1);
	}
	mlx_put_image_to_window(d->, mlibx()->win, mlibx()->img, 0, 0);
}
