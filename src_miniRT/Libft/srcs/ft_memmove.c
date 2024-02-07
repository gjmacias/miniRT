/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:43:34 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:51:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str1;
	const char	*str2;

	str1 = (char *)dst;
	str2 = (const char *)src;
	if (str2 < str1)
	{
		while (len--)
			str1[len] = str2[len];
		return (dst);
	}
	return (ft_memcpy(str1, str2, len));
}
