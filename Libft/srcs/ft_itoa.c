/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:53:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:45:28 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	calc_size(long int n, size_t *size)
{
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		*size += 1;
		n /= 10;
	}
	*size += 1;
}

static void	create_str(char *str, long int n, size_t size)
{
	size_t	i;
	size_t	j;
	int		c;

	i = 0;
	j = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
		j++;
	}
	while (size > j)
	{
		c = (n % 10);
		str[size - 1] = c + '0';
		n = n / 10;
		i++;
		size--;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = 0;
	if (n < 0)
		size = 1;
	calc_size(n, &size);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	create_str(str, n, size);
	return (str);
}
