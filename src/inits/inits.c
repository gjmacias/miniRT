/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:40 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/07 16:59:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT.h"
#include "miniRT_defs.h"
#include "matrix.h"
#include "libft.h"
#include <limits.h>

void	init_mlx(t_mlx_data *d, t_data *p)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, p->width, p->height, "miniRT");
	d->img = mlx_new_image(d->vars.mlx, p->width, p->height);
	d->addr = mlx_get_data_addr(d->img, &d->bpps, &d->l_len, &d->endian);
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img, 0, 0);
}

void	init_parameters_info(t_data *p)
{
	p->line = 0;
	p->info.ambient_light = 0;
	p->info.camera = 0;
	p->info.cylinders = 0;
	p->info.lights = 0;
	p->info.planes = 0;
	p->info.spheres = 0;
	p->lights = NULL;
	p->planes = NULL;
	p->spheres = NULL;
	p->cylinders = NULL;
	p->camera = ft_calloc(1, sizeof(t_camera));
	if (!p->camera)
		clean_exit(p, 12);
}

void	init_canvas(t_data *p, char *str_width, char *str_height)
{
	int	width;
	int	height;

	width = ft_atoi(str_width);
	height = ft_atoi(str_height);
	if (width <= 0 || width > 3840)
		p->width = 1920;
	else
		p->width = width;
	if (height <= 0 || height > 3840)
		p->height = 1080;
	else
		p->height = height;
}

void	init_euler(t_vector *n_vector)
{
	t_vector	euler;

	euler.x = 0;
	euler.y = asin(n_vector->y);
	if (fabs(n_vector->y) < 0.9999)
		euler.z = atan2(n_vector->x, n_vector->z);
	else
		euler.z = 0;
	*n_vector = euler;
}

void	init_quaternion(t_vector *e, t_quaternion *q)
{
	q->x = 0;
	q->y = 0;
	q->z = 0;
	q->w = 1;
	*q = multiply_quaternions(*q, euler_to_q(e->x, e->y, e->z));
}
