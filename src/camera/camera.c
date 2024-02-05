/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:11 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/05 19:23:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "matrix.h"
#include "vectors.h"
#include "mlx.h"
#include <limits.h>
#include <sys/wait.h>

t_vector	calculate_ray_direction(int x, int y, t_data *d)
{
	t_vector	result;
	double		work_fov;
	double		aspect_ratio;

	work_fov = 180.0 - d->camera->fov;
	aspect_ratio = (double)d->width / (double)d->height;
	result.x = (((2.0 * x) / d->width) - 1.0) * aspect_ratio;
	result.y = (1.0 - ((2.0 * y) / d->height));
	result.z = tan((work_fov / 2) * (M_PI / 180));
	normalize_v(&result);
	result = rotate_vector_by_quaternion(result, *(d->camera->q));
	normalize_v(&result);
	return (result);
}

void	render_camera(t_data *d, t_mlx_data *mlx, int start, int end)
{
	int			pos[2];
	t_vector	v_fov;
	t_color		color;

	init_quaternion(d->camera->euler, d->camera->q);
	pos[Y] = start - 1;
	while (++pos[Y] < end)
	{
		pos[X] = -1;
		while (++pos[X] < d->width)
		{
			v_fov = calculate_ray_direction(pos[X], pos[Y], d);
			color = trace_ray(&v_fov, d);
			my_mlx_pixel_put(mlx, pos[X], pos[Y], color);
		}
	}
	mlx_put_image_to_window(mlx->vars.mlx, mlx->vars.win, mlx->img, 0, 0);
}
