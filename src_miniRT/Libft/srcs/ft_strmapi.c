/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:54:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:50:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	count;
	char	*str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char *)s);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (count < size)
	{
		str[count] = (*f)((unsigned int)count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
