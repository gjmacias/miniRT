/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:22:26 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 19:23:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "miniRT_defs.h"

t_vector	new_vector(double x, double y, double z);
t_vector	tmp_vector(double x, double y, double z);
t_vector	v_addition(t_vector *v1, t_vector *v2);
t_vector	v_subtract(t_vector *v1, t_vector *v2);
t_vector	v_product(t_vector *v1, double n);
double		v_magnitude(t_vector *vector);
void		normalize_v(t_vector *vector);
double		dot(t_vector *v1, t_vector *v2);
float		angle_vectors(t_vector *a, t_vector *b);
t_vector	cross_product(t_vector *a, t_vector *b);

#endif
