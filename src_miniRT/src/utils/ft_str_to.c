/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:10 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/07 18:40:13 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdio.h>

double	ft_strtod(char *str)
{
	double	n;
	size_t	i;
	size_t	j;	
	double	result;

	n = (double)ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.' && str[i] != ',')
		i++;
	if (str[i] == '.')
		i++;
	if (str[i] == ',')
		return (n);
	j = i;
	while (str[j] && ft_isdigit(str[j]))
		j++;
	result = (double)ft_atoi(&str[i]);
	result = result / pow(10, j - i);
	if (n < 0)
		result = n - result;
	else
		result = n + result;
	return (result);
}

int	ft_strtouc(char *str)
{
	size_t	n;

	n = ft_atoi(str);
	if (n > 255 || str[0] == ',' || str[0] == '\0')
		return (-1);
	return ((int)n);
}
