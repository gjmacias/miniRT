/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:42 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 13:20:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/*
void	init_matrix(t_4Matrix *matrix)
{
	int	i;
	int	j;

	i = -1;
	while (++i != 4)
	{
		j = -1;
		while (++j != 4)
		{
			if (i == j)
				matrix->m[i][j] = 1.0f;
			else
				matrix->m[i][j] = 0.0f;
		}
	}
}

void	create_pos_matrix(t_4Matrix *matrix, t_camera *c)
{
	matrix->m[0][3] = c->center->x;
	matrix->m[1][3] = c->center->y;
	matrix->m[2][3] = c->center->z;
}

void	create_direction_matrix(t_4Matrix *matrix, t_camera *c)
{
	t_vector	right;
	t_vector	up;
	t_vector	forward;
	t_vector	tmp;

	tmp = tmp_vector(0, 1, 0);
	forward = *c->n_vector;
	right = cross_product(&tmp, &forward);
	up = cross_product(&forward, &right);
	matrix->m[0][0] = right.x;
	matrix->m[1][0] = right.y;
	matrix->m[2][0] = right.z;
	matrix->m[0][1] = up.x;
	matrix->m[1][1] = up.y;
	matrix->m[2][1] = up.z;
	matrix->m[0][2] = forward.x;
	matrix->m[1][2] = forward.y;
	matrix->m[2][2] = forward.z;
}

t_vector 	matrix_FOV(t_4Matrix *m, t_data *d, t_vector *v)
{
	t_vector	res;

	v->x = (float)(d->width / 2) - v->x;
	v->y = (float)(d->height / 2) - v->y;
	res.x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z;
	res.y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z;
	res.z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z;
	return (res);
}
*/
// t_quaternion rotate_quaternion(double angle_degrees, int c)
// {
// 	double angle_radians = angle_degrees * (M_PI / 180.0);
// 	double half_angle = 0.5 * angle_radians;

// 	if (c == 'x')
// 		return (t_quaternion){sin(half_angle), 0, 0, cos(half_angle)};
// 	if (c == 'y')
// 		return (t_quaternion){0, sin(half_angle), 0, cos(half_angle)};
// 	if (c == 'z')
// 		return (t_quaternion){0, 0, sin(half_angle), cos(half_angle)};
// 	return (t_quaternion){1, 0, 0, 0};
// }

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
	t_quaternion vector_quaternion = {v.x, v.y, v.z, 0};
	// t_quaternion conjugate = {-q.x, -q.y, -q.z, q.w};
	t_quaternion conjugate = {q.x, q.y, q.z, -q.w};
	// t_quaternion rotated = multiply_quaternions(q, multiply_quaternions(vector_quaternion, conjugate));
	t_quaternion rotated = multiply_quaternions(conjugate, multiply_quaternions(vector_quaternion, q));

	return (t_vector){rotated.x, rotated.y, rotated.z};
}

t_quaternion euler_to_q(double roll, double pitch, double yaw)
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
	rads = ang * (M_PI / 180);
	printaux();
	print_vector(*c->center);
	c->center->x += steps * sin(rads);
	printd((rads) * (180 / M_PI));
	printd(sin(rads));
	c->center->z += steps * cos(rads);
	printd(cos(rads));
}