/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:00 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/07 17:58:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"
#include "vectors.h"

void	input_brightness(char *s, t_data *p, double *bright)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		ft_putstr_fd("Error in line: < ", 2);
		ft_putstr_fd(line_num, 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Double brightness\n", 2);
		else
			ft_putstr_fd(" > Need parameter: brightness\n", 2);
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
		ft_putstr_fd("Error in line: < ", 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Vector position\n", 2);
		else
			ft_putstr_fd(" > Need parameter: position\n", 2);
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
		ft_putstr_fd("Error in line: < ", 2);
		ft_putstr_fd(line_num, 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Normal\n", 2);
		else
			ft_putstr_fd(" > Need parameter: Normal\n", 2);
		exit(EXIT_FAILURE);
	}
	arraytodouble(s, vector);
	if (v_magnitude(vector) != 1)
		normalize_v(vector);
	free(line_num);
}

void	input_diameter(char *s, t_data *p, double *diameter)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		ft_putstr_fd("Error in line: < ", 2);
		ft_putstr_fd(line_num, 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Double diameter\n", 2);
		else
			ft_putstr_fd(" > Need parameter: diameter\n", 2);
		exit(EXIT_FAILURE);
	}
	(*diameter) = ft_strtod(s);
	free(line_num);
}
