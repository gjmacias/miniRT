/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:00 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:02:00 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include <stdio.h>

void	arraytouchar(char *s, t_color *color)
{
	int	x[6];

	x[0] = 0;
	x[5] = 1;
	x[4] = 0;
	x[1] = ft_strtouc(s);
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			x[5] += 1;
			x[x[5]] = ft_strtouc(&s[x[0] + 1]);
		}
		x[0] += 1;
	}
	color->r = x[1];
	color->g = x[2];
	color->b = x[3];
	color->a = x[4];
}

void	arraytodouble(char *s, t_vector *vector)
{
	int		x[2];
	double	y[3];

	x[0] = 0;
	x[1] = 0;
	y[0] = ft_strtod(s);
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			x[1] += 1;
			y[x[1]] = ft_strtod(&s[x[0] + 1]);
		}
		x[0] += 1;
	}
	vector->x = y[0];
	vector->y = y[1];
	vector->z = y[2];
}
