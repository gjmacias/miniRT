/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:56:02 by ffornes-          #+#    #+#             */
/*   Updated: 2023/11/02 11:56:05 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long long	check_limits(unsigned long long j, int i)
{
	long long			out;

	if (i)
		j -= 1;
	if (j > LONG_MAX)
		return (0);
	out = (long long)j;
	if (i)
	{
		if (out == 0)
		{
			out += 1;
			out *= -1;
		}
		else
		{
			out *= -1;
			out += 1;
		}
	}
	return (out);
}

long long	ft_atoll(const char *str)
{
	int					i;
	unsigned long long	j;

	i = 0;
	j = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i++;
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		j = (j * 10) + (*str - '0');
		str++;
	}
	return (check_limits(j, i));
}
