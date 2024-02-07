/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:04:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:49:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1_size;

	s1_size = ft_strlen((char *)s1) + 1;
	ptr = malloc (sizeof(char) * s1_size);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s1_size);
	return (ptr);
}
