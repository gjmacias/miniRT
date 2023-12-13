/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:05:00 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/13 16:22:18 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT_defs.h"

t_vector	*new_vector(double x, double y, double z)
{
	t_vector	*out;

	out = ft_calloc(sizeof(t_vector), 1);
	if (!out)
		return (NULL);
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vector	tmp_vector(double x, double y, double z)
{
	t_vector	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}
