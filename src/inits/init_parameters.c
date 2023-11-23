/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:40 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:00:40 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"

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