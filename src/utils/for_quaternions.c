/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:42 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/05 19:05:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_quaternion	multiply_quaternions(t_quaternion a, t_quaternion b)
{
	t_quaternion	result;

	result.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	result.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	result.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	result.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	return (result);
}

t_vector	rotate_vector_by_quaternion(t_vector v, t_quaternion q)
{
	t_quaternion	vq;
	t_quaternion	conjugate;
	t_quaternion	rotated;
	t_vector		out;

	vq = (t_quaternion){v.x, v.y, v.z, 0};
	conjugate = (t_quaternion){-q.x, -q.y, -q.z, q.w};
	rotated = multiply_quaternions(q, multiply_quaternions(vq, conjugate));
	out = (t_vector){rotated.x, rotated.y, rotated.z};
	return (out);
}

t_quaternion	euler_to_q(double roll, double pitch, double yaw)
{
	t_quaternion	q;
	double			y[2];
	double			p[2];
	double			r[2];

	r[0] = cos(roll / 2.0);
	r[1] = sin(roll / 2.0);
	p[0] = cos(pitch / 2.0);
	p[1] = sin(pitch / 2.0);
	y[0] = cos(yaw / 2.0);
	y[1] = sin(yaw / 2.0);
	q.w = r[0] * y[0] * p[0] + r[1] * y[1] * p[1];
	q.x = r[0] * y[0] * p[1] - r[1] * y[1] * p[0];
	q.y = r[0] * y[1] * p[0] + r[1] * y[0] * p[1];
	q.z = r[1] * y[0] * p[0] - r[0] * y[1] * p[1];
	return (q);
}

void	move_euler(t_camera *c, double ang)
{
	double	steps;
	double	rads;

	steps = 5;
	rads = (ang * (M_PI / 180) + c->euler->z);
	print_vector(*c->center);
	c->center->x += steps * sin(rads);
	c->center->z += steps * cos(rads);
}
