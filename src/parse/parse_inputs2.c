/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:01:10 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_fov(char *s, t_data *p, double *fov)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Double FOV\n", 30);
		else
			write(2, " > Need parameter: FOV\n", 24);
		exit(EXIT_FAILURE);
	}
	(*fov) = ft_strtod(s);
	free(line_num);
}

void	input_height(char *s, t_data *p, double *height)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Double height\n", 33);
		else
			write(2, " > Need parameter: height\n", 27);
		exit(EXIT_FAILURE);
	}
	(*height) = ft_strtod(s);
	free(line_num);
}

void	input_color(char *s, t_data *p, t_color *color)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_uchar(s))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Vector color\n", 32);
		else
			write(2, " > Need parameter: color\n", 26);
		exit(EXIT_FAILURE);
	}
	arraytouchar(s, color);
	free(line_num);
}
