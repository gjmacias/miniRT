/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:08:15 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/21 17:08:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"
#include <stdio.h>
#include <math.h>

void	print_vector(t_vector vector)
{
	printf("[ X %f ][ Y %f ][ Z %f ]\n", vector.x, vector.y, vector.z);
}

void	print_ang(t_vector vector)
{
	printf("ANGLE:[ X %f ][ Y %f ][ Z %f ]\n", vector.x * (180 / M_PI), vector.y * (180 / M_PI), vector.z * (180 / M_PI));
}

void	print_color(t_color color)
{
	printf("[ R %d ][ G %d ][ B %d ][ A %d ]\n", color.r, color.g, color.b, color.a);
}

void	print_quaternion(t_quaternion quaternion)
{
	printf("[ X %f ][ Y %f ][ Z %f ][ W %f ]\n", quaternion.x, quaternion.y, quaternion.z, quaternion.w);
}