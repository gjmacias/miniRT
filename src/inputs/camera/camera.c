#include "miniRT.h"

void	render_camera(t_data *d)
{
	t_Color		color;
	int			x;
	int			y;
	t_Vector	d;
	t_pos_camera	camera;

	camera = pos_camera(d);
	x = (d->width / 2) * -1);
	y = (d->height / 2);
	while (--y >= (d->height / 2) * -1)
	{
		while (++x <= (d->width / 2))
		{
			d = mult_mtrx_vector(&camera, canvas_to_viewport(x, y));
			color = trace_ray(d, T_MIN, T_MAX); // crear  funcion
			put_pixel(x, y, color); // revisar axis, my_mlx, my plx pixe put
		}
		x = ((d->width / 2) * -1);
	}
	mlx_put_image_to_window(mlibx()->mlx, mlibx()->win, mlibx()->img, 0, 0);
}
