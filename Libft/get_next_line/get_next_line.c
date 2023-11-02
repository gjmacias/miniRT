/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:19:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/15 15:51:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_to_buff(int fd, char *buffer, char *line)
{
	int		i;
	char	*aux;

	i = BUFFER_SIZE;
	while (i > 0)
	{
		i = (int)read(fd, buffer, BUFFER_SIZE);
		if (i > 0)
		{
			aux = line;
			buffer[i] = '\0';
			line = ft_strjoin(line, buffer);
			free(aux);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	free(buffer);
	return (line);
}

static char	*get_line(char *str)
{
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_memcpy(line, str, i + 1);
	if (str[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

static char	*save_remains(char *str)
{
	char	*aux;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		i++;
	aux = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!aux)
		return (NULL);
	while (str[i + j])
	{
		aux[j] = str[i + j];
		j++;
	}
	aux[j] = '\0';
	free(str);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*aux;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	aux = read_to_buff(fd, buffer, aux);
	line = get_line(aux);
	aux = save_remains(aux);
	if (!line || !*line)
	{
		if (line)
			free(line);
		free(aux);
		return (NULL);
	}
	return (line);
}
