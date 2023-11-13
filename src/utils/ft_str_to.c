/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:02:10 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_strtod(char *str)
{
	long int	n;
	size_t		i;
	double		result;

	n = ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	result = (double)ft_atoi(&str[i]);
	result = result / pow(10, ft_strlen(&str[i]));
	result = n + result;
	return (result);
}

int	ft_strtouc(char *str)
{
	size_t	n;

	n = ft_atoi(str);
	if (n > 255 || n < 0 || str[0] == ',' || str[0] == '\0')
		return (-1);
	return ((int)n);
}
