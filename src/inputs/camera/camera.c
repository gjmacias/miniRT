/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:11 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/18 13:42:11 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include <limits.h>
#include <sys/wait.h>

t_4Matrix	pos_camera(t_camera *c)
{
	t_4Matrix	matrix;

	init_matrix(&matrix);
	create_pos_matrix(&matrix, c);
	create_direction_matrix(&matrix, c);
	return (matrix);
}

void	render_camera(t_data *d, t_mlx_data *mlx, int start, int end)
{
	int			x;
	int			y;
	t_vector	normal;
	t_color		color;
	t_4Matrix	camera;

	camera = pos_camera(&(d->camera));
	printf("FOV: %.2f\n", d->camera.fov);
	print_matrix(&camera);
	y = start - 1;
	while (++y < end)
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

/*void	process_camera(t_data *d, t_mlx_data *mlx, int num)
{
    pid_t	pid;
	int		i, start, end;

	i = -1;
	while (++i < num)
	{
        pid = fork();
        if (pid == 0)
        {
            start = i * (d->height / num);
            end = (i + 1) * (d->height / num);
			if (end >= d->height)
				end = d->height;
            render_camera(d, mlx, start, end);
            break;
        }
        else if (pid < 0)
        {
            fprintf(stderr, "Error al crear el proceso hijo\n");
            exit(1);
        }
    }
    i = -1;
	while (++i < num)
        wait(NULL);
}*/
