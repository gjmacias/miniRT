/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:21:00 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:53:56 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen((char *)dst);
	if (j <= dstsize)
	{
		while (*(src + i) != '\0' && (j + 1) < dstsize)
		{
			*(dst + j) = *(src + i);
			j++;
			i++;
		}
		*(dst + j) = '\0';
	}
	else
		return (ft_strlen((char *)src) + dstsize);
	return (ft_strlen(dst) + ft_strlen((char *)(src + i)));
}
