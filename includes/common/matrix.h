/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:18:09 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:20:55 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "miniRT_defs.h"

void			create_pos_matrix(t_4Matrix *matrix, t_camera *c);
void			create_direction_matrix(t_4Matrix *matrix, t_camera *c);
void			create_FOV_matrix(t_4Matrix *matrix, double fov);
t_vector		matrix_FOV(t_4Matrix *m, t_data *d, t_vector *v);
t_vector		rotate_vector_by_quaternion(t_vector v, t_quaternion q);
t_quaternion	rotate_quaternion(double angle_degrees, int c);
t_quaternion	multiply_quaternions(t_quaternion a, t_quaternion b);
t_quaternion	euler_to_q(double yaw, double pitch, double roll);
void			move_euler(t_camera *c, double ang);

#endif
