/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:30 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 17:27:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT_defs.h"
#include "miniRT.h"
#include <stdlib.h>

int	ft_frame(t_hook *hook)
{
	mlx_clear_window(hook->data->vars.mlx, hook->data->vars.win);
	render_camera(hook->parameters, hook->data, 0, hook->parameters->height);
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

static void	move_hook(int keycode, t_hook *hook)
{
	if (keycode == A)
		hook->parameters->camera->center->x -= 5;
	else if (keycode == D)
		hook->parameters->camera->center->x += 5;
	else if (keycode == S)
		hook->parameters->camera->center->z -= 5;
	else if (keycode == W)
		hook->parameters->camera->center->z += 5;
	else if (keycode == SPACE_K)
		hook->parameters->camera->center->y += 5;
	else if (keycode == SHIFT_K)
		hook->parameters->camera->center->y -= 5;
	ft_frame(hook);
}

// static void	rot_hook(int keycode, t_hook *hook)
// {
// 	if (keycode == UP_K)
// 		*hook->parameters->camera->q = 
// 			multiply_quaternions(*hook->parameters->camera->q, rotate_quaternion(-5.0, 'x'));
// 	else if (keycode == DOWN_K)
// 		*hook->parameters->camera->q = 
// 			multiply_quaternions(*hook->parameters->camera->q, rotate_quaternion(5.0, 'x'));
// 	else if (keycode == LEFT_K)
// 		*hook->parameters->camera->q = 
// 			multiply_quaternions(*hook->parameters->camera->q, rotate_quaternion(5.0, 'y'));
// 	else if (keycode == RIGHT_K)
// 		*hook->parameters->camera->q = 
// 			multiply_quaternions(*hook->parameters->camera->q, rotate_quaternion(-5.0, 'y'));
// 	print_quaternion(*hook->parameters->camera->q);
// 	ft_frame(hook);
// }

static void	rot_hook(int keycode, t_hook *hook)
{
	if (keycode == UP_K)
		hook->parameters->camera->euler->y = (hook->parameters->camera->euler->y + (-5.0 * (M_PI / 180)));
	else if (keycode == DOWN_K)
		hook->parameters->camera->euler->y = (hook->parameters->camera->euler->y + (+5.0 * (M_PI / 180)));
	else if (keycode == LEFT_K)
		hook->parameters->camera->euler->x = (hook->parameters->camera->euler->x + (-5.0 * (M_PI / 180)));
	else if (keycode == RIGHT_K)
		hook->parameters->camera->euler->x = (hook->parameters->camera->euler->x + (+5.0 * (M_PI / 180)));
	if (hook->parameters->camera->euler->y >= M_PI || hook->parameters->camera->euler->y <= -M_PI)
		hook->parameters->camera->euler->y = 0;
	if (hook->parameters->camera->euler->x >= M_PI || hook->parameters->camera->euler->x <= -M_PI)
		hook->parameters->camera->euler->x = 0;
	print_quaternion(*hook->parameters->camera->q);
	ft_frame(hook);
}

int	key_hook_test(int keycode, t_hook *hook)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(hook->data->vars.mlx, hook->data->vars.win);
		exit(0);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D
		|| keycode == SPACE_K || keycode == SHIFT_K)
		move_hook(keycode, hook);
	else if (keycode == UP_K || keycode == DOWN_K || keycode == LEFT_K
		|| keycode == RIGHT_K)
		rot_hook(keycode, hook);
	else if (keycode == PLUS_K && hook->parameters->camera->fov + 5.0 <= 180.0)
	{
		hook->parameters->camera->fov = hook->parameters->camera->fov + 5.0;
		printd(hook->parameters->camera->fov);
		ft_frame(hook);
	}
	else if (keycode == MINUS_K && hook->parameters->camera->fov - 5.0 >= 0.0)
	{
		hook->parameters->camera->fov = hook->parameters->camera->fov - 5.0;
		printd(hook->parameters->camera->fov);
		ft_frame(hook);
	}
	return (0);
}
