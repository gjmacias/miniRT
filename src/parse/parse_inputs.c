/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:00 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/17 17:54:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_brightness(char *s, t_data *p, double *bright)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Double brightness\n", 37);
		else
			write(2, " > Need parameter: brightness\n", 31);
		exit(EXIT_FAILURE);
	}
	(*bright) = ft_strtod(s);
	free(line_num);
}

void	input_position(char *s, t_data *p, t_vector *center)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_array_double(s))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Vector position\n", 36);
		else
			write(2, " > Need parameter: position\n", 30);
		exit(EXIT_FAILURE);
	}
	arraytodouble(s, center);
	free(line_num);
}

void	input_vector(char *s, t_data *p, t_vector *vector)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_array_double(s))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Vector\n", 26);
		else
			write(2, " > Need parameter: Vector\n", 27);
		exit(EXIT_FAILURE);
	}
	arraytodouble(s, vector);
	if (checker_normal(vector))
	{
		write(2, " > Wrong values: Normal\n", 24);
		exit(EXIT_FAILURE);	
	}
	free(line_num);
}

void	input_diameter(char *s, t_data *p, double *diameter)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		write(2, "Error in line: < ", 18);
		write(2, line_num, ft_strlen(line_num));
		if (s)
			write(2, " > Bad parameter: Double diameter\n", 35);
		else
			write(2, " > Need parameter: diameter\n", 29);
		exit(EXIT_FAILURE);
	}
	(*diameter) = ft_strtod(s);
	free(line_num);
}
