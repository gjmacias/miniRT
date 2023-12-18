/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:42:31 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/18 13:42:31 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_defs.h"
#include <stdio.h>

void	print_matrix(t_4Matrix *m)
{
	int	i;
	int	j;

	i = -1;
	printf("MATRIX:\n");
	while (++i != 4)
	{
		j = -1;
		while (++j != 4)
		{
			printf("[ %.4f ]\t", m->m[i][j]);
		}
		printf("\n");
	}
}
