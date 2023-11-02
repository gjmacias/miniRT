/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:32:04 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/08 15:27:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str1;
	const char	*str2;

	if (!dst && !src)
		return (NULL);
	str1 = (char *)dst;
	str2 = (const char *)src;
	while (n--)
		*str1++ = *str2++;
	return (dst);
}
