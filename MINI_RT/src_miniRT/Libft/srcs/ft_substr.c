/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:28:40 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:51:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	malloc_len;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start >= len)
		malloc_len = len + 1;
	else
		malloc_len = s_len - start + 1;
	substr = malloc (sizeof(char) * (malloc_len));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
}
