/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:40 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 17:01:39 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "libft.h"
#include <limits.h>

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

void	init_quaternion(t_vector *v, t_quaternion *q)
{
	double	yaw;
	double	pitch;


	yaw = (acos(v->z) * (180.0 / M_PI));
	if (v->x >= 0)
		yaw = -yaw;
	if (v->x == 0 && v->z == 0)
		yaw = 0;
	pitch = (asin(v->y) * (180.0 / M_PI));
	q->x = 1;
	q->y = 0;
	q->z = 0;
	q->w = 0;
	*q = multiply_quaternions(*q, rotate_quaternion(yaw, 'y'));
	*q = multiply_quaternions(*q, rotate_quaternion(-pitch / 2, 'x'));
	*q = multiply_quaternions(*q, rotate_quaternion(-pitch / 2, 'x'));
}