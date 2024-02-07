/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:00 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:00:00 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> 
#include "libft.h"

void	write_error(char *s1)
{
	ft_putstr_fd(s1, 2);
	exit(EXIT_FAILURE);
}

void	write_error3int(char *s1, int i, char *s3)
{
	char	*s2;

	s2 = ft_itoa(i);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	write_error3(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	exit(EXIT_FAILURE);
}
