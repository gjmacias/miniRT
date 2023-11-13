/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:20 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:01:20 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	fill_expected_line(char *line, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		while (!(is_space(line[i])) && line[i] != '\0')
		{
			s[j] = line[i];
			i++;
			j++;
		}
		if (line[i] != '\0' && is_space(line[i]))
			s[j++] = ' ';
	}
}

char	*correct_spaces(char *line)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line && line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		while (!(is_space(line[i])) && line[i] != '\0')
		{
			i++;
			len++;
		}
		if (line[i] != '\0' && is_space(line[i]))
		{
			len++;
			i++;
		}
	}
	s = ft_calloc(sizeof(char), len + 1);
	fill_expected_line(line, s);
	return (s);
}

void	search_from(char *line, t_data *p)
{
	char	**arguments;
	char	*expected_line;

	expected_line = correct_spaces(line);
	if (!expected_line || expected_line[0] == '\0')
	{
		free(expected_line);
		return ;
	}
	arguments = ft_split(expected_line, ' ');
	parse_type(arguments, p);
	free(expected_line);
	free_double((void **)arguments);
}

void	parse_txt(t_data *p)
{
	char	*line;
	int		fd;

	init_parameters_info(p);
	fd = open(p->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error: Map not read\n", 21);
		exit (EXIT_FAILURE);
	}
	while (line)
	{
		p->line += 1;
		search_from(line, p);
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
	print_data(p);
	exit (EXIT_SUCCESS);
}
