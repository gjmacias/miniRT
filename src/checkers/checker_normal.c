/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:31:03 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/17 17:35:04 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"

int	checker_normal(t_vector *vector)
{
	double	n;
	n = vector->x + vector->y + vector->z;
	if (vector->x > 1 || vector->x < -1 || vector->y > 1 || vector->y < -1 
		|| vector->z > 1 || vector->z < -1)
		return (1);
	else if ( n > 1.00 || n < -1.00 )
		return (1);
	return (0);
}
