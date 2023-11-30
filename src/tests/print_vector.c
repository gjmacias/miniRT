/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:08:15 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/21 13:20:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"
#include <stdio.h>

void	print_vector(t_vector vector)
{
	printf("[ X %.2f ][ Y %.2f ][ Z %.2f ]\n", vector.x, vector.y, vector.z);
}

void	print_color(t_color color)
{
	printf("[ R %d ][ G %d ][ B %d ][ A %d ]\n", color.r, color.g, color.b, color.a);
}
