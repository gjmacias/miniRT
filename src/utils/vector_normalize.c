/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:52:45 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/21 16:16:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

t_vector	*normalize_v(t_vector *vector)
{
	t_vector	*output;
	double		len;

	output = ft_calloc(sizeof(t_vector), 1);
	if (!output)
		return (NULL);
	len = vector_length(vector);
	output->x = vector->x / len;
	output->y = vector->y / len;
	output->z = vector->z / len;
	return (output);
}
