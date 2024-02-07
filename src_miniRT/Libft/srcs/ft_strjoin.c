/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:34:20 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:49:59 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;

	size1 = 0;
	size2 = 0;
	if (s1)
		size1 = ft_strlen((char *)s1);
	if (s2)
		size2 = ft_strlen((char *)s2);
	str = malloc (sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(str, s1, size1 + 1);
		ft_strlcat((char *)(str + size1), s2, size2 + 1);
	}
	else if (s2)
		ft_strlcpy(str, s2, size2 + 1);
	return (str);
}
