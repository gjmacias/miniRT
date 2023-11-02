/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:53:35 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:53:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	count;

	if (!s || !f)
		return ;
	size = ft_strlen(s);
	count = 0;
	while (count < size)
	{
		(*f)(count, (char *)(s + count));
		count++;
	}
}
