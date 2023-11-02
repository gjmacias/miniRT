/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:38 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:55:47 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i) && i < len)
	{
		while (*(haystack + i + j) == *(needle + j) && (i + j) < len)
		{
			if (!*(needle + j + 1) || (i + j) == len)
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
