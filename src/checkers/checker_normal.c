/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:31:03 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/21 12:14:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"
#include <math.h>

int	checker_normal(t_vector *vector)
{
	double	n;

	n = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	if (n != 1)
		return (1);
	return (0);
}
