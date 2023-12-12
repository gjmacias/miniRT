/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:30 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:00:30 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT_defs.h"
#include "miniRT.h"
#include <stdlib.h>

int	ft_frame(t_hook *hook)
{
	mlx_clear_window(hook->data->vars.mlx, hook->data->vars.win);
	render_camera(hook->parameters, hook->data);
	return (0);
}


int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	key_hook_test(int keycode, t_hook *hook)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(hook->data->vars.mlx, hook->data->vars.win);
		exit(0);
	}
	else if (keycode == A)
	{
		hook->parameters->camera.center.x = hook->parameters->camera.center.x - 5;
		ft_frame(hook);
	}
	else if (keycode == D)
	{
		hook->parameters->camera.center.x = hook->parameters->camera.center.x + 5;
		ft_frame(hook);
	}
	else if (keycode == S)
	{
		hook->parameters->camera.center.z = hook->parameters->camera.center.z - 5;
		ft_frame(hook);
	}
	else if (keycode == W)
	{
		hook->parameters->camera.center.z = hook->parameters->camera.center.z + 5;
		ft_frame(hook);
	}
	else if (keycode == PLUS_K && hook->parameters->camera.fov + 5.0 <= 180.0)
	{
		hook->parameters->camera.fov = hook->parameters->camera.fov + 5.0;
		ft_frame(hook);
	}
	else if (keycode == MINUS_K && hook->parameters->camera.fov - 5.0 >= 0.0)
	{
		hook->parameters->camera.fov = hook->parameters->camera.fov - 5.0;
		ft_frame(hook);
	}
	return (0);
}